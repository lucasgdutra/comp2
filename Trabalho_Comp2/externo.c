#include <stdio.h>
#include <stdlib.h>

//Limpeza de Buffer
void clean(){
    char c;
    while(c=getchar()!='\n');
}
