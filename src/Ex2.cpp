#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int processCommanLine(const std::vector<std::string>& args,
                      std::string& input_file_name,
                      std::string& output_file_name, bool& help_flag,
                      bool& version_flag, bool& unknown_arg_flag,
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
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                input_file_name = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == args.size() - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
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
    return 0;
}

std::string transform_char(const char in_char)
{
    /*Take input character and transliterate

    Takes a char as input
    Removes alphanumeric characters
    Transforms a number to it's word form 
    (i.e. 1 -> ONE)
    Capitalises an alpha char
    returns string
    */

    std::string out_char{};
    if (std::isalnum(in_char)) {
        std::cout << (in_char) << "\n";
        switch (in_char) {
            case '0':
                out_char += "ZERO";
                break;

            case '1':
                out_char += "ONE";
                break;

            case '2':
                out_char += "TWO";
                break;

            case '3':
                out_char += "THREE";
                break;

            case '4':
                out_char += "FOUR";
                break;

            case '5':
                out_char += "FIVE";
                break;

            case '6':
                out_char += "SIX";
                break;

            case '7':
                out_char += "SEVEN";
                break;

            case '8':
                out_char += "EIGHT";
                break;

            case '9':
                out_char += "NINE";
                break;
            default:
                out_char += std::toupper(in_char);
                break;
        }
        return out_char;
    } else {
        return {};
    }
}

int main(int argc, char* argv[])
{
    //Initialise command line arguments
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    std::string inputFile{""};
    std::string outputFile{""};
    bool help_flag{0};
    bool version_flag{0};
    bool unknown_arg_flag{0};
    std::vector<std::string> unknown_arg_vect{};

    //process the command line arguments
    processCommanLine(cmdLineArgs, inputFile, outputFile, help_flag,
                      version_flag, unknown_arg_flag, unknown_arg_vect);

    //interpret any returned flags
    if (help_flag) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        return 0;
    }
    if (version_flag) {
        std::cout << "0.3.0" << std::endl;
        return 0;
    }
    if (unknown_arg_flag) {
        std::cerr << "[error] unknown argument(s) '"
                  << "'\n";
        for (const std::string& element : unknown_arg_vect) {
            std::cerr << element << "\n";
        }
        return 1;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {
        std::cerr << "[warning] input from file ('" << inputFile
                  << "') not implemented yet, using stdin\n";
    }

    // loop over each character from user input
    while (std::cin >> inputChar) {
        inputText += transform_char(inputChar);
    }

    // Print out the transliterated text
    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        std::cerr << "[warning] output to file ('" << outputFile
                  << "') not implemented yet, using stdout\n";
    }

    std::cout << inputText << std::endl;
    return 0;
}
