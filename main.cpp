#include <iostream>
#include <ctime>
#include "battlefield.h"
#include "battlefield.cpp"
#include "gameinfo.h"
#include "gameinfo.cpp"
#include "simulation.cpp"
using namespace std;


int main(){
    srand(time(NULL));
    string filename = "input.txt";

    GameInfo gameInfo;
    gameInfo.readFile(filename);
    gameInfo.printGameInfo();    // Print the parsed information to verify it

    Battlefield battlefield(gameInfo);
    battlefield.printBattlefield(gameInfo);

    //beginSimulation();

    return 0;
}
