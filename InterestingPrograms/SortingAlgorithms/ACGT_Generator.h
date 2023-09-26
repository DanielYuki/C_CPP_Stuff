#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef GENERATOR_H
#define GENERATOR_H

// Generates a file containing random strings, one per line.
// Number of strings: asks the user.
// String length: 50
// String content: characters A, C, G, T
int generator()
{
    clock_t start, end;
    char s[51]; // string
    int i,
        k,
        n,        // number of strings
        draw;     // drawn number
    FILE *output; // output file

    // read quantity
    printf("How many elements? ");
    scanf("%d", &n);

    // n = 15000;

    // open file and write quantity
    output = fopen("input.txt", "w");
    fprintf(output, "%d\n", n);
    // initialize the random number generator
    time_t t;
    start = clock();
    srand((unsigned)time(&t));
    // generate n strings
    for (i = 0; i < n; i++)
    {
        // for each position in the string
        for (k = 0; k < 50; k++)
        {
            // draw a number between 0 and 3
            draw = rand() % 4;
            // assign a character to the string
            switch (draw)
            {
            case 0:
                s[k] = 'A';
                break;
            case 1:
                s[k] = 'C';
                break;
            case 2:
                s[k] = 'G';
                break;
            case 3:
                s[k] = 'T';
                break;
            }
        }
        // mark end of string and write to output
        s[50] = '\0';
        fprintf(output, "%s\n", s);
    }
    end = clock();
    printf("time to create random strings: %f \n", ((end - start) / (float)CLOCKS_PER_SEC));
    fclose(output);
    return 0;
}

#endif