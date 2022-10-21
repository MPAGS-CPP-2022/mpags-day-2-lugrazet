#include "TransformChar.hpp"
#include <cctype>
#include <string>

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
        //std::cout << (in_char) << "\n";
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
