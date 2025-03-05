// 题目描述
// 在一个高度为H的箱子前方，有一个长和高为N的障碍物。
// 障碍物的每一列存在一个连续的缺口，第i列的缺口从第l各单位到第h个单位（从底部由0开始数）。
// 现在请你清理出一条高度为H的通道，使得箱子可以直接推出去。
// 请输出最少需要清理的障碍物面积。
// 如下图为样例中的障碍物，长和高度均为5，箱子高度为2。（不需要考虑箱子会掉入某些坑中）


// 最少需要移除两个单位的障碍物可以造出一条高度为2的通道。

// 输入格式
// 输入第一行为两个正整数N和H，表示障碍物的尺寸和箱子的高度，1≤H≤N≤1000000。
// 接下来N行，每行包含两个整数li和hi，表示第i列缺口的范围，0≤li≤hi<N。
// 输出格式
// 输出一个数字表示答案。
// 输入样例 复制
// 5 2
// 2 3
// 1 2
// 2 3
// 1 2
// 2 3
// 输出样例 复制
// 2

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 H, N;
    cin >> N >> H;

    vector<i64> d(N), a(N), sum(N + 1);

    for (int i = 0; i < N; i++) {
        i64 l, h;

        cin >> l >> h;

        d[l]++;
        if (h + 1 < N) {
            d[h + 1]--;
        }
    }
    a[0] = d[0];

    for (int i = 1; i < N; i++) {

        a[i] = a[i - 1] + d[i];
    }

    // for (auto x: a) {
    //     cout << x << endl;
    // }

    for (int i = 0; i < N; i++) {
        sum[i + 1] = sum[i] + a[i];
    }

    // for (auto x: sum) {
    //     cout << x << endl;

    // }
    i64 maxs = numeric_limits<i64>::min();

    for (int i = 0; i + H < N; i++) {
        auto curs = sum[i + H] - sum[i];

        // cout << curs << endl;

        if (curs > maxs) {
            maxs = curs;
        }
    }

    cout << H * N - maxs;


}
