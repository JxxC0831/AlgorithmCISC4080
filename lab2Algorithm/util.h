/* declare all util functions */
#include <vector>
#include <unordered_map>
using namespace std;

int BinarySearch (const vector<int> & list, int first, int last, int v);

//iterative Insertion sort
void InsertionSort (vector<int> & list);

//Recursive Insertion Sort
void InsertionSort (vector<int> & list, int, int);

//QuickSort
int partition(vector<int> &list, int left, int right);// partition function

void QuickSort(vector<int> & list, int left, int right);

int Selection (vector<int> & list, int left, int right, int k);

vector<int> Distinct(vector<int> & list);

bool SameSet (const vector<int> & list1, const vector<int> & list2);

