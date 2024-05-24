# RoboCop-OOPDS-Assignment
In this project, we are required to implement a "Robot War" simulator using standard C++. The simulator is a turn-based warfare simulation of robots on a 2D battlefield. Robots with different capabilities fight each other until one remains or the simulation time is up.



### Battlefield
- **Size**: A 2D matrix
- **Display**: Uses characters/symbols to represent robots, locations, and boundaries

### Simulation Rules
1. **Turn-Based**: Robots take turns to perform actions: look, move, and fire (depending on capabilities).
2. **Movement**: Robots move to one of 8 neighboring locations.
3. **Look**: Reveals a 3x3 grid centered on the robot’s position.
4. **Fire**: Targets specific locations without self-destruction.

### The Types of Robots
1. **RoboCop**: Looks, moves, fires (up to 3 times randomly up to a specified range). Can be upgraded to TerminatorRoboCop after 3 kills.
2. **Terminator**: Looks, moves to a random neighboring cell and stomps on existing enemy. Upgrades to TerminatorRoboCop after 3 kills.
3. **TerminatorRoboCop**: Can both fire and step on enemies. Upgrades to UltimateRobot after 3 kills.
4. **BlueThunder**: Fires in a clockwise pattern, fires once each turn. Upgrades to MadBot after 3 kills.
5. **MadBot**: Fires once at a random neighboring cell. Upgrades to RoboTank after 3 kills.
6. **RoboTank**: Fires once randomly on any area the battlefield. Upgrades to UltimateRobot after 3 kills.
7. **UltimateRobot**: Moves like TerminatorRoboCop, stepping and killing any robots on its path. Also fires randomly at 3 locations on tbe battlefield.

### Additional Features
- **Lives**: Each robot has 3 lives and re-enters the battlefield after destruction.
- **Display**: Shows battlefield, actions, and results each turn; saves this info to a text file.
