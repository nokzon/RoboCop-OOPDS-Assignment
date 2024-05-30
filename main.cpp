#include <iostream>
#include "util.h"
#include "util.cpp"
using namespace std;


int main(){
    string filename = "input.txt";
    GameInfo gameInfo = readFile(filename);
    printGameInfo(gameInfo);    // Print the parsed information to verify it

    return 0;
}
