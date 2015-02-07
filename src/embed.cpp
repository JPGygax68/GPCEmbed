#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using std::string;

// TODO: option for capitalization; possibly (many?) others

static string
fileToVariableName(string filename)
{
    using std::isalpha;
    using std::isalnum;

    auto i = filename.find_last_of("\\/");
    if (i != string::npos) filename = filename.substr(i);

    string name;
    auto ch = filename[0];
    name += isalpha(ch) ? ch : '_';
    for (auto ch: filename.substr(1)) name += std::isalnum(ch) ? ch : '_';

    return name;
}

int main(int argc, char *argv[])
{
	using namespace std;

	try {

        cout << "GPCEmbed" << endl;

        string data_file, wrapper_file, import_file;
        string const_name;

		// TODO: handle quotation marks
        // TODO: make parameters positional

        for (int i = 1; i < argc; i++) {

            string arg(argv[i]);

            // TODO: options (mainly: specifying const name explicitly)

            if (data_file.empty()) {
                data_file = arg;
            }
            else if (wrapper_file.empty()) {
                wrapper_file = arg;
            }
            else if (import_file.empty()) {
                import_file = arg;
            }

        }

        // Check required parameters
        // TODO: make wrapper and import file optional, derive names ?
        // TODO: support indicating directories and automatically appending filenames ?
        if (data_file.empty()) throw std::runtime_error("No data file specified!");
        if (wrapper_file.empty() && import_file.empty()) throw std::runtime_error("Neither wrapper nor import file specified!");

        // TODO: set default values of overridable derived parameters
        if (const_name.empty()) const_name = fileToVariableName(data_file);
        cout << "Constant object is called: " << const_name << endl;

		ifstream data_fs;
		ofstream import_fs, wrapper_fs;

		data_fs.open(data_file, ios::binary);
        wrapper_fs.open(wrapper_file, 0);

		// Convert

		size_t n = 0;
		while (true) {
			unsigned char byte = static_cast<unsigned int>(data_fs.get());
			if (data_fs.eof()) break;
			if (n > 0) {
				wrapper_fs << ", ";
				if (n % 16 == 0) wrapper_fs << endl;
			}
			wrapper_fs << "0x" << hex << setw(2) << setfill('0') << (unsigned int) byte;
			n++;
		}

		return 0;
	}
	catch (const exception &e) {
		cerr << "Error: " << e.what() << endl;
	}

	/*
	cout << endl;
	cout << "Press RETURN to terminate" << endl;
	cin.ignore();
	*/

	return -1;
}