#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "runCaesarCipher.hpp"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/*
std::string name {"myoutputfiletxt"};
std::ofstream out_file {name};
bool ok_to_write = out_file.good();
out_file << "Some text\n";
file.close();

std::string name {"myinputfile.txt"};
std::ifstream in_file {name};
bool ok_to_read = in_file.good();
in_file >> inputChar;
file.close();

std::ofstream out_file{ name, std::ios::app};
*/
int main(int argc, char* argv[])
{
    //Initialise command line arguments
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    std::string inputFile{""};
    bool input_err_flag{0};
    std::string outputFile{""};
    bool output_err_flag{0};
    bool help_flag{0};
    bool version_flag{0};
    bool unknown_arg_flag{0};
    std::vector<std::string> unknown_arg_vect{};
    bool& encrypt_flag{0};
    bool& encrypt_err_flag{0};
    bool& decrypt_flag{0}; 
    bool& decrypt_err_flag{0};
    int& key{0};

    //process the command line arguments
    processCommandLine(cmdLineArgs, inputFile, input_err_flag, outputFile,
                       output_err_flag, help_flag, version_flag,
                       unknown_arg_flag, unknown_arg_vect,
                       encrypt_flag, encrypt_err_flag, 
                       decrypt_flag, decrypt_err_flag,
                       key);

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
            << "  --encrypt INT    Encrypt text via a Caeser Shift of magnitude INT\n"
            << "                   No encryption if unspecified\n\n"
            << "  --decrypt INT    Decrypt text via a Caeser Shift of magnitude INT\n"
            << "                   No decryption if unspecified\n\n"
            << std::endl;
        return 0;
    }
    if (version_flag) {
        std::cout << "0.3.0" << std::endl;
        return 0;
    }

    if (output_err_flag) {
        std::cerr << "[error] -o requires a filename argument" << std::endl;
        return 1;
    }

    if (input_err_flag) {
        std::cerr << "[error] -i requires a filename argument" << std::endl;
        return 1;
    }
    if (encrypt_err_flag){
        std::cerr << "[error] --encrypt requires an integer argument" << std::endl;
        return 1;
    }
    if (decrypt_err_flag){
        std::cerr << "[error] --decrypt requires an integer argument" << std::endl;
        return 1;
    }
    if (unknown_arg_flag) {
        std::cerr << "[error] unknown argument(s) "
                  << "\n";
        for (const std::string& element : unknown_arg_vect) {
            std::cerr << element << "\n";
        }
        return 1;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    //Read in input and transliterate it.
    if (!inputFile.empty()) {
        std::ifstream in_file{inputFile};

        if (in_file.good()) {
            while (in_file >> inputChar) {
                inputText += transform_char(inputChar);
            }
        } else {
            std::cout << "Input File not good, please see -h"
                      << "\n";
            return 1;
        }
        in_file.close();
    } else {
        while (std::cin >> inputChar) {
            inputText += transform_char(inputChar);
        }
    }
    //Transform transliterated string via Caeser Shift
    std::string outText{CaesarCipher(key, inputText, encrypt_flag, decrypt_flag)};


    //Read out output, to file, else, stdout.
    if (!outputFile.empty()) {
        std::ofstream out_file{outputFile};
        if (out_file.good()) {
            out_file << outText << "\n";
        }

        else {
            std::cout << "Output File not good, please see -h"
                      << "\n";
            return 1;
        }
        out_file.close();
    } else {
        std::cout << outText<< std::endl;
    }
    return 0;
}
