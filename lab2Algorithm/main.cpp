/* Starter code for lab2
 */


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "util.h"
#include <cstdlib>
#include <string>
#include <string.h>
#include "doctest.h"


using namespace std;


TEST_CASE("lab2") {


  SUBCASE("binary search") {
    vector<int> input1{2,4,8,12,20,30};
    int output1 = BinarySearch (input1,0, input1.size()-1, 1);

    CHECK (output1==0);

    int output2 =  BinarySearch (input1,0, input1.size()-1, 8);
    CHECK (output2==2);


    int output3 = BinarySearch (input1,0, input1.size()-1, 18);
    CHECK (output3==4);
  }

  SUBCASE("insertion sort") {
        vector<int> input1{3,2,4,8,12,1,5};
        vector<int> expected_output1{1,2,3,4,5,8,12};

        InsertionSort (input1);

        CHECK (input1==expected_output1);
  }

  SUBCASE("recursive insertionsort") {
        vector<int> input1{3,2,4,8,12,1,5};
        vector<int> expected_output1{1,2,3,4,5,8,12};

        InsertionSort (input1,0,input1.size()-1);

        CHECK  (input1==expected_output1);
  }

 SUBCASE ("quicksort") {
        vector<int> input1{3,2,4,8,12,1,5};
        vector<int> expected_output1{1,2,3,4,5,8,12};
        QuickSort (input1, 0, input1.size()-1);
        CHECK (input1==expected_output1);

        vector<int> input2{1,2,3,4,5,8,12};
        vector<int> expected_output2{1,2,3,4,5,8,12};
        QuickSort (input2, 0, input1.size()-1);
        CHECK (input2==expected_output2);

        vector<int> input3{3,2,4,8,12,1,5};
        vector<int> expected_output3{1,2,3,4,8,12,5};
        QuickSort(input3,0,input3.size()-2);

        CHECK (input3==expected_output3);

  }

  SUBCASE ("selection") {
        vector<int> input1{3,2,4,8,12,1,5};
        int output = Selection (input1, 0, input1.size()-1, 1);
        CHECK (output==1);

        output = Selection (input1, 0, input1.size()-1, 3);
        CHECK (output==3);

        output = Selection (input1, 0, input1.size()-1, 6);
        CHECK (output==8);

  }
 SUBCASE("distinct"){
        vector<int> input1{3,2,4,8,2,2,3};
        vector<int> expected_output{3,2,4,8};
        vector<int> output1 = Distinct (input1);
        CHECK (output1==expected_output);


        vector<int> input2{3,3,2,4,4,4,8,2,2,3};
        vector<int> expected_output2{3,2,4,8};
        vector<int> output2 = Distinct (input2);

        CHECK (output2==expected_output2);
  }

  SUBCASE ("sameset"){
       vector<int> v1{3,2,4,2};
        vector<int> v2{2,3,4};
        CHECK (SameSet (v1,v2)==true);

        vector<int> v3{3,1,4,2};
        vector<int> v4{2,3,4};
        CHECK (SameSet (v3,v4)==false);

        vector<int> v5;
        vector<int> v6{2,3,4};
        CHECK (SameSet (v5,v6)==false);
  }
}

