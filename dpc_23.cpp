#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void SlidingWindowMax(const vector<int> &arr, int n, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    for (int i = 0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    cout << "Output: ";
    SlidingWindowMax(arr, n, k);
    cout << endl;

    return 0;
}
