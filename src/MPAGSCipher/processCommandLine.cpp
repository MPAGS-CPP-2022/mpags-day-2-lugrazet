
#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& args,
                        std::string& input_file_name, bool& input_err_flag,
                        std::string& output_file_name, bool& output_err_flag,
                        bool& help_flag, bool& version_flag,
                        bool& unknown_arg_flag,
                        std::vector<std::string>& unknown_arg_vect)
{
    for (std::size_t i{1}; i < args.size(); ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            help_flag = true;
        } else if (args[i] == "--version") {
            version_flag = true;
        } else if (args[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
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
        } else if (args[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
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
        } else {
            unknown_arg_flag = true;
            unknown_arg_vect.push_back(args[i]);
        }
    }
    if (unknown_arg_flag || input_err_flag || output_err_flag) {
        return 1;
    }
    return 0;
}