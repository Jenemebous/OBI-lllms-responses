#include <iostream>
#include <vector>

using namespace std;

int countSubarrays(const vector<int>& sizes, int target) {
    int count = 0;
    int n = sizes.size();
    int sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        sum += sizes[right];
        while (left <= right && sum > target) {
            sum -= sizes[left];
            ++left;
        }
        count += (sum == target);
    }

    return count;
}

int countSubsequences(const vector<int>& sizes, int target) {
    int count = 0;
    int n = sizes.size();
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = i; j < n; ++j) {
            sum += sizes[j];
            if (sum == target)
                ++count;
            else if (sum > target)
                break;
        }
    }

    return count;
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> sizes(N);
    for (int i = 0; i < N; ++i) {
        cin >> sizes[i];
    }

    int subarraysCount = countSubarrays(sizes, D);
    int subsequencesCount = countSubsequences(sizes, D);
    
    cout << subarraysCount + subsequencesCount << endl;

    return 0;
}