// 题目描述
// 给你一个1-n的排列，每个<i,j>对的价值是j-i+1，计算所有满足以下条件<i,j>对的总价值：
// 1≤i<j≤n
// a[i]-a[j]之间的数字均小于min(a[i],a[j])
// a[i]-a[j]之间不存在其他数字则直接满足
// 输入格式
// 输入第一行包含正整数N(N≤300000)
// 第二行包含N个正整数，表示一个1-N的排列a
// 输出格式
// 输出一个正整数表示答案。
// 输入样例 复制
// 7
// 4 3 1 2 5 6 7
// 输出样例 复制
// 24

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
stack<int64> st;

int64 N;



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> N;
    vector<int64> nums(N + 1);


    int64 ans = 0;

    for (int64 i = 1; i <= N; i++) {
        cin >> nums[i];
    }

    for (int64 i = 1; i <= N; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
            if (!st.empty()) {
                ans += i - st.top() + 1;
            }
        }
        st.emplace(i);
    }

    ans += (N - 1) * 2;
    cout << ans << endl;
}
