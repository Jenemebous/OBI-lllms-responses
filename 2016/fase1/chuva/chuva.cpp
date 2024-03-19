#include <iostream>
#include <vector>

using namespace std;

int sectionsCoveredWithWater(const vector<int>& heights) {
    int n = heights.size();
    int waterSections = 0;
    int max_height = 0;

    for (int i = 0; i < n; ++i) {
        if (heights[i] > max_height) {
            max_height = heights[i];
            waterSections++;
        }
    }

    return waterSections;
}

int main() {
    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    int result = sectionsCoveredWithWater(heights);
    cout << result << endl;

    return 0;
}