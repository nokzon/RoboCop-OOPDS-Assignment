#include <iostream>
#include "util.h"
#include "util.cpp"
using namespace std;


int main(){
    try{
        readFiles();
    }
    catch (const exception &e){
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
