// 问题描述
// 有一根长度为 len 的横向的管道，该管道按照单位长度分为 len 段，每一段的中央有一个可开关的阀门和一个检测水流的传感器。

// 一开始管道是空的，位于 Li 的阀门会在 Si 时刻打开，并不断让水流入管道。

// 对于位于 Li 的阀门，它流入的水在 Ti (Ti ≥ Si) 时刻会使得从第 Li − (Ti − Si) 段到第 Li + (Ti − Si) 段的传感器检测到水流。

// 求管道中每一段中间的传感器都检测到有水流的最早时间。

// 输入格式
// 输入的第一行包含两个整数 n, len，用一个空格分隔，分别表示会打开的阀门数和管道长度。

// 接下来 n 行每行包含两个整数 Li, Si，用一个空格分隔，表示位于第 Li 段管道中央的阀门会在 Si 时刻打开。

// 输出格式
// 输出一行包含一个整数表示答案。

// 样例输入
// 3 10
// 1 1
// 6 5
// 10 2

// 样例输出
// 5

// 评测用例规模与约定
// 对于 30% 的评测用例，n ≤ 200，Si, len ≤ 3000；
// 对于 70% 的评测用例，n ≤ 5000，Si, len ≤ 10^5；
// 对于所有评测用例，1 ≤ n ≤ 10^5，1 ≤ Si, len ≤ 10^9，1 ≤ Li ≤ len，Li−1 < Li。

#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 n, len;

    cin >> n >> len;
    vector<i64> L(n + 1), S(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> L[i] >> S[i];
    }

    // 对于位于 Li 的阀门，它流入的水在 Ti (Ti ≥ Si) 时刻会使得从第 Li − (Ti − Si) 段到第 Li + (Ti − Si)
    // 段的传感器检测到水流。

    auto cover_n = [&](i64 t) {
        i64 ans = 0, lastR = -1;
        vector<pair<i64, i64>> range;

        for (int i = 0; i < n; i++) {
            if (t > S[i]) {
                range.emplace_back(make_pair(L[i] - (t - S[i]), L[i] + (t - S[i])));
            }
        }
        for (const auto &x: range) {
            if (x.second >= lastR) {
                ans += x.second - max(lastR, x.first) + 1;
                lastR = x.second + 1;
            }
        }
        //  cout << "ans:\t" << ans << endl;
        return ans;
    };

    i64 l = 0, r = 10e10;

    while (l <= r) {
        auto mid = (l + r) >> 1;

        auto nn = cover_n(mid);

        if (nn >= len) {
            r = mid - 1;
        } else if (nn < len) {
            l = mid + 1;
        }
    }

    cout << l << endl;
}
