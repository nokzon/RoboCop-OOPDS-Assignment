#include <iostream>
#include "util.h"
#include "util.cpp"
using namespace std;


int main(){
    string filename = "input.txt";
    GameInfo gameInfo;
    gameInfo.readFile(filename);
    gameInfo.printGameInfo();    // Print the parsed information to verify it

    return 0;
}
