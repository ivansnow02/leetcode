#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 200005;
int main() {
    ios::sync_with_stdio(false);
    vector<int> nums(MAXN);
    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        nums[i] = x;
    }
    sort(nums.begin(), nums.begin() + N);
    auto l = 0, r = 0; // l is the first num >= nums[i] - C, r is the first num > nums[i] - C
    long long res = 0;
    for (int i = 0; i < N; i++) {
        while (!(nums[l] >= nums[i] - C) && l < N)
            l++;
        while (!(nums[r] > nums[i] - C) && r < N)
            r++;
        if (nums[l] == nums[i] - C) {
            res += r - l;
        }
    }
    cout << res << endl;
    return 0;
}
