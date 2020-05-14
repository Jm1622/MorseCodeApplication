#include <iostream>
#include <fstream>
#include "MorseCodeTranslator.h"
#include <string>

int main() {
    bool keepLoop = true;
    MorseCodeTranslator *morseTranslator = new MorseCodeTranslator();
    std::string inputMessage;
    std::string encodedMessage;
    std::string decodedMessage;
    std::string fileName;
    std::string line;
    std::ifstream file;
    int menuOption = 0;
    while (keepLoop) {
        std::cout << "Menu: "
        << "\n\t" << "1: Encode Message from console."
        << "\n\t" << "2: Decode message from console"
        << "\n\t" << "3: Encode message from filesystem"
        << "\n\t" << "4: Decode message from filesystem"
        << "\n\t" << "5: Encode message to network"
        << "\n\t" << "6: Decode message from network"
        << "\n\t" << "7: Quit"
        <<'\n';
        menuOption = 0;
        inputMessage = "";
        encodedMessage = "";
        decodedMessage = "";
        std::cout << "Option: ";
        std::cin >> menuOption;
        switch (menuOption) {
            case 1:
                std::cout << "Input Message: ";
                std::cin.ignore();
                std::getline(std::cin, inputMessage);
                encodedMessage = morseTranslator->encode(inputMessage);
                std::cout << "Encoded Message: " << encodedMessage << '\n';
                break;
            case 2:
                std::cout << "Input Encoded Message: ";
                std::cin.ignore();
                std::getline(std::cin, inputMessage);
                decodedMessage = morseTranslator->decode(inputMessage);
                std::cout << "Decoded Message: " << decodedMessage << '\n';
                break;
            case 3:
                std::cout << "Input path to file: ";
                std::cin.ignore();
                std::getline(std::cin, fileName);
                file.open(fileName);
                if (file.is_open()){
                    while ( std::getline(file, line) ) {
                        encodedMessage += morseTranslator->encode(line)+"\n";
                    }
                    file.close();
                } else {
                    std::cout << "Unable to open file with path: " << fileName;
                }
                std::cout << "Encoded Message: " << encodedMessage << '\n';
                break;
            case 4:
                std::cout << "Input path to file: ";
                std::cin.ignore();
                std::getline(std::cin, fileName);
                file.open(fileName);
                if (file.is_open())
                {
                    while ( std::getline(file, line) )
                    {
                        decodedMessage += morseTranslator->decode(line)+"\n";
                    }
                    file.close();
                }
                else {
                    std::cout << "Unable to open file with path: " << fileName;
                }
                std::cout << "Decoded Message: " << decodedMessage << '\n';
                break;
            case 5:
                std::cout << "Not implemented yet, sorry!" << '\n';
                break;
            case 6:
                std::cout << "Not implemented yet, sorry!" << '\n';
                break;
            case 7:
                keepLoop = false;
                std::cout << "Exiting the application. Thanks for using it!" << '\n';
                break;
            default:
                std::cout << "Invalid option selected" << '\n';
                break;
        }
    }
    return 0;
}