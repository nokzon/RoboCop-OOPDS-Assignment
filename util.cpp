#include "util.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


void printGrid(int &fieldRows, int &fieldCol);

void readFiles(){
    string myLine, M, N;
    ifstream myFile("input.txt");
    getline(myFile, myLine);

    if (myLine.find("M by N: ") != string::npos){
        stringstream s(myLine);
        string dummy1;
        s >> dummy1 >> dummy1 >> dummy1 >> M >> N;
    } else{
        throw runtime_error("String 'M by N: ' not found!");
    }

    cout << M << endl << N << endl;
    int strM = stoi(M);
    int strN = stoi(N);

    printGrid(strM, strN);

    myFile.close();
}

void printGrid(int &fieldRows, int &fieldCol){
    cout<<endl;
    cout<<" ";
    int i=1,j;
    for(j = 0; j <= 4*fieldCol; j++){
        if(j%4==2){
            cout<<i++;
        }
        else{
            cout<<" ";
        }
    }
    cout<<endl;
    for(i = 0; i <= 2*fieldRows; i++){
        if(i%2!=0){
            cout << (i / 2) + 1;
        }
        else{
            cout << " ";
        }
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
        if(i%2!=0){
            cout << (i/2) + 1;
        }
        cout << endl;
    }
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
