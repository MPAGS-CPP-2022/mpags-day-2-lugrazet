
#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& args,
                        std::string& input_file_name, bool& input_err_flag,
                        std::string& output_file_name, bool& output_err_flag,
                        bool& help_flag, bool& version_flag,
                        bool& unknown_arg_flag,
                        std::vector<std::string>& unknown_arg_vect,
                        bool& encrypt_flag, bool& encrypt_err_flag,
                        bool& decrypt_flag, bool& decrypt_err_flag,
                        int& key)
{
    //Iterate and flag appropriate command line arguments
    for (std::size_t i{1}; i < args.size(); ++i) {
        //Help flag
        if (args[i] == "-h" || args[i] == "--help") {
            help_flag = true;
        } 
        //Version flag
        else if (args[i] == "--version") {
            version_flag = true;
        } 
        //Input file flag expecting 
        else if (args[i] == "-i") {
            // Next element is filename unless next argument is another flag or doesn't exist
            if (i == args.size() - 1) {
                input_err_flag = 1;
            } else if (args[i + 1][0] == '-') {
                input_err_flag = 1;
                i++;
            } else {
                // Got filename, so assign value and advance past it
                input_file_name = args[i + 1];
                ++i;
            }
        //Output file flag, expecting filename after
        } else if (args[i] == "-o") {
            // Next element is filename unless next argument is another flag or doesn't exist
            if (i == args.size() - 1) {
                output_err_flag = 1;
            }
            if (args[i + 1][0] == '-') {
                output_err_flag = 1;
                i++;
            } else {
                // Got filename, so assign value and advance past it
                output_file_name = args[i + 1];
                ++i;
            }
        } 
        //Encryption file flag, expecting Key after
        else if (args[i] == "--encrypt"){
            // Next element is Key unless next argument is another flag or doesn't exist
            if (i == args.size() - 1) {
                encrypt_err_flag = 1;
            }
            if (args[i + 1][0] == '-') {
                encrypt_err_flag = 1;
                i++;
            } else {
                // Got Key, so assign value and advance past it
                encrypt_flag = 1;
                key = std::stoi(args[i + 1]);
                ++i;
            }
        }
        //Decryption file flag, expecting Key after
        else if (args[i] == "--decrypt"){
            // Next element is Key unless next argument is another flag or doesn't exist
            if (i == args.size() - 1) {
                decrypt_err_flag = 1;
            }
            if (args[i + 1][0] == '-') {
                decrypt_err_flag = 1;
                i++;
            } else {
                // Got filename, so assign value and advance past it
                decrypt_flag = 1;
                key = std::stoi(args[i + 1]);
                ++i;
            }

        }
        //If a cmd line argument doesn't satisfy any of these, flag an error
        else {
            unknown_arg_flag = true;
            unknown_arg_vect.push_back(args[i]);
        }
    }
    if (unknown_arg_flag || input_err_flag || output_err_flag || encrypt_err_flag ||decrypt_err_flag ) {
        return 1;
        //return 1 so we can close check in main and close it before anything breaks.
    }
    return 0;
}