#include<bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono; 

long int binary_search(long int arr[],int minm, int maxm,int num)
{
    int mid;
    if (maxm >= minm) { 
        mid = (minm + maxm)/2; 
  
        if (arr[mid] == num) 
            cout<<"Your search result find at position No. :"<< mid; 
  
        else if (arr[mid] > num){ 
            return binary_search(arr, minm, mid - 1, num);} 
  
        else
            return binary_search(arr, mid + 1, maxm, num); 
    } 
    else
	  cout<<"\nSearch Not Found";
}


void linear_search(long int arr[],int n,int num)
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == num)
        {
        	cout<<"\nYour search result found at position No. : "<< i;
		}
	}
}


int main(){
    int minm,maxm,n,num;
    long int arr[100000];
    
    srand(time(0));
    n = 100000;
    
    for( int i=0; i<n; i++)
    {
        arr[i] = i+1;
    }
    minm = 0;
    maxm = n;
    
    num = (rand() % 100000 + 1);

	
	auto start = high_resolution_clock::now(); 
    binary_search(arr,minm,maxm,num);
    auto stop = high_resolution_clock::now(); 
    
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "\nTime taken by Binary Search: "<< duration.count() << " microseconds" << endl; 
    
    auto startL = high_resolution_clock::now(); 
    linear_search(arr,n,num);
    auto stopL = high_resolution_clock::now(); 
    
    auto durationL = duration_cast<microseconds>(stopL - startL); 
    
    cout << "\n\nTime taken by Linear Search: "<< durationL.count() << " microseconds" << endl; 
    
    return 0;
}