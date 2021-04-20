#include <bits/stdc++.h> 
#include <stdlib.h>
#include<time.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;  


void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

//median of median methods
int partition(int arr1[], int l, int r, int k);
int kthSmallest(int arr1[], int l, int r, int k);
void printArray(int arr1[], int size);

void quickS_MM(int arr[], int l, int h, long size)
{
    //printArray(arr, size);
    if (l < h)
    {
        int n = h - l + 1;

        int med = kthSmallest(arr, l, h, n / 2);

        int p = partition(arr, l, h, med);

        quickS_MM(arr, l, p - 1, size);
        quickS_MM(arr, p + 1, h, size);
    }
}

int findMedian(int arr2[], int n)
{
    sort(arr2, arr2 + n);
    return arr2[n / 2];
}

int kthSmallest(int arr2[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1;
        int i, median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++)
            median[i] = findMedian(arr2 + l + i * 5, 5);
        if (i * 5 < n)
        {
            median[i] = findMedian(arr2 + l + i * 5, n % 5);
            i++;
        }
        int medOfMed = (i == 1) ? median[i - 1] : kthSmallest(median, 0, i - 1, i / 2);

        int pos = partition(arr2, l, r, medOfMed);

        if (pos - l == k - 1)
            return arr2[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr2, l, pos - 1, k);
        return kthSmallest(arr2, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}

int partition(int arr2[], int l, int r, int x)
{
    int i;
    for (i = l; i < r; i++)
        if (arr2[i] == x)
            break;
    swap(&arr2[i], &arr2[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr2[j] <= x)
        {
            swap(&arr2[i], &arr2[j]);
            i++;
        }
    }
    swap(&arr2[i], &arr2[r]);
    return i;
}

//End of Median of Median methods



//creating Random Arrays
void createRandomArray(int arr[], int arr1[], int arr2[], int n)
{
    srand(time(0));
    for (long i = 0; i < n; i++)
    {
        arr[i] = arr1[i] = arr2[i] = (rand()%100);
    }
}


int partition (int arr[], int low, int high) 
{ 
  int pivot = arr[high]; 
  int i = (low - 1);  

  for (int j = low; j <= high - 1; j++) 
  { 
    if (arr[j] < pivot) 
    { 
      i++; 
      swap(&arr[i], &arr[j]); 
    } 
  } 
  swap(&arr[i + 1], &arr[high]); 
  return (i + 1); 
} 


void quickSort(int arr[], int low, int high) 
{ 
  if (low < high) 
  { 
    int pi = partition(arr, low, high); 
    quickSort(arr, low, pi - 1); 
    quickSort(arr, pi + 1, high);
  }
} 

void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
      
    // Last i elements are already in place 
    for (j = 0; j < n-i-1; j++) 
        if (arr[j] > arr[j+1]) 
            swap(&arr[j], &arr[j+1]); 
} 

void printArray(int arr[], int size) 
{ 
  int i; 
  for (i = 0; i < size; i++) 
    cout << arr[i] << " "; 
  cout << endl; 
} 

 
int main() 
{ 
    cout << "\nEnter the size of Sorted Array: ";
    int n;
    cin >> n;
    int arr[n],arr1[n],arr2[n];
    createRandomArray(arr, arr1, arr2, n);
    bubbleSort(arr, n);
    //printArray(arr, n);
  
    auto start = high_resolution_clock::now(); 

    // already SORTED ARRAY
    quickSort(arr, 0, n - 1); 
    cout << "\nSorted array: \n"; 
    printArray(arr, n); 
    
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "\nTime taken by WORST Case (Passed Already SORTED ARRAY): "<< duration.count() << " microseconds" << endl; 
    cout<<"\n=================================================================="<<endl;
    
    // UNSORTED 
    auto startMM = high_resolution_clock::now();
    quickS_MM(arr2, 0, n - 1, n - 1); 
    cout << "\nSorted array: \n"; 
    printArray(arr2, n);
    auto stopMM = high_resolution_clock::now();
    auto durationMM = duration_cast<microseconds>(stopMM - startMM); 
    cout << "\nTime taken by AVERAGE Case (Passed UNSORTED ARRAY): "<< durationMM.count() << " microseconds" << endl; 
    cout<<"\n=================================================================="<<endl;
  
    //MEDIAN OF MEDIAN
    auto startL = high_resolution_clock::now();
    quickSort(arr1, 0, n - 1); 
    cout << "\nSorted array: \n"; 
    printArray(arr1, n);
  
    auto stopL = high_resolution_clock::now(); 
    auto durationL = duration_cast<microseconds>(stopL - startL); 
    cout << "\nTime taken by BEST Case (Median of Median): "<< durationL.count() << " microseconds" << endl; 
    cout<<"\n=================================================================="<<endl;
 
 
  return 0; 
}
