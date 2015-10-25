/* 
 * File:   read.cpp
 * Author: Adam
 *
 * Created on October 25, 2015, 12:00 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <read.h>
using namespace std;


int* reverse(int list []){
    int temp;
    int i,j;
    int n = max_size;
    for(i=0,j=n-1;i<n/2;i++,j--)
	{
		temp=list[i];
		list[i]=list[j];
		list[j]=temp;
	}
    return list;
}
void print(int sum, int min , int max){
    printf("sum %i min %i max %i\n",sum,min,max);
}
int * read(std::string filename){
    int temp=0;
    std::ifstream ifs;
    ifs.open (filename.c_str(), std::ifstream::in );
    
    for(int i =0 ; i<(sizeof(list)/sizeof(list[0]));i++){
        ifs >> temp;
        list[i] =temp;
        if( i ==0){
            min_val = temp;
            max_val = temp;
        }
        if(temp > max_val){
            max_val = temp;
        }
        if(temp< min_val){
            min_val = temp;
        }
        sum += temp;
    }
    print(sum,min_val,max_val);
    return list;
}