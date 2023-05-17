#include <iostream>
#include "functions.h"

int itandroids::max(int a, int b)
{
    // return the highest squared value
    return a * a > b * b ? a * a : b * b;
}

void itandroids::swap(int a, int b)
{
    // do nothing ;)
}

float itandroids::pow(float *a, float *b)
{
    // return the value of a to the power of b
    float temp = *b;
    float aux = *a;
    while (temp > 1)
    {
        *a *= aux;
        temp--;
    }
    return *a;
}

void itandroids::printArray(char arr[])
{
    // Calculate the length of the array
    int length = 0;
    while (arr[length] != '\0')
    {
        length++;
    }

    // Swap elements from the beginning and end of the array until the midpoint is reached
    for (int i = 0; i < length / 2; i++)
    {
        char temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }

    // Print the inverted array
    for (int i = 0; i < length; i++)
    {
        std::cout << " " << arr[i];
    }
}

void printArray(char arr[])
{
    int i = 0;
    while (true)
    {
        if (arr[i] == '\0')
        {
            break;
        }
        std::cout << arr[i] << " ";
        i++;
    }
}