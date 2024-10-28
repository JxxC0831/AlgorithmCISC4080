#include<iostream>
#include<vector>
#include<climits>


using namespace std;

int CalculatePenalty(const vector<int> &hotels, vector<int> &parent);
void FindOptimalStops(const vector<int> &hotels, const vector<int> &parent);

int main() {
    int nofHotels = 0;
    const int maxDistance = 200;
    int totalDistance = 0;
    vector<int> hotels;

    // Get the total distance
    cout << "Enter the total distance: ";
    while (!(cin >> totalDistance) || totalDistance <= 0) {
        cout << "Please enter a valid total distance greater than 0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Get the number of hotels
    cout << "Enter the number of hotels: ";
    while (!(cin >> nofHotels) || nofHotels < 0) {
        cout << "Please enter a valid number of hotels: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Ask for the distances of each hotel from the start point
    cout << "Enter the distances for each hotel: ";
    int previous_distance = 0;
    hotels.push_back(0); // Start point
    for (int i = 0; i < nofHotels; i++) {
        int distance;
        while (!(cin >> distance) || distance <= previous_distance || distance > totalDistance) {
            cout << "Invalid distance. Please enter a distance greater than " << previous_distance 
                 << " and up to " << totalDistance << " miles: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        hotels.push_back(distance);
        previous_distance = distance;
    }
    hotels.push_back(totalDistance); // Ensure the last hotel or point is the destination

    vector<int> parent(hotels.size(), -1);
    int penalty = CalculatePenalty(hotels, parent);
    cout << "The minimum penalty is: " << penalty << endl;

    FindOptimalStops(hotels, parent);

    return 0;
}

int CalculatePenalty(const vector<int>& hotels, vector<int>& parent) {
    int n = hotels.size();
    vector<int> penalties(n, numeric_limits<int>::max());
    penalties[0] = 0; // Start with no penalty

    // Dynamic programming to find minimum penalty path with 200 miles constraint
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (hotels[i] - hotels[j] <= 200) {
                int penalty = (200 - (hotels[i] - hotels[j])) * (200 - (hotels[i] - hotels[j]));
                if (penalties[i] > penalties[j] + penalty) {
                    penalties[i] = penalties[j] + penalty;
                    parent[i] = j;
                }
            }
        }
    }
    return penalties[n - 1];
}

void FindOptimalStops(const vector<int> &hotels, const vector<int> &parent) {
    int current = hotels.size() - 1;
    vector<int> path;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());

    cout << "Optimal path of stops: ";
    for (int i = 1; i < path.size(); i++) {  // Start from 1 to skip the start point
        cout << hotels[path[i]] << " ";
    }
    cout << endl;
}
