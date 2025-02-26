// 统计数字

// 题目描述
// 某次科研调查时得到了 n 个自然数，每个数均不超过 1.5 × 10^9 。已知不相同的数不超过 10^4 个，现在需要统计这些自然数各自出现的次数，并按照自然数从小到大的顺序输出统计结果。

// 输入描述
// 第 1 行是整数 n，表示自然数的个数。
// 第 2 ~ n+1 行每行一个自然数。
// 其中，1 ≤ n ≤ 2 × 10^5，每个数均不超过 1.5 × 10^9 。

// 输出描述
// 输出 m 行（m 为 n 个自然数中不相同数的个数），按照自然数从小到大的顺序输出。每行输出两个整数，分别是自然数和该数出现的次数，其间用一个空格隔开。

// 输入输出样例
// 示例 1
// 输入
// 8
// 2
// 4
// 2
// 4
// 5
// 100
// 2
// 100

// 输出
// 2 3
// 4 2
// 5 1
// 100 2

#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);
    i64 n;
    map<i64, i64> m;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        m[t]++;
    }

    for (auto x: m) {
        cout << x.first << ' ' << x.second << endl;
    }

}
