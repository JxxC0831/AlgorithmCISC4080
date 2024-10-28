/*
@ Name: lab1.cpp
@ This program have four sorting functions: bubble sort, selection sort, recursive bubble sort, recursive selection sort. 
@It required user to input the number of elements in the list, the elements in the list, and the sorting method. Then it will print out the sorted list.
@Author: Jiaxuan Cao
@Last modify time: 2024/2/6
@Know bugs: None
*/
#include <iostream>
#include <vector>
using namespace std;

void BubbleSort (vector<int> & a);
void SelectionSort (vector<int> & a);
void RecursiveBubble (vector<int> & a, int last);
void RecursiveSelection (vector<int> & a, int first);

int main()
{
    vector<int> list;
    int element;
    cin >> element;//input the number of elements in the list
    for(int i = 0; i < element; i++)
    {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }

    string HowtoSort;
    cin >> HowtoSort;//input the sorting method

    if(HowtoSort == "bubble")
        BubbleSort(list);
    else if(HowtoSort == "selection")
        SelectionSort(list);
    else if(HowtoSort == "rbubble")
        RecursiveBubble(list, list.size()-1);
    else if(HowtoSort == "rselection")
        RecursiveSelection(list, 0);
    else
        cout << "Invalid input" << endl;

    

    //print out the sorted list
    for(int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    return 0;
}

/* bubble: iterative bubble sort function
@param: vector a
@post-condition: vector a is arranged into ascending order
*/
void BubbleSort (vector<int> & a)
{
    for(int i = 0; i < a.size()-1; i++)
    {
        for(int j = 0; j < a.size()-i-1; j++)
        {
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

/* iterative selection sort function
@param: vector a
@post-condition: vector a is arranged into ascending order 
*/
void SelectionSort (vector<int> & a)
{
    for(int i = 0; i < a.size()-1; i++)
    {
        int min = i;
        for(int j = i; j < a.size(); j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        swap(a[min], a[i]);
    }
}

/* recursive implementation of bubble sort function
@param: vector a
@param: last, specify the range of vector a to be sorted, i.e., a[0…last] is to be sorted
@post-condition: vector a[0…last] is arranged into ascending order
*/
void RecursiveBubble (vector<int> & a, int last)
{
    if(last == 0)
        return;
    for(int i = 0; i < last; i++)
    {
        if(a[i] > a[i+1])
            swap(a[i], a[i+1]);
    }
    RecursiveBubble(a, last-1);
}

/* recursive selection sort function
@param: vector a
@param: first, specify the range of vector a to be sorted, i.e., a[first…n-1] is to be sorted, where
n is the size of vector a
@post-condition: vector a[first…n-1] is arranged into ascending order
*/
void RecursiveSelection (vector<int> & a, int first)
{
    if(first == a.size()-1)
        return;
    int min = first;
    for(int i = first+1; i < a.size(); i++)
    {
        if(a[i] < a[min])
            min = i;
    }
    swap(a[min], a[first]);
    RecursiveSelection(a, first+1);
}
