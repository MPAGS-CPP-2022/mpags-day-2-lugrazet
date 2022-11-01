#ifndef MPAGSCIPHER_RUNCAESERCIPHER_HPP
#define MPAGSCIPHER_RUNCAESERCIPHER_HPP

#include <string>


//Caesar Shifting the string. 
std::string runCaesarCipher(
    const std::size_t init_key,
    const std::string& in_text,
    const bool encrypt,
    const bool decrypt
);

#endif    //MPAGSCIPHER_RUNCAESERCIPHER_HPP