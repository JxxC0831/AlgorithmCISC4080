//Compile using g++ -std=c++11
#include <iostream>
#include <vector>
#include <algorithm>
#include "coinchange.h"
using namespace std;


int main()
{
   vector<int> coins{2,5,3,10};
   vector<int> used;

   vector<int> values{4, 6,15, 18, 30, 41}; //use this to test

  string command;
  cout <<"Which function do you want to test: oneofakind/kofakind/unlimited ?:";
  cin >> command;

  if (command=="oneofakind"){
         for (auto v: values) {
  	  	if (CoinChange (coins, 0, coins.size()-1, v, used))
   		{
			cout <<"value="<<v <<" True: using";
			PrintVector (used);
			cout <<endl;
   		}
   		else 
			cout <<"Value=" << v<<" False"<<endl;
   	} 
  } else if (command=="kofakind"){  
  	 //Test of K-of-a-kind
        //make 20, k=1 ==> cannot be done
        if (CoinChangeK (coins, 0, coins.size()-1, 20, 1)!=true)
        {
                cout <<"fail coinchangek test case #1\n";
                return 1; //faild coinchangeK test
        }
        else{
                cout <<"pass coinchangek test case #1\n";
                return 0; //pass coinchangeK test
        }


          //Make 9, k=3 ==> can be done
        if (CoinChangeK (coins, 0, coins.size()-1, 9, 2)!=false)
        {
                cout <<"fail coinchangek test case #2\n";
                return 1; //faild coinchangeK test
        }
        else{
                cout <<"pass coinchangek test case $2";
                return 0; //pass coinchangeK test
        }

          //Make 9, k=3 ==> can be done
        if (CoinChangeK (coins, 0, coins.size()-1, 9, 3)!=true)
        {
                cout <<"fail coinchangek test case #3\n";
                return 1; //faild coinchangeK test
        }
        else{
                cout <<"pass coinchangek test case #3";
                return 0; //pass coinchangeK test
        }

  } else if (command=="unlimited"){
   	//Test UnlimitedCoinChange 
	vector<int> bestSolution;

	//Make 1? ==> impossible
   	if (UnlimitedCoinChange (coins, 1,bestSolution)!=false) {
      		cout <<"Failed UnlimitedCoinChange case 1\n";
		return 1; //failed unlimited test 
	}

	//Make 15 ==> yes, best solution is using {5,10} 
   	if (UnlimitedCoinChange (coins, 15, bestSolution)!=true) {
		cout <<"Failed UnlimitedCoinChange case 2\n";
		return 1;
	}
	vector<int> expectedSol{5,10}; 
        sort (bestSolution.begin(), bestSolution.end());
	if (bestSolution!=expectedSol){
		cout <<"Failed UnlimitedCoinChange case 2\n";
		return 1;

	}

	//Make 30 ==> yes, using {10,10,10} is optimal solution
   	if (UnlimitedCoinChange (coins, 30, bestSolution)!=true) {
		cout <<"Failed UnlimitedCoinChange case 3\n";
		return 1;
	}
	vector<int> expectedSol3{10,10,10}; 
        sort (bestSolution.begin(), bestSolution.end());
	if (bestSolution!=expectedSol3){
		cout <<"Failed UnlimitedCoinChange case 3\n";
		return 1;

	}

        cout <<"Pass unlimitedCoinChange cases\n";
        return 0;
  }

}
