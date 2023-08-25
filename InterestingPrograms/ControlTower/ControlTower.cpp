#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Airplane Airplane;

struct Airplane
{
    char from[30];
    int flight;
    struct Airplane *next;
};

Airplane *insert(Airplane *start, char *from, int flight)
{
    Airplane *newPlane = (Airplane *)malloc(sizeof(Airplane));
    strcpy(newPlane->from, from);
    newPlane->flight = flight;
    newPlane->next = NULL;
    if (start == NULL)
    {
        start = newPlane;
    }
    else
    {
        Airplane *aux = start;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = newPlane;
    }
    return start;
}

Airplane *changePosition(Airplane *start, int targetFlight, int newPosition)
{
    if (start == NULL)
    {
        return NULL; // Handle empty list
    }

    // Find the node before the target node
    Airplane *prevNode = NULL;
    Airplane *currentNode = start;
    while (currentNode != NULL && currentNode->flight != targetFlight)
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL)
    {
        return start; // Node not found
    }

    // Detach the node from its current position
    if (prevNode != NULL)
    {
        prevNode->next = currentNode->next;
    }
    else
    {
        start = currentNode->next; // Node was the first element
    }

    // Insert the node at the new position
    Airplane *newPrevNode = NULL;
    Airplane *newCurrentNode = start;
    for (int i = 1; i < newPosition && newCurrentNode != NULL; i++)
    {
        newPrevNode = newCurrentNode;
        newCurrentNode = newCurrentNode->next;
    }

    if (newPrevNode != NULL)
    {
        newPrevNode->next = currentNode;
    }
    else
    {
        start = currentNode; // Node becomes the first element
    }

    currentNode->next = newCurrentNode;

    return start;
}

Airplane *remover(Airplane *start)
{
    Airplane *aux = start;
    start = start->next;
    free(aux);

    return start;
}

int main()
{
    Airplane *start = NULL;

    int urgency = 0;

    char from[30];
    int flight;
    char message[30];

    FILE *inputFile = fopen("data.txt", "r");
    FILE *outputFile = fopen("response.txt", "w");

    fprintf(outputFile, "LANDING AUTHORIZATION\n");
    fprintf(outputFile, "=========================================\n");
    fprintf(outputFile, "FLIGHT  FROM\n\n");

    while (fscanf(inputFile, "%s ", message) != EOF)
    {
        fscanf(inputFile, "%d ", &flight);
        fgets(from, 30, inputFile);
        if (strcmp(message, "landing_attempt") == 0)
        {
            if (urgency > 0)
            {
                urgency--;
            }

            start = insert(start, from, flight);
        }
        else if (strcmp(message, "runway_ready") == 0)
        {
            if (start == NULL)
            {
                fprintf(outputFile, "0000    No Airplane Landing\n");
            }
            else
            {
                fprintf(outputFile, "%.4d    %s", start->flight, start->from);
                start = remover(start);
            }
        }
        else if (strcmp(message, "urgency") == 0)
        {
            urgency++;
            start = changePosition(start, flight, urgency);
        }
    }

    fprintf(outputFile, "\nQueue Status \n\n");

    if (start == NULL)
    {
        fprintf(outputFile, "-- Empty Queue --\n");
    }
    else
    {
        while (start != NULL)
        {
            fprintf(outputFile, "%.4d    %s", start->flight, start->from);
            start = remover(start);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
