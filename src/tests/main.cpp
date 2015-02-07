#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

#include <boost/process.hpp>

int main(int argc, char *argv[])
{
    using namespace boost::process;
    using namespace boost::process::initializers;

    enum Constraint { UNSPECIFIED = 0, ZERO, NON_ZERO };

    struct Params {
        std::vector<std::string> arguments;
        Constraint constraint;
    };

    try {
     
        Params params;
        
        // Set defaults
        params.constraint = Constraint::UNSPECIFIED;

        // Consume all options
        int i = 1;
        for (; i < argc; i ++) {
            if (argv[i][0] != '-') break;
            std::string option = argv[i];
            if (option == "-zero" || option == "--zero") {
                params.constraint = Constraint::ZERO;
            }
            else if (option == "-non-zero" || option == "--non-zero") {
                params.constraint = Constraint::NON_ZERO;
            }
        }

        // Testee path is the only mandatory parameter
        if (i >= argc) throw std::runtime_error("Missing testee path!");
        params.arguments.push_back(argv[i++]);
        std::cout << "Testee path: \"" << params.arguments.back() << "\"" << std::endl;

        // Remaining parameters are for testee
        for (; i < argc; i++) {
            std::cout << "Appending parameter \"" << argv[i] << "\"" << std::endl;
            params.arguments.push_back(argv[i]);
        }

        // Execute the testee, passing all parameters
        auto child = execute(throw_on_error(), set_args(params.arguments));
        auto exit_code = wait_for_exit(child);

        // Check the result
        if (params.constraint == ZERO) return (exit_code == 0) ? 0 : 1;
        else if (params.constraint == NON_ZERO) return (exit_code != 0) ? 0 : 1;
        else assert(false);
    }
    catch(const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return -1;
}
