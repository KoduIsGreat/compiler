/* 
 * File:   cradle.h
 * Author: Adam
 *
 * Created on October 25, 2015, 10:01 PM
 */

#ifndef CRADLE_H
#define	CRADLE_H
#define UPCASE(C) ((1<<6) |(C))
#define MAX_BUF 100
char tmp[MAX_BUF];
char look;

void getChar();

void Error (char *s);
void Abort (char *s);
void Expected(char *s);
void Match(char x);

int isAlpha(char c);
int isDigit(char c);
int isAddop(char c);
char getName();
char getNum();

void Emit(char *s);
void EmitLn(char *s);
void init();
#endif	/* CRADLE_H */

