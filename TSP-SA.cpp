#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

double totalDistance(const vector<pair<int, int>>& cities, const vector<int>& tour) {
    double distance = 0.0;
    for (int i = 0; i < tour.size() - 1; ++i) {
        int city1 = tour[i];
        int city2 = tour[i + 1];
        distance += sqrt(pow(cities[city1].first - cities[city2].first, 2) + pow(cities[city1].second - cities[city2].second, 2));
    }
    distance += sqrt(pow(cities[tour.back()].first - cities[tour.front()].first, 2) + pow(cities[tour.back()].second - cities[tour.front()].second, 2));
    return distance;
}

vector<int> simulatedAnnealing(vector<pair<int, int>>& cities) {
    int n = cities.size();
    vector<int> currentTour(n);
    for (int i = 0; i < n; ++i) currentTour[i] = i;
    double currentDistance = totalDistance(cities, currentTour);
    double temperature = 10000.0;
    double coolingRate = 0.995;
    srand(42);

    while (temperature > 1) {
        vector<int> newTour = currentTour;
        int city1 = rand() % n;
        int city2 = rand() % n;
        while (city1 == city2) {
            city2 = rand() % n;
        }
        swap(newTour[city1], newTour[city2]);
        double newDistance = totalDistance(cities, newTour);
        double deltaDistance = newDistance - currentDistance;
        if (deltaDistance < 0 || exp(-deltaDistance / temperature) > ((double) rand() / RAND_MAX)) {
            currentTour = newTour;
            currentDistance = newDistance;
        }
        temperature *= coolingRate;
    }
    return currentTour;
}

int main() {
    string fileinput;
    cout<<"Enter file name with extension: ";
    cin>>fileinput;
    ifstream TSP(fileinput);
    if (!TSP) {
        cerr << "Error in opening the given file" << endl;
        return 1;
    }
    vector<pair<int, int>> pairs;
    string line;
    bool readingCoordinates = false;

    while (getline(TSP, line)) {
        if (line.find("NODE_COORD_SECTION")!=string::npos) {
            readingCoordinates = true;
            continue;
        }
        if (line == "EOF") break;
        if (readingCoordinates) {
            int index, x, y;
            istringstream iss(line);
            if (iss >> index >> x >> y) {
                pairs.emplace_back(x, y);
            }
        }
    }
    TSP.close();
    cout << "Number of cities: " << pairs.size() << endl;
    if (pairs.size() < 2) {
        cerr << "Insufficient city data for TSP" << endl;
        return 1;
    }
    vector<int> bestTour = simulatedAnnealing(pairs);
    cout << "Best tour: ";
    for (int city : bestTour) {
        cout << city << " ";
    }
    cout << endl;
    double bestDistance = totalDistance(pairs, bestTour);
    cout << "Best distance: " << bestDistance << endl;
    return 0;
}
