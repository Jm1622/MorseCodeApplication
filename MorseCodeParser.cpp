#include "MorseCodeParser.h"
MorseCodeParser::MorseCodeParser() {
}
std::string MorseCodeParser::parse(std::string message) {
    std::string outputString = "";
    std::string morseLetterString = "";
    for (char const& c : message) {
        if (c == MorseCodeParser::letterSpace ||
            c == MorseCodeParser::wordSpace) {
            outputString.push_back(translationTable.at(morseLetterString));
            if (c == MorseCodeParser::wordSpace) {
                outputString.append(" ");
            }
            morseLetterString = "";
        } else {
            morseLetterString.push_back(c);
        }
    }
    outputString.push_back(translationTable.at(morseLetterString));
    return outputString;
}