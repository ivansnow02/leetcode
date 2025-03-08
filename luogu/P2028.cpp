// # P2082 区间覆盖（加强版）

// ## 题目描述

// 已知有 $N$ 个区间，每个区间的范围是 $[s_i,t_i]$，请求出区间覆盖后的总长。

// ## 输入格式

// 第一行一个正整数 $N$，表示区间个数。

// 接下来 $N$ 行，每行两个正整数，表示 $s_i$ 和 $t_i$。

// ## 输出格式

// 共一行，一个正整数，为覆盖后的区间总长。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 3
// 1 100000
// 200001 1000000
// 100000000 100000001
// ```

// ### 输出 #1

// ```
// 900002
// ```

// ## 说明/提示

// 对于 $40 \%$ 的数据，$N \le 1000$，$1 \le s_i < t_i \le 10000$。

// 对于 $100 \%$ 的数据 ，$N \le 10^5$，$1 \le s_i < t_i \le 10^{17}$。

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;



int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 n;
    cin >> n;

    vector<pair<i64, i64>> intervals(n);

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) { return a.first < b.first; });

    i64 lastR = -1;
    i64 ans = 0;

    for (const auto &x: intervals) {
        if (x.second >= lastR) {
            ans += x.second - max(lastR, x.first) + 1;
            lastR = x.second + 1;
        }
    }

    cout << ans;

}
