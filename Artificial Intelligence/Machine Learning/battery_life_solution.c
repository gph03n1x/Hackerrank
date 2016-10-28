#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float output;
    char line[64];
    while(fgets(line, 64, stdin)) {
        float input = atof(line);
        output=input*2.0;
        if(output>8.0)
            output=8.0;
        printf("%.2f\n", output);
    }    
    return 0;
}
