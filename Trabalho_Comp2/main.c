#include <stdio.h>
#include <stdlib.h>
#include "externo.h"
int main()
{
    float a = 1.0, b = 2.0, saida = 0;

    saida = soma(a,b);
    printf("%f",saida);
    return 0;
}
