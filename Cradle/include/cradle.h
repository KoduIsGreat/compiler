/* 
 * File:   cradle.h
 * Author: Adam
 *
 * Created on October 25, 2015, 10:01 PM
 */
#include <string>
#ifndef CRADLE_H
#define	CRADLE_H
#define UPCASE(C) ((1<<6) |(C))
#define MAX_BUF 100
extern char tmp[MAX_BUF];
extern char look;

void getChar();

void Error (std::string s);
void Abort (std::string s);
void Expected(std::string s);
void Match(char x);

int isAlpha(char c);
int isDigit(char c);
int isAddop(char c);
char getName();
char getNum();

void Emit(std::string s);
void EmitLn(std::string s);
void init();
#endif	/* CRADLE_H */

