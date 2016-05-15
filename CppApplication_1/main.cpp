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
int* read(std::string filename);
int* reverse(int list[]);

int main() {
    while(true){
        string command;
        cout << "commands\n" <<endl;
        cout << "read or write\n" <<endl;
        cout << "q to quit\n" <<endl;
        cout << "are you reading or writing?\n" <<endl;
        cin>> command;
        if(command.compare("read")==0){
            string filename;
            cout << "name of file to read\n"<<endl;
            cin >> filename;
            int* rList= reverse(read(filename));
            for(int i =0 ; i < 100;i++){//bad magic #
                cout << rList[i];
                cout <<"\n";
            }
        }
        else if(command.compare("write")==0){
            string filename;
            cout << "name of file to generate?\n"<<endl;
            cin >> filename;

            write(filename);
        }
        else if(command.compare("q")==0){
            break;
        }
        else{
            cout << "incorrect option"<<endl;
        }
    }
    return 0;
}

