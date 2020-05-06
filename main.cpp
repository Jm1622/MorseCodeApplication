#include <iostream>
#include <MorseCodeTranslator.h>

int main() {
    std::string testString = "Test Message";
    MorseCodeTranslator *morseTranslator = new MorseCodeTranslator();
    std::string morseString = morseTranslator->encode(testString);
    std::cout << morseString << '\n';
    std::cout << morseTranslator->decode(morseString) << '\n';
    return 0;
}