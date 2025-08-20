#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<pair<int, int> > findZeroSumSubarrays(vector<int>& arr) {
    int n = arr.size();
    long long prefix_sum = 0;
    map<long long, vector<int> > prefix_map;
    vector<pair<int, int> > result;

    prefix_map[0].push_back(-1);

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if (prefix_map.find(prefix_sum) != prefix_map.end()) {
            for (int j = 0; j < prefix_map[prefix_sum].size(); j++) {
                int startIdx = prefix_map[prefix_sum][j];
                result.push_back(make_pair(startIdx + 1, i));
            }
        }

        prefix_map[prefix_sum].push_back(i);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<int, int> > subarrays = findZeroSumSubarrays(arr);

    if (subarrays.empty()) {
        cout<<"[]"<<endl;
    } else {
        cout<<"Zero-sum Subarray: ";
        for (int i = 0; i < subarrays.size(); i++) {
            cout<<"("<<subarrays[i].first<<", "<<subarrays[i].second<<") ";
        }
        cout << endl;
    }

    return 0;
}
