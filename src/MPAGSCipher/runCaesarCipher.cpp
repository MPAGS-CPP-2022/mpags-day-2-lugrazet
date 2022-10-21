#include <string>
#include "runCaeserCipher.hpp"
/*
What inputs
What output
what args 
what return type



We want to receive a number 0-25 as K, the key to shunt all the letters along.
We want to receive the string that we want to convert

we want to output the shifted string. 
*/

std::string CaesarCipher(
    const int& init_key,
    const std::string& in_text,
    const bool& encrypt,
    const bool& decrypt
){
    //Convert initial key to a functional key
    const int Key = (init_key % 25) * (encrypt - decrypt);
    //Initialise the alphabet characters
    std::string ab_str{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; 
    
    //Init the output string
    std::string out_text{};

    //Loop input string and convert via Key
    for( const char& elem: in_text){
        out_text += ab_str[ab_str.find(elem) + Key];
    }

    return out_text;
}