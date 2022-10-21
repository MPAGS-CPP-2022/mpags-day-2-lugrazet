#ifndef MPAGSCIPHER_RUNCAESERCIPHER_HPP
#define MPAGSCIPHER_RUNCAESERCIPHER_HPP

#include <string>


//Caeser Shifting the string. 
std::string CaeserCipher(
    const int& init_key,
    const std::string& in_text,
    const bool& encrypt,
    const bool& decrypt
);

#endif    //MPAGSCIPHER_RUNCAESERCIPHER_HPP