// 问题描述
// 妮妮学姐手头有一个长度为 n 的数组 a，她想进行 k 次操作来取出数组中的元素。每次操作必须选择以下两种操作之一：
// 1. 取出数组中的最大元素。
// 2. 取出数组中的最小元素和次小元素。
// 妮妮学姐希望在进行完 k 次操作后，取出的数的和最小。她感觉有些困难，于是请擅长贪心的你帮助她解决这个问题。

// 输入格式
// 第一行输入两个整数 n 和 k，表示数组长度和操作次数。
// 第二行输入 n 个整数表示数组 a。

// 数据范围保证
// 3 ≤ n ≤ 2 × 10^5，1 ≤ ai ≤ 10^9，1 ≤ k ≤ 99999，2k < n。

// 输出格式
// 样例输入
// 5 1
// 2 5 1 10 6

// 样例输出
// 3

// 说明
// 对于样例，我们通过操作 2 取出 1 和 2 可以获得最小值。

#include <bits/stdc++.h>
#include <limits>
#include <vector>

using namespace std;
using i64 = long long;

vector<i64> init_pre(const vector<i64> &a) {
    i64 n = a.size();
    vector<i64> presum(n + 1, 0);

    for (i64 i = 0; i < n; i++) {
        presum[i + 1] = presum[i] + a[i];
    }

    return presum;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);
    i64 n, k;
    cin >> n >> k;

    vector<i64> a(n);

    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto presum = init_pre(a);

    // for (int i = 0; i < n; i++) {
    //     cout << presum[i] << ' ';
    // }
    auto ans = numeric_limits<i64>::max();

    for (i64 p = 0; p <= k; p++) {
        ans = min(presum[2 * p] + presum[n] - presum[n + p - k], ans);
    }

    cout << ans << endl;
}
