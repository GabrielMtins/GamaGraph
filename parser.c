#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

double interpretExpression(char* expression){
    if(expression[0] == '(' && expression[strlen(expression)-1] == ')'){
        char str[256] = "";
        for(int j = 1; j < strlen(expression)-1; j++){
            strncat(str, &expression[j], 1);
        }
        return interpretExpression(str);
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
    if(!strcmp(expression, "x")) return xGlobalValue;
    return atof(expression);
}
