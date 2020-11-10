# parking-lot-system
A parking lot system created in C++
This program can be compiled using the g++ compiler by doing the following:

1. Open terminal and point current directory to the folder
that holds all of the necessary files (main.cpp, loadDataFunctions.cpp ,loadDataFunctions.hpp, Admin.hpp, Admin.cpp, management.c management.h and all other header and input files)
by using command: cd (enter path to current directory here)
Make sure all the input files and CSV file are in the same directory.
2. call g++ compiler with command: g++ loadDataFunctions.cpp Admin.cpp management.cpp main.cpp -o output.exe
3. After compiling is completed, enter command: ./output.exe

Note: ID can be only interger
Note: When Type option is prompt, only integer prompt are allowed.
Note: Name cannot be any integer value
Note: Password cannot be any integer value only but mixture of integer and character.
Note: Uncomment first two lines form loadDatabase function to run in window

