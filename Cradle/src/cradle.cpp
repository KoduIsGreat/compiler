
#include <cradle.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
char look ;
char tmp [MAX_BUF];
void getChar(){
    look = cin.get();
}

void Error (std::string s){
    cerr << "\nError: " << s << endl;
}

void Abort(std::string s){
    Error(s);
    exit(1);
}

void Expected(std::string s){
    cout <<  s <<" Expected" << endl;
}

void Match (char x){
    if(look ==x){
        getChar();
    }else{
        cout << tmp << x;
        Expected(tmp);
    }
}

int isAlpha(char c){
    bool t1 = (UPCASE(c)>=  'A');
    bool t2 = (UPCASE(c)<=  'z');
    return (UPCASE(c) >= 'A') && (UPCASE(c)<='z');
}

int isDigit(char c){
    return (c >='0') && (c<='9');
}

int isAddop(char c){
    return (c == '+') || (c == '-');
}

char getName(){
    char c = look;
    
    if (!isAlpha(look)){
        cout << tmp << " Name " << endl;
        Expected(tmp);
    }
    getChar();
    
    return UPCASE(c);
}
string sConv(char c){
    stringstream ss;
    string s;
    ss << c;
    ss >> s;
    return s;
}
char getNum(){
    char c = look;
    
    if (!isDigit(look)){
        cout << tmp <<" Integer " << endl;
        Expected(tmp);
    }
    getChar();
    
    return c;
}

void Emit(std::string s){
    cout << "\t" <<s << endl;
}

void EmitLn(std::string s){
    Emit(s);
    cout << "\n" << endl;
}
void init(){
    getChar();
}