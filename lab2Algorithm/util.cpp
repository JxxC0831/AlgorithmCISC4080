/*
@file util.cpp
@Author: Jiaxuan Cao
@Last modify time: Mar 9
@Known bug: unknown
*/
#include <iostream>
#include "util.h"
#include <vector>
#include <unordered_set>
/* Implement all util functions */


/* Search for v in list[first...last]. If v appears in the sublist, return the index 
 * of its appearance; if v does not appear in the sublist, return the insert location
 * if v=[2,4,5,7,9], first=0, last=4, v=8, the function return 4
 * if v=[2,4,5,7,9], first=0, last=4, v=1, the function return 0
 * if v=[2,4,5,7,9], first=3, last=4, v=7, the function returns 3
 @param list: a vector of int, sorted in ascending order
 @param first, last: specify the range of vector where we search v in
 @param v: the value we are searching for
 @return: the index or insert location
 */

// running time: O(logn)
int BinarySearch (const vector<int> & list, int first, int last, int v)
{
	//base case
	//if this is a empty list or only one element, return the insert location
	if(first >= last)
	{
		//if the only value is less than target value, return the next index
		if(list[first] < v)
		{
			return first+1;
		}
		//smaller than taget value, return the current index
		else
		{
			return first;
		}
	}


	//general case
	int mid = (first + last) / 2;

	//if the middle value is less than target value, search the right half
	if(list[mid] < v)
	{
		return BinarySearch(list, mid+1, last, v);
	}
	//if the middle value is greater than target value, search the left half
	else if(list[mid] > v)
	{
		return BinarySearch(list, first, mid-1, v);
	}
	//if the middle value is equal to target value, return the index
	else
	{
		return mid;
	}
}

// You are required to use BinarySearch in your implementation of InsertionSort 
//running time: O(n^2)
void InsertionSort (vector<int> & list)
{
	for(int i = 1; i < list.size(); i++)
	{
		int target = list[i];
		int j = i - 1;

		//find the insert location using binary search
		int index = BinarySearch(list, 0, j, target);

		//shift the elements to the right
		while(j >= index)
		{
			list[j+1] = list[j];
			j--;
		}
		//insert the target value into the right spot
		list[j+1] = target;
	}


}

//Recursive Insertion Sort to sort list[first...last] recursively
//You need to use BinarySearch 
//running time: O(n^2)
void InsertionSort (vector<int> & list, int first, int last)
{
	//base case
	//if the list is empty or has only one element, means sorted
	if(first >= last)
	{
		return;
	}

	//general case
	//sort from first to last - 1, recursively
	InsertionSort(list, first, last-1);
	//inser the last element into right spot using binary search
	int target = list[last];
	int index = BinarySearch(list, first, last-1, target);

	//shift the elements to the right
	for(int i = last; i > index; i--)
	{
		list[i] = list[i-1];
	}
	list[index] = target;
}
// partition function 
//running time: O(n)
int partition(vector<int> &list, int left, int right)
{
	//choose the last element as pivot
	int pivot = list [right];
	//use i and j to trace the list
	int i = left-1;

	for(int j = left; j < right; j++)
	{
		//if the value is less than pivot, swap it with the value at i+1
		if(list[j] < pivot)
		{
			i++;
			swap(list[i], list[j]);
		}
	}
	//swap the pivot with the value at i+1
	swap(list[i+1], list[right]);
	return i+1;
}

//running time: O(nlogn)
void QuickSort(vector<int> & list, int left, int right)
{
	//base case
	if(left >= right)
	{
		return;
	}
	//general case
	int p = partition(list, left, right);
	//sort the left half and right half
	QuickSort(list, left, p - 1);
	QuickSort(list, p + 1, right);

}

//Return the k-th smallest element in list[left...right]
//k=1, ... right-left+1 
// if k=1, reuturn the smallest value;
// if k=2, return the second smallest value,...
// if k=right-left+1, return the largest value in list[left...right]

//running time: O(n)
int Selection (vector<int> & list, int left, int right, int k)
{
	//base case
	if(left >= right)
	{
		return list[left];
	}

	int p = partition(list, left, right);
	int length = p - left + 1;

	//general case
	if(k == length)
	{
		return list[p];
	}
	else if(k < length)
	{
		return Selection(list, left, p - 1, k);
	}
	else
	{
		return Selection(list, p + 1, right, k - length);
	}

}

//running time: O(n)
vector<int> Distinct(vector<int> & list)
{
	vector<int> result;
	//use set to store the distinct values
	unordered_set<int> distinctlist;
	for(int i=0; i< list.size(); i++)
	{
		if(distinctlist.find(list[i]) == distinctlist.end())//check each value, if it is first time show up, add it into the set and push to result
		{
			distinctlist.insert(list[i]);
			result.push_back(list[i]);
		}
	}
	return result; 
}


//running time: O(n)
bool SameSet (const vector<int> & list1, const vector<int> & list2)
{
	//Todo by you
	unordered_set<int> set1;//define set1 to store all distinct values in list1
	unordered_set<int> set2;//define set2 to store all distinct values in list2

	//use set to store the distinct values
	for(int i = 0; i < list1.size(); i++)
	{
		if(set1.find(list1[i]) == set1.end())
		{
			set1.insert(list1[i]);
		}

	}
	//use set to store the distinct values
	for(int j = 0; j < list2.size();j++)
	{
		if(set2.find(list2[j]) == set2.end())
		{
			set2.insert(list2[j]);
		}
	}
	
	return set1 == set2; //compare the two sets, if they are the same, return true, otherwise return false

}






