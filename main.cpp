#include <iostream>
#include "util.h"
#include "util.cpp"
using namespace std;


int main(){
    int userRows, userColumns;
    cout << "Enter the number of rows -> ";   
    cin >> userRows;   
    cout << "Enter the number of columns -> ";
    cin >> userColumns; 
    printGrid(userRows, userColumns);

    return 0;
}
