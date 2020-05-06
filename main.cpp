#include <iostream>
#include <MorseCodeParser.h>

int main() {
    std::string testString = "- . ... -\t-- . ... ... .- --. .";
    MorseCodeParser *morseParser = new MorseCodeParser();
    std::cout << morseParser->parse(testString) << '\n';
    return 0;
}