#include <iostream>
#include "robots.h"
#include "battlefield.h"
#include "gameinfo.h"

using namespace std;

void simulation(GameInfo& gameInfo, Battlefield& battlefield) {
    for (int i = 0; i < gameInfo.steps; i++) {
        for (int j = 0; j < gameInfo.robotCount; j++) {
            
        }

        battlefield.printBattlefield(gameInfo);
    }
}