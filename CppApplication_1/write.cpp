/* 
 * File:   main.cpp
 * Author: Adam
 *
 * Created on October 23, 2015, 12:37 AM
 */




/*
 * writes a file with max_val random numbers;
 */

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <write.h>
using namespace std;


void write(string filename){
    std::ofstream ofs;
    ofs.open (filename.c_str(), std::ofstream::out );
   
    srand(time(NULL));
    
    for(int i = 0 ; i<max_val; i++){
        ofs << rand() % 100+i;
        ofs << '\n';
    }
    
    ofs.close();
}