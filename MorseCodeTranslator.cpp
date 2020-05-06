#include "MorseCodeTranslator.h"
#include <iostream>

MorseCodeTranslator::MorseCodeTranslator() {
}
std::string MorseCodeTranslator::decode(const std::string & message) {
    std::string outputString = "";
    std::string morseLetterString = "";
    for (const char & c : message) {
        if (c == MorseCodeTranslator::letterSpace) {
            /*When we find the end of a letter 
            we want to add the character to the string 
            Then reset the morseLetterString for next code
            */
            outputString.push_back(decodeTable.at(morseLetterString));
            morseLetterString = "";
        } else if (c == MorseCodeTranslator::wordSpace) {
            /*When we find the end of a word we want to add the letter 
            value of the morse code string to the string
            Also in this case add a space, and then reset the morseLetterString for next code
            */
            outputString.push_back(decodeTable.at(morseLetterString));
            outputString.append(" ");
            morseLetterString = "";
        } else {
            /*This means we haven't reached the end of the morse code segment yet 
            so add it to morseLetterString*/
            morseLetterString.push_back(c);
        }
    }
    // When we reach end we'll have one character left
    outputString.push_back(decodeTable.at(morseLetterString));
    return outputString;
}

std::string MorseCodeTranslator::encode(const std::string &message) {
    std::string capitalizedMessage = "";
    // Create an all caps version of the message (morse code is only capitals)
    for (const char & c : message) {
        capitalizedMessage.push_back(toupper(c));
    }
    std::string outputString = "";
    for (const char & c : capitalizedMessage) {
        if (c == ' ') {
            /* If we have a space we want to add our word space 
            and will need to remove the last letter space*/
            outputString.pop_back();
            outputString.push_back(MorseCodeTranslator::wordSpace);
        } else {
            /* If we have a letter we
            simply get its morse code equivalent and add a letter space */
            outputString.append(MorseCodeTranslator::encodeTable.at(c));
            outputString.push_back(MorseCodeTranslator::letterSpace);
        }
    }
    // When we reach end of loop remove the letterSpace that will be at the end
    outputString.pop_back();
    return outputString;
}