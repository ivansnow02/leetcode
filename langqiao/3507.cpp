// 题目描述
// 给定一个数组 Ai，分别求其每个子段的异或和，并求出它们的和。或者说，对于每组满足 1≤L≤R≤n 的 L, R，求出数组中第 L 至第 R 个元素的异或和。然后输出每组 L, R 得到的结果加起来的值。

// 输入格式
// 输入的第一行包含一个整数 n。

// 第二行包含 n 个整数 Ai，相邻整数之间使用一个空格分隔。

// 输出格式
// 输出一行包含一个整数表示答案。

// 样例输入
// 5
// 1 2 3 4 5

// 样例输出
// 39

// 评测用例规模与约定
// 对于 30% 的评测用例，n≤300；
// 对于 60% 的评测用例，n≤5000；
// 对于所有评测用例，1≤n≤10^5，0≤Ai≤2^20。


// 90

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<i64> a;
vector<i64> pre;
int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);
    i64 n;

    cin >> n;

    a.resize(n);
    pre.resize(n + 1);


    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // pre[i + 1] = pre[i] ^ a[i];
    }

    i64 ans = 0;

    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         ans += pre[j + 1] ^ pre[i];

    //     }
    // }
    for (int L = 0; L < n; L++) {
        i64 sum = 0; // sum是包含a[L]的子段的前缀和
        for (int R = L; R < n; R++) {
            sum ^= a[R]; // 用递推求前缀和sum
            ans += sum; // 累加所有子段和
        }
    }

    cout << ans << endl;


    return 0;
}
