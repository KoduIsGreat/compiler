/* 
 * File:   main.cpp
 * Author: Adam
 *
 * Created on October 23, 2015, 12:37 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
#include <String>
using namespace std;

/*
 * simple executable to generate a file with 100 random numbers;
 */
const int max_val = 100;
int main() {
    
    char * filename;
    cout << "name of file to generate?";
    cin >> filename;
    
    std::ofstream ofs;
    ofs.open (filename, std::ofstream::out | std::ofstream::app);
    srand(time(NULL));
    
    for(int i = 0 ; i<max_val; i++){
        ofs << rand() % 100+i;
        ofs << '\n';
    }
    
    ofs.close();
    return 0;
}

