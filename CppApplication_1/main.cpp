/* 
 * File:   main.cpp
 * Author: Adam
 *
 * Created on October 23, 2015, 12:37 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
const int max_val = 100;
int main() {
    std::ofstream ofs;
    ofs.open ("test.txt", std::ofstream::out | std::ofstream::app);
    for(int i = 0 ; i<max_val; i++){
        ofs << rand() % 100+i "\n";
    }
    ofs.close();
    return 0;
}

