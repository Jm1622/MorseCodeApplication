#pragma once
#include <unordered_map>
#include <string>

class MorseCodeParser {
 public:
    std::string parse(std::string morseCode);
    MorseCodeParser();

 private:
    const char letterSpace = ' ';
    const char wordSpace = '\t';
    const std::unordered_map<std::string, char> translationTable = {
        {".-", 'A'},
        {"-...", 'B'},
        {"-.-.", 'C'},
        {"-..", 'D'},
        {".", 'E'},
        {"..-.", 'F'},
        {"--.", 'G'},
        {"....", 'H'},
        {"..", 'I'},
        {".---", 'J'},
        {"-.-", 'K'},
        {".-..", 'L'},
        {"--", 'M'},
        {"-.", 'N'},
        {"---", 'O'},
        {".--.", 'P'},
        {"--.-", 'Q'},
        {".-.", 'R'},
        {"...", 'S'},
        {"-", 'T'},
        {"..-", 'U'},
        {"...-", 'V'},
        {".--", 'W'},
        {"-..-", 'X'},
        {"-.--", 'Y'},
        {"--..", 'Z'},
        {".----", '1'},
        {"..---", '2'},
        {"...--", '3'},
        {"....-", '4'},
        {".....", '5'},
        {"-....", '6'},
        {"--...", '7'},
        {"---..", '8'},
        {"----.", '9'},
        {"-----", '0'},
    };
};
