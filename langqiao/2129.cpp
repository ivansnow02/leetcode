// 技能升级

// 问题描述
// 小蓝最近正在玩一款 RPG 游戏。他的角色一共有 N 个可以加攻击力的技能。

// 其中第 i 个技能首次升级可以提升 Ai 点攻击力, 以后每次升级增加的点数都会减少 Bi。
// Ai / Bi 次之后, 再升级该技能将不会改变攻击力。

// 现在小蓝可以总计升级 M 次技能, 他可以任意选择升级的技能和次数。请你计算小蓝最多可以提高多少点攻击力?

// 输入格式
// 输入第一行包含两个整数 N 和 M。

// 以下 N 行每行包含两个整数 Ai 和 Bi。

// 输出格式
// 输出一行包含一个整数表示答案。

// 样例输入
// 3 6
// 10 5
// 9 2
// 8 1

// 样例输出
// 47

// 评测用例规模与约定
// 对于 40% 的评测用例, 1 ≤ N, M ≤ 1000;

// 对于 60% 的评测用例, 1 ≤ N ≤ 10^4, 1 ≤ M ≤ 10^7;

// 对于所有评测用例, 1 ≤ N ≤ 10^5, 1 ≤ M ≤ 2 × 10^9, 1 ≤ Ai, Bi ≤ 10^6。


//! 思考升级技能的过程，是每次找攻击力最高的技能。对某个技能，最后一次升级的攻击力，肯定比之前升级的攻击力小，也就是前面的升级都更大。可以设最后一次升级提升的攻击力是mid，对每个技能，若它最后一次能升级mid，那么它前面的升级都更大。所有这样最后能达到mid的技能，它们前面的升级都应该使用。用二分法找到这个mid，另外，升级技能减少的攻击力的过程是一个等差数列，用O(1)次计算即可知道每个技能升级了几次。知道了每个技能升级的次数，就可以计算一共提升了多少攻击力，这就是题目的答案

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;
    vector<i64> A(N + 1), B(N + 1);


    for (int i = 0; i < N ; i++) {
        cin >> A[i] >> B[i];

    }
// 猜一个临界值（叫它 mid）：
// 这个 mid 是说，每次升级增加的攻击力不能比它小。
// 比如 mid = 5，意思是每次升级至少加 5，少于 5 的就不升级了。
    auto upgrade_cnt = [&](i64 mid) {
        i64 cnt = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] < mid) {
                continue;
            }
            cnt += (A[i] - mid) / B[i] + 1;
        }
        return cnt;
    };

    // 升级增加的攻击力
    i64 l = 0, r = 10e6;

    while (l <= r) {
        i64 m = (l + r) >> 1;
        i64 n = upgrade_cnt(m);

        if (n > M) {
            l = m + 1;
        } else if (n < M) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }


    // 升级次数
    i64 cnt = M;
    // 攻击力
    i64 atk = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < r) {
            continue;
        }
        auto t = (A[i] - l) / B[i] + 1;

        if (A[i] - B[i] * (t - 1) == r) {
            // 这个技能每次升级刚好等于R，其他技能更好
            t--;
        }

        atk += (A[i] * 2 - (t - 1) * B[i]) * t / 2;
        cnt -= t;
    }

    cout << atk + cnt * r;

}
