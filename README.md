# Simple Morse Code Parser application. 

## Features:
* Console Encode and Decode
* Encode and Decode from a file on the system
* Network communicated messages which are sent as morse code

## Execution Instructions:
To compile using g++:
``` bash
g++ main.cpp MorseCodeTranslator.cpp -I ./ -L /usr/lib/ -lboost_system -lboost_thread -lpthread
```
The boost library must be installed on your system, see below for getting it installed on a linux system.
https://www.boost.org/doc/libs/1_61_0/more/getting_started/unix-variants.html

I used the command below to install on centos 
```
yum install boost-devel
```
