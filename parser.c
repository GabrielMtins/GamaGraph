#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

double interpretExpression(char* expression){
    if(expression[0] == '(' && expression[strlen(expression)-1] == ')'){
        int foundSomething = 0;
        for(int i = 1; i < strlen(expression)-1; i++){
            if(expression[i] == '(' || expression[i] == ')'){
                foundSomething = 1;
                break;
            }
        }
        if(!foundSomething){
            char str[256] = "";
            for(int j = 1; j < strlen(expression)-1; j++){
                strncat(str, &expression[j], 1);
            }
            return interpretExpression(str);
        }
    }
    for(int i = strlen(expression)-1; i >= 0; i--){
        if(expression[i] == ')'){
            int toSkip = 1;
            while(toSkip){
                i--;
                if(expression[i] == ')') toSkip++;
                if(expression[i] == '(') toSkip--;
            }
        }
        if(expression[i] == '+' || expression[i] == '-'){
            char str1[256] = "";
            char str2[256] = "";
            for(int j = 0; j < i; j++) strncat(str1, &expression[j], 1);
            for(int j = i+1; j < strlen(expression); j++) strncat(str2, &expression[j], 1);
            if(expression[i] == '+') return interpretExpression(str1)+interpretExpression(str2);
            if(expression[i] == '-') return interpretExpression(str1)-interpretExpression(str2);
        }
    }
    for(int i = strlen(expression)-1; i >= 0; i--){
        if(expression[i] == ')'){
            int toSkip = 1;
            while(toSkip){
                i--;
                if(expression[i] == ')') toSkip++;
                if(expression[i] == '(') toSkip--;
            }
        }
        if(expression[i] == '*' || expression[i] == '/'){
            char str1[256] = "";
            char str2[256] = "";
            for(int j = 0; j < i; j++) strncat(str1, &expression[j], 1);
            for(int j = i+1; j < strlen(expression); j++) strncat(str2, &expression[j], 1);
            if(expression[i] == '*') return interpretExpression(str1)*interpretExpression(str2);
            if(expression[i] == '/') return interpretExpression(str1)/interpretExpression(str2);
        }
    }
    for(int i = strlen(expression)-1; i >= 0; i--){
        if(expression[i] == ')'){
            int toSkip = 1;
            while(toSkip){
                i--;
                if(expression[i] == ')') toSkip++;
                if(expression[i] == '(') toSkip--;
            }
        }
        if(expression[i] == '^'){
            char str1[256] = "";
            char str2[256] = "";
            for(int j = 0; j < i; j++) strncat(str1, &expression[j], 1);
            for(int j = i+1; j < strlen(expression); j++) strncat(str2, &expression[j], 1);
            return pow(interpretExpression(str1), interpretExpression(str2));
        }
    }
    {
        if(expression[0] == 'c' && expression[1] == 'o' && expression[2] == 's'){
            char str[256] = "";
            for(int i = 4; i < strlen(expression)-1; i++) strncat(str, &expression[i], 1);
            return cos(interpretExpression(str));
        }
    }
    {
        if(expression[0] == 's' && expression[1] == 'i' && expression[2] == 'n'){
            char str[256] = "";
            for(int i = 4; i < strlen(expression)-1; i++) strncat(str, &expression[i], 1);
            return sin(interpretExpression(str));
        }
    }
    {
        if(expression[0] == 't' && expression[1] == 'a' && expression[2] == 'n'){
            char str[256] = "";
            for(int i = 4; i < strlen(expression)-1; i++) strncat(str, &expression[i], 1);
            return tan(interpretExpression(str));
        }
    }
    {
        if(!strcmp(expression, "PI")) return 3.141592;
    }
    if(!strcmp(expression, "x")) return xGlobalValue;
    return atof(expression);
}
