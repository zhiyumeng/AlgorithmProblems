#include <iostream>
#include "Stack.h"
#include <fstream>
#include <sstream>
#include<regex>
#include "Computer.h"
using namespace std;





int main( int argc, char* argv[]) {



    Computer computer;
    computer.readExpression(argv[1]);
    computer.compute();


    return 0;
}