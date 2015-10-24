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
#include <write.h>
using namespace std;

/*
 * simple executable to generate a file with 100 random numbers;
 */
void write (char* filename);


int main() {
    
    string filename;
    cout << "name of file to generate?\n";
    cin >> filename;
    
    write(filename);
    
    return 0;
}

