#include <iostream>
#include <fstream>
#include "MorseCodeTranslator.h"
#include <string>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

std::string read(tcp::socket & socket) {
       boost::asio::streambuf buf;
       boost::asio::read_until(socket, buf, "\n");
       std::istream is(&buf);
       std::string data;
       std::getline(is, data);
       return data;
}


int main() {
    bool keepLoop = true;
    MorseCodeTranslator *morseTranslator = new MorseCodeTranslator();
    std::string inputMessage;
    std::string encodedMessage;
    std::string decodedMessage;
    std::string destinationIP;
    std::string fileName;
    std::string line;
    char buffer[1024];
    std::ifstream file;
    boost::asio::io_service io_service;
    int menuOption = 0;
    while (keepLoop) {
        std::cout << "Menu: "
        << "\n\t" << "1: Encode Message from console."
        << "\n\t" << "2: Decode message from console"
        << "\n\t" << "3: Encode message from filesystem"
        << "\n\t" << "4: Decode message from filesystem"
        << "\n\t" << "5: Send messages to a hosted server"
        << "\n\t" << "6: Host a server to receive morse code messages"
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
                if (file.is_open()) {
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
                if (file.is_open()) {
                    while ( std::getline(file, line) ) {
                        decodedMessage += morseTranslator->decode(line)+"\n";
                    }
                    file.close();
                } else {
                    std::cout << "Unable to open file with path: " << fileName;
                }
                std::cout << "Decoded Message: " << decodedMessage << '\n';
                break;
            case 5:
            {
                std::cin.ignore();
                std::cout << "Input Message: ";
                std::getline(std::cin, inputMessage);
                std::cout << "Input Destination IP: ";
                std::getline(std::cin, destinationIP);
                encodedMessage = morseTranslator->encode(inputMessage) + "\n";
                std::cout << "Encoded Message: " << encodedMessage << '\n';
                boost::asio::io_service io_service;
                // socket creation
                tcp::socket socket(io_service);
                // connect to destination IP
                socket.connect(tcp::endpoint( 
                    boost::asio::ip::address::from_string(destinationIP), 1234));
                // send encoded message to server
                boost::system::error_code error;
                boost::asio::write(socket, boost::asio::buffer(encodedMessage), error);
                if (!error) {
                    std::cout << "Morse Code Message: "<< inputMessage << " successfully sent." << '\n';
                } else {
                    std::cout << "send failed: " << error.message() << "\n";
                }
                break;
            }
            case 6:
            {
                std::cout << "Waiting for message sent to server: "<< '\n';
                // listen for new connection
                tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234));
                // Create socket object
                tcp::socket socket(io_service);
                // waiting for connection
                acceptor_.accept(socket);
                // read message
                std::string message = read(socket);
                std::cout << "Received Morse Code: " << message << '\n';
                decodedMessage = morseTranslator->decode(message);
                std::cout << "Translated message: " << decodedMessage << '\n';
                break;
            }
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