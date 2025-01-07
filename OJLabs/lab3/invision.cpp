#include <iostream>
#include <vector>
using namespace std;

long long count(int arr[], int temp[], int left, int mid, int right) {
    int i = left;   
    int j = mid + 1; 
    int k = left;    
    long long inv_count = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); 
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += count(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int n;
    cin >> n;
    int arr[100000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int temp[100000];
    long long inv_count = mergeSort(arr, temp, 0, n - 1);

    cout << inv_count << endl;
    return 0;
}