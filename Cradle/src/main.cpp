/* 
 * File:   main.cpp
 * Author: Adam
 *
 * Created on October 24, 2015, 5:35 PM
 */

#include <cstdlib>
#include <cradle.h>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;


void Term();
void Expression();
void Add();
void Substract();
void Factor();
char CR='\n';

void Multiply()
{
    Match('*');
    Factor();
    EmitLn("imull (%esp), %eax");
    /* push of the stack */
    EmitLn("addl $4, %esp");
} 

void Divide()
{
    Match('/');
    Factor();

    /* for a expersion like a/b we have eax=b and %(esp)=a
     * but we need eax=a, and b on the stack 
     */
    EmitLn("movl (%esp), %edx");
    EmitLn("addl $4, %esp");

    EmitLn("pushl %eax");

    EmitLn("movl %edx, %eax");

    /* sign extesnion */
    EmitLn("sarl $31, %edx");
    EmitLn("idivl (%esp)");
    EmitLn("addl $4, %esp");

}
void Ident(){
    // convert to string 
    
    string name =getName();
    
    if(look == '('){
        Match('(');
        Match(')');
        EmitLn("bsr $"+ name);
    }
    else{
        string s = "movl $"+name+", %edx";
        EmitLn(s);
    }
}
void Factor()
{

    if(look == '(') {

        Match('(');
        Expression();
        Match(')');
     } else if(isAddop(look)) {

        Match('-');
        cout << tmp << "movl $" <<getNum() <<" %%eax" <<endl;
        
        EmitLn(tmp);
        EmitLn("negl %eax");
       
    } else if(isAlpha(look)){
        Ident();
    } else {

        cout << tmp << "movl $" <<getNum() <<" %%eax" <<endl;
        EmitLn(tmp);
    }
}

void Term()
{
    Factor();
    while (strchr("*/", look)) {

        EmitLn("pushl %eax");

        switch(look)
        {
            case '*':
                Multiply();
                break;
            case '/':
                Divide();
                break;
            default:
                Expected("Mulop");
        }
    }
}

void Expression()
{
    if(isAddop(look))
        EmitLn("xor %eax, %eax");
    else
        Term();

    while (strchr("+-", look)) {

        EmitLn("pushl %eax");

        switch(look)
        {
            case '+':
                Add();
                break;
            case '-':
                Substract();
                break;
            default:
                Expected("Addop");
        }
    }
}

void Assignment()
{
    string name = getName();    
    Match('=');
    Expression();
    EmitLn("leal %eax, "+name);
    EmitLn("movl %eax, %edx");
}

void Add()
{
    Match('+');
    Term();
    EmitLn("addl (%esp), %eax");
    EmitLn("addl $4, %esp");
    
}


void Substract()
{
    Match('-');
    Term();
    EmitLn("subl (%esp), %eax");
    EmitLn("negl %eax");
    EmitLn("addl $4, %esp");
}


int main()
{
    while(true)
    {
        init();
        Assignment();
        if(look != CR){
            Expected("NewLine");
        }
    }
    return 0;
}

