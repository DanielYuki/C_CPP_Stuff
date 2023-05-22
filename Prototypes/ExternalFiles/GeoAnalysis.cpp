#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

#define R 6378100 // Earth's radius in meters
#define N 2713    // Number of points
#define M_PI 3.14159265358979323846

using namespace std;

struct Point
{
    int index;
    double latitude;
    double longitude;
    int density;
    double maxDist;
    double minDist;
    double meanDist;
    int numBlocksRadius;
    int totalDensityRadius;
};

// Function to read data from a text file
void readText(int numPoints, Point points[])
{
    char line[100];
    ifstream file("NewYork.txt");

    // Skip the first 5 lines in the file
    for (int i = 0; i < 5; i++)
    {
        file.getline(line, 100);
    }

    // Read latitude, longitude, and density for each point
    for (int i = 0; i < numPoints; i++)
    {
        file.getline(line, 100);
        points[i].index = i + 1;

        istringstream iss(line);
        string token;

        if (getline(iss, token, ' '))
        {
            points[i].latitude = stod(token);
        }

        if (getline(iss, token, ' '))
        {
            points[i].longitude = stod(token);
        }
    }

    // Skip one line in the file
    file.getline(line, 100);

    // Read density for each point
    for (int i = 0; i < numPoints; i++)
    {
        file.getline(line, 100);
        points[i].density = atoi(line);
    }

    file.close();
}

// Function to print the data of each point
void printPoints(Point points[])
{
    for (int i = 0; i < N; i++)
    {
        cout << "Index: " << points[i].index << endl;
        cout << "Latitude: " << points[i].latitude << endl;
        cout << "Longitude: " << points[i].longitude << endl;
        cout << "Density: " << points[i].density << endl;
        cout << "Max Distance: " << points[i].maxDist << endl;
        cout << "Min Distance: " << points[i].minDist << endl;
        cout << "Mean Distance: " << points[i].meanDist << endl;
        cout << "Num of blocks in radius: " << points[i].numBlocksRadius << endl;
        cout << "Total Radius Density: " << points[i].totalDensityRadius << endl;
    }
}

// Function to create a file and write the data of each point to it
void createFile(Point points[])
{
    ofstream file("data.txt"); // Open a file named "data.txt" for writing

    if (file.is_open())
    { // Check if the file was successfully opened
        file << "Points Data"
             << "\n";
        for (int i = 0; i < N; i++)
        {
            file << "\n"
                 << fixed << setprecision(6) << "Point index: " << points[i].index << "\n";
            file << "Latitude: " << points[i].latitude << "\n";
            file << "Longitude: " << points[i].longitude << "\n";
            file << "Density: " << points[i].density << "\n";
            file << "Max Distance: " << points[i].maxDist << "\n";
            file << "Min Distance: " << points[i].minDist << "\n";
            file << "Mean Distance: " << points[i].meanDist << "\n";
            file << "Num of blocks in radius: " << points[i].numBlocksRadius << "\n";
            file << "Total Radius Density: " << points[i].totalDensityRadius << "\n";
        }
        file.close(); // Close the file
        cout << "File created successfully." << endl;
    }
    else
    {
        cout << "Failed to create the file." << endl;
    }
}

// Function to calculate statistics based on the distances between points
void dataStatistics(vector<vector<double>> distance, Point points[])
{
    double maxDistance, minDistance, sumDistance, d;
    int numBlocksRadius, totalDensityRadius, higherPointDensity = 0, higherPointDensityIndex;
    for (int i = 0; i < N; i++)
    {
        maxDistance = 0;
        minDistance = 999999;
        sumDistance = 0;

        numBlocksRadius = 1;
        totalDensityRadius = points[i].density;

        for (int j = 0; j < N; j++)
        {
            d = distance[i][j];
            distance[j][i] = distance[i][j];

            if (maxDistance < d)
            {
                maxDistance = d;
            }
            if (d > 0 && minDistance > d)
            {
                minDistance = d;
            }
            sumDistance += d;

            if (d > 0 && d <= 1000)
            {
                numBlocksRadius++;
                totalDensityRadius += points[j].density;
            }
        }

        if (higherPointDensity < totalDensityRadius)
        {
            higherPointDensity = totalDensityRadius;
            higherPointDensityIndex = i + 1;
        }

        points[i].maxDist = maxDistance;
        points[i].minDist = minDistance;
        points[i].meanDist = sumDistance / N - 1;

        points[i].numBlocksRadius = numBlocksRadius;
        points[i].totalDensityRadius = totalDensityRadius;
    }

    // cout << "Higher point density: " << higherPointDensity << endl;
    // cout << "Higher point density index: " << higherPointDensityIndex << endl;
}

// Function to calculate the distances between points and populate the distance matrix
void matrixDist(Point points[])
{
    vector<vector<double>> distance(N, vector<double>(N));

    double lat1, lat2, lon1, lon2, dLat, dLon, a, c, d;

    for (int i = 0; i < N; i++)
    {
        lat1 = points[i].latitude;
        lon1 = points[i].longitude;

        for (int j = i; j < N; j++)
        {
            // Haversine formula to calculate distances between two points (on a globe)
            lat2 = points[j].latitude;
            lon2 = points[j].longitude;

            dLat = (lat2 - lat1) * M_PI / 180;
            dLon = (lon2 - lon1) * M_PI / 180;

            a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) * sin(dLon / 2) * sin(dLon / 2);
            c = 2 * atan2(sqrt(a), sqrt(1 - a));
            d = R * c;

            distance[i][j] = d;
            distance[j][i] = distance[i][j];
        }
    }

    dataStatistics(distance, points);
}

int main()
{
    Point points[N];
    readText(N, points);

    // Uncomment the following line to print the points data
    // printPoints(points);

    matrixDist(points);

    createFile(points);

    return 0;
}
