# RoboCop-OOPDS-Assignment
In this project, we are required to implement a "Robot War" simulator using standard C++. The simulator simulates the warfare of robots in a given battlefield. 

## The Types of Robots
1. **RoboCop**: Looks, moves, fires (up to 3 times randomly up to a specified range). Can be upgraded to TerminatorRoboCop after 3 kills.
2. **Terminator**: Looks, moves to a random neighboring cell and stomps on existing enemy. Upgrades to TerminatorRoboCop after 3 kills.
3. **TerminatorRoboCop**: Can both fire and step on enemies. Upgrades to UltimateRobot after 3 kills.
4. **BlueThunder**: Fires in a clockwise pattern, fires once each turn. Upgrades to MadBot after 3 kills.
5. **MadBot**: Fires once at a random neighboring cell. Upgrades to RoboTank after 3 kills.
6. **RoboTank**: Fires once randomly on any area the battlefield. Upgrades to UltimateRobot after 3 kills.
7. **UltimateRobot**: Moves like TerminatorRoboCop, stepping and killing any robots on its path. Also fires randomly at 3 locations on tbe battlefield.
