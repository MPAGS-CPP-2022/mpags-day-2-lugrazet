#include <string>
#include "runCaesarCipher.hpp"
/*
Receive a string and encrypt it via a Caesar Cipher

A Caesar Cipher is a simple shift of the alphabet. 
For example, A shifted 5 letters is F, and shifted -6 letters is U

    Receives a string to shift
    Receives an unsigned key, (not limited to 0-25)
    Receives flags, true indicating to encrypt or decrypt respectively.

    returns the shifted string 
*/

std::string runCaesarCipher(
    const std::size_t init_key,
    const std::string& in_text,
    const bool encrypt,
    const bool decrypt
){
    //checks if encryption or decryption is needed.
    if ( (encrypt && decrypt) || !(encrypt || decrypt) ){
        return in_text;
    }

    std::size_t Key{0};

    if (encrypt){
        Key = (init_key%26);    
    }
    if (decrypt){
        Key = 26 - (init_key%26);
    }
    //Initialise the alphabet characters
    std::string ab_str{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; 
    
    //Init the output string
    std::string out_text{};

    //Loop input string and convert via Key
    for( const char& elem: in_text){
        out_text += ab_str[(ab_str.find(elem) + Key)%26];
    }

    return out_text;
}