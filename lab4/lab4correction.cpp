/*
@This program is to find the minimum total penalty for the trip with giving the distance between each hotel
@postcondition: return the minimum total penalty
@Last modyfy time: April 28
*/
#include <iostream>
#include <vector>
using namespace std;

/*
@This function is to find the minimum total penalty for the trip with giving the distance between each hotel
@precondition: hotels is a vector that stores the distance between each hotel
@postcondition: return the minimum total penalty
*/
int minTotalPenalty(vector<int>& hotels) {
    int n = hotels.size();
    vector<int> dp(n, 0);

    //The penalty of the first hotel is 0, we don't need to stop at the first hotel
    for (int i = 1; i < n; i++) 
    {
        dp[i] = dp[i - 1] + (200 - (hotels[i] - hotels[i - 1])) * (200 - (hotels[i] - hotels[i - 1])); 
        for (int j = 0; j < i - 1; j++) {
            int penalty = dp[j] + (200 - (hotels[i] - hotels[j])) * (200 - (hotels[i] - hotels[j]));//calculate the penalty
            if (penalty < dp[i]) {
                dp[i] = penalty;//find the minimum penalty
            }
        }
    }

    return dp[n - 1];
}

int main() {
    vector <int> hotels; //store the distance between each hotel
    int distance; //store the distance between each hotel
    int nofHotels; //store the number of hotels
    cout << "Enter how many hotels you have: ";
    cin >> nofHotels;
    cout << "Enter the distance between each hotel: ";
    hotels.push_back(0); // Start point, which is 0
    for (int i = 1; i <= nofHotels; i++) {
        cin >> distance;
        hotels.push_back(distance);
    }

    //calculate the minimum total penalty
    int totalPenalty = minTotalPenalty(hotels);
    cout << "Minimum total penalty: " << totalPenalty << endl;

    return 0;
}