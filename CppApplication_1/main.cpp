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
int main() {
    std::ofstream ofs;
    ofs.open ("test.txt", std::ofstream::out | std::ofstream::app);
    ofs << " more lorem ipsum";
    ofs.close();
    return 0;
}

