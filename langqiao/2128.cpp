// 重新排序

// 问题描述
// 给定一个数组 A 和一些查询 Li, Ri，求数组中第 Li 至第 Ri 个元素之和。

// 小蓝觉得这个问题很无聊, 于是他想重新排列一下数组, 使得最终每个查询结果的和尽可能地大。
// 小蓝想知道相比原数组, 所有查询结果的总和最多可以增加多少?

// 输入格式
// 输入第一行包含一个整数 n。

// 第二行包含 n 个整数 A1, A2, ⋯, An，相邻两个整数之间用一个空格分隔。

// 第三行包含一个整数 m 表示查询的数目。

// 接下来 m 行, 每行包含两个整数 Li、Ri，相邻两个整数之间用一个空格分隔。

// 输出格式
// 输出一行包含一个整数表示答案。

// 样例输入
// 5
// 1 2 3 4 5
// 2
// 1 3
// 2 5

// 样例输出
// 4

// 样例说明
// 原来的和为 6 + 14 = 20, 重新排列为 (1, 4, 5, 2, 3) 后和为 10 + 14 = 24, 增加了 4。

// 评测用例规模与约定
// 对于 30% 的评测用例，n, m ≤ 50;
// 对于 50% 的评测用例, n, m ≤ 500;
// 对于 70% 的评测用例, n, m ≤ 5000;
// 对于所有评测用例, 1 ≤ n, m ≤ 10^5, 1 ≤ Ai ≤ 10^6, 1 ≤ Li ≤ Ri ≤ 10^6。


#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);
    i64 n;
    cin >> n;

    vector<i64> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<i64> cnt(n + 1);
    vector<i64> dcnt(n + 1);

    int m;

    cin >> m;

    for (int i = 0; i < m; i++) {
        int l, r;

        cin >> l >> r;

        dcnt[l] += 1;
        if (r + 1 <= n) {
            dcnt[r + 1] -= 1;
        }

    }

    cnt[1] = dcnt[1];
    for (int i = 2; i <= n; i++) {
        cnt[i] = cnt[i - 1] + dcnt[i];
    }

    i64 ans1 = 0;
    for (int i = 1; i <= n; i++) {
        ans1 += cnt[i] * a[i];
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << dcnt[i] << ' ';
    // }


    sort(cnt.begin() + 1, cnt.end(), greater<i64>());

    sort(a.begin() + 1, a.end(), greater<i64>());

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[i] * a[i];
    }
    cout << ans - ans1;
    return 0;

}
