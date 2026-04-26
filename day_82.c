#include <iostream>
using namespace std;

// Lower Bound: first index where arr[i] >= x
int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n; // default if not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            right = mid - 1; // go left
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

// Upper Bound: first index where arr[i] > x
int upperBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > x) {
            ans = mid;
            right = mid - 1; // go left
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter target value: ";
    cin >> x;

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    cout << lb << " " << ub;

    return 0;
}
