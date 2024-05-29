#include <iostream>
#include "util.h"
using namespace std;


int main(){
    string filename = "input.txt";
    GameInfo gameInfo = readFile(filename);
    printGameInfo(gameInfo);    // Print the parsed information to verify it

    return 0;
}
