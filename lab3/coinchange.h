//Compile using g++ -std=c++11
#include <iostream>
#include <vector>
using namespace std;

void PrintVector (const vector<int> & v);

bool CoinChange (vector<int> & L, int first, int last, int value, vector<int> & used);

bool CoinChangeK (const vector<int> & coins, int first, int last, int value, int K);

bool UnlimitedCoinChange (const vector<int> & coins, int value, vector<int>& bestSolution);

