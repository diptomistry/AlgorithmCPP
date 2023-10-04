/* Dynamic Programming C++ implementation of LIS problem */
#include<bits/stdc++.h> 
using namespace std; 
	
/* lis() returns the length of the longest increasing 
subsequence in arr[] of size n */
int lis( int arr[], int n ) 
{ 
	int lis[n]; 

	lis[0] = 1; 

	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) //arr(maintaings increasing order):larger value at right and lis(make it longest): smaller value at left
				lis[i] = lis[j] + 1; //indexing
	} 

	// Return maximum value in lis[] 
	return *max_element(lis, lis+n); 
} 
	
/* Driver program to test above function */
int main() 
{ 
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Length of lis is %d\n", lis( arr, n ) ); 
	return 0; 
}
//O(n^2)
//https://www.youtube.com/watch?v=mouCn3CFpgg&ab_channel=Techdose