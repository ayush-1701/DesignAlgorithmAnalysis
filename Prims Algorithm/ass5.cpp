#include<bits/stdc++.h>
using namespace  std;
using namespace std::chrono;

void sortit(vector<int> &arr, int l, int m, int r) {
    vector<int> temp;

    int i{l};
    int j{m+1};

    while (i<m+1 && j<r+1) {
        if (arr[i] > arr[j]) {
            temp.push_back(arr[j++]);
        } else {
            temp.push_back(arr[i++]);
        }
    }

    while (i<m+1) {
        temp.push_back(arr[i++]);
    }

    while (j<r+1) {
        temp.push_back(arr[j++]);
    }

    for(int i{0}; i<(r-l+1); i++) {
        arr[l+i] = temp[i];
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l<r) {
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        sortit(arr, l, m, r);
    }
}

int main() {
    chrono::time_point<std::chrono::system_clock> start, end; 

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i{0}; i<n; i++) {
        arr[i] = i+1;
    }

    random_shuffle(arr.begin(), arr.end());
    for(int &x: arr) {
        cout << x << " ";
    }
    cout << endl;

    start = chrono::system_clock::now(); 
    mergeSort(arr, 0, n-1);
    end = chrono::system_clock::now(); 

    for(int &x: arr) {
        cout << x << " ";
    }
    cout << endl;

    chrono::duration<double> elapsed_seconds = end - start; 
    cout << "Time Required by MergeSort (Worst Case): " << fixed << setprecision(10) << elapsed_seconds.count() << endl;
    cout << endl;
}