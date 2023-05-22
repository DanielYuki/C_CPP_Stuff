# Read and Write External Files in C++

This code demonstrates how to read data from a text file and write data to a new file using C++. The code includes two functions: `readText()` and `createFile()`.
The `readText()` function reads data from a file, while the `createFile()` function creates a new file and writes data to it.

## Read Data from a Text File
Look at this example:

1. Include the necessary headers:
```cpp
#include <fstream>
#include <sstream>
```

2. Implement the `readText()` function:
```cpp
void readText()
{
    char line[100];
    ifstream file("NewYork.txt");

    // Skip the first 5 lines in the file
    for (int i = 0; i < 5; i++)
    {
        file.getline(line, 100);
    }

    for (int i = 0; i < numLinesToRead; i++)
    {
        file.getline(line, 100);

        istringstream iss(line);
        string token;

        if (getline(iss, token, ' '))
        {
            someVariable = stod(token); //converts a string to double
        }
    }

    // Skip one line in the file
    file.getline(line, 100);

    for (int i = 0; i < numPoints; i++)
    {
        file.getline(line, 100);
        anotherVariable = atoi(line); //converts a string to int
    }

    file.close();
}
```
In this example, this function opens the file named "NewYork.txt"

## Create and Write Data to a File
To create a file and write data to it, look at this example:

1. Include the necessary headers:
```cpp
#include <fstream>
#include <iostream>
#include <iomanip> //setprecision() function
```

2. Implement the `createFile()` function:
```cpp
void createFile()
{
    ofstream file("data.txt"); // Open a file named "data.txt" for writing

    if (file.is_open())
    { // Check if the file was successfully opened
        for (int i = 0; i < N; i++)
        {
            file << "\n"
                 << fixed << setprecision(6) <<"Write something"<< "\n";
            file << "Write anything"<< "\n";
        }
        file.close(); // Close the file
        cout << "File created successfully." << endl;
    }
    else
    {
        cout << "Failed to create the file." << endl;
    }
}
```
In this example, this function opens a file named "data.txt" for writing and checks if the file was successfully opened. 

## Conclusion
This example demonstrates how to read data from a text file and write data to a new file in C++. By following the provided steps and code snippets, you can easily incorporate file input/output functionality into your own C++ programs.

### Obs:
The `NewYork.txt` file, in this example, is something like this:
```
NAME : NewYork
TYPE : MCLP
EDGE_WEIGHT_TYPE : COORD
DIMENSION : 2713
NODE_COORD_SECTION	
40.6899138 -074.0453133
40.7140465 -073.9861951
40.7123064 -073.9858950
DEMAND_SECTION
2
988
1344
EOF
```