
#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#include "processCommandLine.hpp"

#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& args,
                        std::string& input_file_name, bool& input_err_flag,
                        std::string& output_file_name, bool& output_err_flag,
                        bool& help_flag, bool& version_flag,
                        bool& unknown_arg_flag,
                        std::vector<std::string>& unknown_arg_vect);

#endif    //MPAGSCIPHER_TRANSFORMCHAR_HPP