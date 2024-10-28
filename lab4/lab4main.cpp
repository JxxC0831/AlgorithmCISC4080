/*
@This program is to find the minimum penalty for a trip with a constraint of 200 miles per day. 
@It will ask the user to enter the total distance of the trip, the number of hotels, and the distance of each hotel from the start point. 
@The program will then calculate the minimum penalty and display the optimal path of stops.
@Date: Apr 25
@Known bugs: None
*/
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int CalculatePenalty(const vector<int> &hotels, vector<int> &parent);
void FindOptimalStops(const vector<int> &hotels, const vector<int> &parent);

int main()
{
    int nofHotels = 0; //number of hotels
    const int maxDistance = 200; //const type, so it won't be changed, maximum distance you travel a day
    int totalDistance = 0; //total distance of your trip

    // Get the total distance
    cout << "Enter the total distance: ";
    cin >> totalDistance;

    // Check if the total distance is within the maximum distance, if so, only one stop is needed
    if(totalDistance <= maxDistance && totalDistance >= 0)
    {
        cout << "You only need one stop at "<< totalDistance << endl;
        return 0;
    }

    // Check if the total distance is less than 0
    while(totalDistance < 0)
    {
        cout << "Your total distance can not be less than 0." << endl;
        cout << "Enter the total distance: ";
        cin >> totalDistance;
    }

    int minimumNumberOfStops = totalDistance % maxDistance;
    // Get the number of hotels
    cout << "Enter the number of hotels: ";
    cin >> nofHotels;
    if(minimumNumberOfStops == 0)
    {
        minimumNumberOfStops = totalDistance / maxDistance;
        while(nofHotels < minimumNumberOfStops)
        {
            cout << "You need at least " << minimumNumberOfStops << " hotels for your trip." << endl;
            cout << "Enter the number of hotels: ";
            cin >> nofHotels;
        }
    }
    else
    {
        minimumNumberOfStops = totalDistance / maxDistance;
        while(nofHotels < minimumNumberOfStops + 1)
        {
            cout << "You need at least " << minimumNumberOfStops + 1 << " hotels for your trip." << endl;
            cout << "Enter the number of hotels: ";
            cin >> nofHotels;
        }
    }
    
    vector<int> hotels;
    //enter the distance of each hotel rom the start point,
    //the distance of each hotel should be greater than the previous one and less than the total distance
    //the distance of the last hotel should be equal to the total distance
    cout << "Enter the distances for each hotel: ";
    hotels.push_back(0); // Start point
    int distance;
    for (int i = 1; i <= nofHotels; i++) 
    {
        cin >> distance;
        hotels.push_back(distance);
        //we start from 1 because the first element is 0
       if (i > 1 && (hotels[i] - hotels[i-1] > maxDistance)) 
       {
            cout << "Hotel " << i << " is too far from hotel " << i-1 << " (maximum you can travel is 200 miles per day)" << endl;
            return 0;
        }
    }
    hotels.push_back(totalDistance);//the last hotel is at the destination
    
    // Ensure the last hotel is at the destination
    if(hotels.back() != totalDistance)
    {
        cout << "The distance of the last hotel should be equal to the total distance." << endl;
        return 0;
    }
    

    // Calculate the minimum penalty
    vector<int> parent(hotels.size(), -1);//initialize the parent vector, the size is the same as the hotels vector, and all the elements are -1
    int penalty = CalculatePenalty(hotels, parent);
    cout << "The minimum penalty is: " << penalty << endl;

    // Find the optimal path of stops
    FindOptimalStops(hotels, parent);
    return 0;
}


/*
@This function is to calculate the minimum penalty for the trip
@two parameters: hotels and parent
@postcondition: return the minimum penalty
@the vector penalties is to store the penalty of each hotel, the vector parent is to store the index of minimum penalty hotel
@it will return the minimum penalty for the trip
*/

int CalculatePenalty(const vector<int> &hotels, vector<int> &parent)
{
    int n = hotels.size();
    vector<int> penalties(n, numeric_limits<int>::max());
    penalties[0] = 0;//we set the beganing penalty is 0
    
    // Dynamic programming to find minimum penalty path within 200 miles
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (hotels[i] - hotels[j] <= 200) 
            {   
                // If the distance between hotels is less than 200 miles, 
                int penalty = (200 - (hotels[i] - hotels[j])) * (200 - (hotels[i] - hotels[j]));
                // find the minimum penalty
                penalties[i] = min(penalties[i], penalties[j] + penalty); 

                // If the penalty is the same, set the parent to current hotel j, which means we found a place with same penalty but closer to the destination/next hotel
                if (penalties[i] == penalties[j] + penalty) 
                {
                    parent[i] = j;
                }
            }
        }
    }
    
    return penalties[n - 1];

}

/*
@This function is to find the optimal path of stops
@two parameters: hotels and parent
@precondition: the parent vector should be initialized with -1, we create a vector path to store the path of stops, and we reverse the path in oder to print the correct order
@postcondition: print the optimal path of stops
@it will print the optimal path of stops
*/
void FindOptimalStops(const vector<int> &hotels, const vector<int> &parent) {
    int current = hotels.size() - 1;
    vector<int> path;
    while (current != -1) 
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());

    cout << "Optimal path of stops: ";
    // Start from 1 to skip the start point, which is 0
    for (int i = 1; i < path.size(); i++) 
    {  
        cout << hotels[path[i]] << " ";
    }
    cout << endl;
}