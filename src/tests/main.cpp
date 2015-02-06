#include <string>
#include <algorithm>
#include <iostream>

#include <boost/process.hpp>

int main(int argc, char *argv[])
{
    enum Constraint { UNSPECIFIED = 0, ZERO, NON_ZERO };

    struct Params {
        std::string testee_path;
        Constraint constraint;
    };

    try {
     
        Params params;

        if (argc < 2) throw std::runtime_error("Missing path to testee executable");
        params.testee_path = argv[1];
        std::cout << "Testee path: \"" << params.testee_path << "\"" << std::endl;

        if (argc < 3) throw std::runtime_error("Missing return value constraint");
        std::string constr_spec = argv[2];
        std::transform(constr_spec.begin(), constr_spec.end(), constr_spec.begin(), std::tolower);
        if (constr_spec == "zero") params.constraint = ZERO;
        else if (constr_spec == "non-zero") params.constraint == NON_ZERO;
        std::cout << "Constraint: " << constr_spec << std::endl;

        // TODO: pass the rest of the parameters to the testee

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return -1;
}
