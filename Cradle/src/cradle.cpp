
#include <cradle.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
void getChar(){
    look = cin.get();
}

void Error (char  *s){
    cerr << "\nError: " << s << endl;
}

void Abort(char *s){
    Error(s);
    exit(1);
}

void Expected(char *s){
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
    return (UPCASE(c) >= 'A') && (UPCASE(c)<='Z');
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

char getNum(){
    char c = look;
    
    if (!isDigit(look)){
        cout << tmp <<" Integer " << endl;
        Expected(tmp);
    }
    getChar();
    
    return c;
}

void Emit(char *s){
    cout << "\t" <<s << endl;
}

void EmitLn(char *s){
    Emit(s);
    cout << "\n" << endl;
}
void init(){
    getChar();
}