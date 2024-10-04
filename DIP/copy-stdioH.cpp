// Este ejemplo muestra cómo se puede lograr la independencia de dispositivos usando las funciones estándar de C como getchar() y putchar().
#include <stdio.h>
using namespace std;

// Programa de copiado usando getchar y putchar
void Copy()
{
    while (1)
    {
        char c = getchar(); 
        if (c == 'q')
            break; 
        putchar(c); 
    }
}

int main()
{
    Copy(); 
    return 0;
}
