#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum number of matrices
#define N 20

// define struct Matrix as Matrix
typedef struct Matrix Matrix;

struct Matrix
{
    int col;
    int lin;
};

// global variables
int calls = 0;
int BestCut[N][N];
int memo[N][N];

// recursive function to calculate the minimum number of scalar multiplications
int MatrixChainOrder(Matrix matrix[], int i, int j)
{
    calls++;

    // if there is only one matrix
    if (i == j)
        return 0;

    // triyng to use memoization here, dont really know if it works
    if (memo[i][j] != -1)
        return memo[i][j];
    
    int k;
    int min = 999999999;
    int count;

    // place parenthesis at different places between first and last matrix,
    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(matrix, i, k) +
                MatrixChainOrder(matrix, k + 1, j) +
                matrix[i - 1].lin * matrix[k].col * matrix[j].col;

        if (count < min)
        {
            min = count;
            BestCut[i][j] = k; // Store the best split point in BestCut matrix
            memo[i][j] = min;  // Store the minimum number of scalar multiplications in memo matrix
        }
    }

    // return minimum count
    return min;
}

// Function to print the optimal parenthetical expression using the BestCut matrix
void PrintOptimalParentheses(FILE *outputFile, int i, int j)
{
    if (i == j)
    {
        fprintf(outputFile, "A%d", i);
        return;
    }

    fprintf(outputFile, "(");
    PrintOptimalParentheses(outputFile, i, BestCut[i][j]);
    fprintf(outputFile, " ");
    PrintOptimalParentheses(outputFile, BestCut[i][j] + 1, j);
    fprintf(outputFile, ")");
}

// Another way to print the optimal parenthetical expression using the BestCut matrix
void PrintOptimalParenthesesV2(FILE *outputFile, int i, int j)
{
    if (i == j)
    {
        return;
    }

    PrintOptimalParenthesesV2(outputFile, i, BestCut[i][j]);
    PrintOptimalParenthesesV2(outputFile, BestCut[i][j] + 1, j);

    if (j - i == 1)
    {
        fprintf(outputFile, "%5d x %2d\n", i, j);
    }
    else if (BestCut[i][j] == i)
    {
        fprintf(outputFile, "%5d x %2d-%2d\n", i, BestCut[i][j] + 1, j);
    }
    else if (j - BestCut[i][j] == 1)
    {
        fprintf(outputFile, "%2d-%2d x %2d\n", i, BestCut[i][j], j);
    }
    else
    {
        fprintf(outputFile, "%2d-%2d x %2d-%2d\n", i, BestCut[i][j], BestCut[i][j] + 1, j);
    }
}

int main()
{
    char message[70];

    int n, dim, pos = 0;

    // Define input and output files
    FILE *inputFile = fopen("data.txt", "r");
    FILE *outputFile = fopen("response", "w");

    fprintf(outputFile, "Matrix Chain Order\n\n");
    fprintf(outputFile, "======================================\n\n");

    // skips the first 5 lines
    for (int i = 0; i < 5; i++)
    {
        fgets(message, 70, inputFile);
    }

    // reads the number of matrices
    fscanf(inputFile, "%d ", &n);
    fgets(message, 70, inputFile);

    // create list of matrices with the correct size
    Matrix *matrix = (Matrix *)malloc(n * sizeof(Matrix));

    // get the dimensions of the matrices
    while (fscanf(inputFile, "%d ", &dim) != EOF)
    {
        // saves the dimensions in the list of matrices
        matrix[pos].lin = dim;

        if (pos != 0 && pos != n)
        {
            fscanf(inputFile, "%d ", &dim);
        }

        matrix[pos].col = dim;

        pos++;
    }

    // initialize memo matrix with -1
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            memo[i][j] = -1;
        }
    }
    

    fclose(inputFile);

    fprintf(outputFile, "Total number of minimum multiplications: %d\n", MatrixChainOrder(matrix, 1, n));
    fprintf(outputFile, "Recursive function calls: %d\n", calls);

    fprintf(outputFile, "Optimal Parenthetical Expression: \n");
    PrintOptimalParentheses(outputFile, 1, n);
    // PrintOptimalParenthesesV2(outputFile, 1, n);

    fclose(outputFile);

    return 0;
}