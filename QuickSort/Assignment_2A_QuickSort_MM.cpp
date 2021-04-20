#include<bits/stdc++.h>
using namespace  std;
using namespace std::chrono;

int partition(int arr[], int l, int r, int k);
int kthSmallest(int arr[], int l, int r, int k);
void printArray(int arr[], int size);

void createRandomArray(int arr[], int n)
{
    srand(time(0));
    for (long i = 0; i < n; i++)
    {
        arr[i] = (rand()%100);
    }
}

void quickSort(int arr[], int l, int h, long size)
{
    printArray(arr, size);
    if (l < h)
    {
        int n = h - l + 1;

        int med = kthSmallest(arr, l, h, n / 2);

        int p = partition(arr, l, h, med);

        quickSort(arr, l, p - 1, size);
        quickSort(arr, p + 1, h, size);
    }
}

int findMedian(int arr[], int n)
{
    sort(arr, arr + n);
    return arr[n / 2];
}

int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1;
        int i, median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++)
            median[i] = findMedian(arr + l + i * 5, 5);
        if (i * 5 < n)
        {
            median[i] = findMedian(arr + l + i * 5, n % 5);
            i++;
        }
        int medOfMed = (i == 1) ? median[i - 1] : kthSmallest(median, 0, i - 1, i / 2);

        int pos = partition(arr, l, r, medOfMed);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(&arr[i], &arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
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
    clock_t start, end;
    int arr[] = {8, 7, 4, 5, 1, 3, 2, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    start = clock();
    quickSort(arr, 0, n - 1, n);
    end = clock();
    double duration = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "\nTime taken to sort:" << duration * 1000 << " ms" << endl
         << endl;
    cout << "Sorted array is\n";
    printArray(arr, n);

    cout << "\nEnter the size of Sorted Array: ";
    int size;
    cin >> size;
    int array[size];
    createRandomArray(array, size);

    auto startL = high_resolution_clock::now(); 
    quickSort(array, 0, size - 1, size - 1);
    auto stopL = high_resolution_clock::now();
    auto durationL = duration_cast<microseconds>(stopL - startL); 
    ;
    cout << "\nTime taken to sort:" << durationL.count() << " microseconds" << endl;
 
    cout << "Sorted array is\n";
    printArray(array, n);
    cout << endl;
    return 0;
}
