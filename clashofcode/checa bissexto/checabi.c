#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int a;
    scanf("%d", &a);
    int b;
    scanf("%d", &b);

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    int earlier, later, leapy = 0;

    if(a < b){
        earlier = a, later = b;
    }
    else{
        earlier = b, later = a;
    }

    for(int i = earlier; i <= later; i++){
        if(i % 4 == 0){
            if(i % 100 != 0){
                leapy++;
            }
            else{
                if(i % 400 == 0){
                    leapy++;
                }
            }
        }
    }

    printf("%i\n", leapy);

    return 0;
}
