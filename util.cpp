#include "util.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


// Function prototype
void printGrid(int &fieldRows, int &fieldCol);

// readFiles function, it reads the content from input.txt and takes in the needed contents
void readFiles(){
    // Declare variables needed
    string myLine, M, N, steps, robots;

    // Read files input.txt
    ifstream myFile("input.txt");

    while(getline(myFile, myLine)){
        // Checks the first line for keywords using stringstream
        if (myLine.find("M by N: ") != string::npos){
            stringstream s(myLine);
            string dummy1;
            s >> dummy1 >> dummy1 >> dummy1 >> M >> N;
            cout << M << " " << N << endl;
        }

        // Checks for second line for keywords using stringstream 
        else if (myLine.find("Steps: ") != string::npos){
            stringstream s(myLine);
            string dummy2;
            s >> dummy2 >> steps;
            cout << steps << endl;
        } 

        // Checks for second line for keywords using stringstream 
        else if (myLine.find("Robots: ") != string::npos){
            stringstream s(myLine);
            string dummy3;
            s >> dummy3 >> robots;
            cout << robots << endl;
        } 

        // Error handling
        else {
            throw runtime_error("String not found!");
        }
    }

    // Turn string into integer
    int strM = stoi(M);
    int strN = stoi(N);
    int strSteps = stoi(steps);

    // Call functions
    printGrid(strM, strN);
    cout << "Steps: " << strSteps;

    // Close file to prevent wasting memory resources
    myFile.close();
}

// printing grid function
void printGrid(int &fieldRows, int &fieldCol){
    cout<<endl;
    cout<<" ";
    int i=1,j;

    // Loop that outputs top row of column numbers
    for(j = 0; j <= 4*fieldCol; j++){
        if(j%4==2){
            cout<<i++;
        }
        else{
            cout<<" ";
        }
    }
    cout<<endl;

    // Loop to output the entire grid
    for(i = 0; i <= 2*fieldRows; i++){
        // Print grid numbers on the left side
        if(i%2!=0){
            cout << (i / 2) + 1;
        }
        else{
            cout << " ";
        }

        // Loop to print all rows of the grid
        for(j = 0; j <= 2*fieldCol; j++){
            if(i%2==0){
                if(j==0){
                    cout<<" ";
                }
                if(j%2==0){
                    cout<<" ";
                }
                else{
                    cout<<"---";
                }
            }
            else{
                if(j%2==0)
                    cout<<"|";
                else cout<<"   ";
            }
        }

        // Print row numbers on the right side
        if(i%2!=0){
            cout << (i/2) + 1;
        }
        cout << endl;
    }

    // Outputs bottom row of the column numbers
    cout<<" ";
    for(j = 0, i = 1; j <= 4*fieldCol; j++){
        if(j%4==2){
            cout<<i++;
        }
        else{
            cout<<" ";
        }
    }
    cout<<endl;
}
