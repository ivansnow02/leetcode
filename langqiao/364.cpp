// 问题描述
// 一年一度的 "跳石头"比赛又要开始了！
// 这项比赛将在一条笔直的河道中进行，河道中分布着一些巨大岩石。组委会已经选择好了两块岩石作为比赛起点和终点。
// 在起点和终点之间，有 N 块岩石（不含起点和终点的岩石）。
// 在比赛过程中，选手们将从起点出发，每一步跳向相邻的岩石，直至到达终点。

// 为了提高比赛难度，组委会计划移走一些岩石，使得选手们在比赛过程中的最短跳跃距离尽可能长。
// 由于预算限制，组委会至多从起点和终点之间移走 M 块岩石（不能移走起点和终点的岩石）。

// 输入描述
// 输入文件第一行包含三个整数 L，N，M，分别表示起点到终点的距离，起点和终点之间的岩石数，以及组委会至多移走的岩石数。

// 接下来 N 行，每行一个整数，第 i 行的整数 D_i（0 < D_i < L）表示第 i 块岩石与起点的距离。
// 这些岩石按与起点距离从小到大的顺序给出，且不会有两个岩石出现在同一个位置。

// 其中，0 ≤ M ≤ N ≤ 5 × 10^4，1 ≤ L ≤ 10^9。

// 更新：数据于 2024 年 10 月 15 日进行了加强。

// 输出描述
// 输出只包含一个整数，即最短跳跃距离的最大值。

// 输入输出样例
// 示例输入
// 25 5 2
// 2
// 11
// 14
// 17
// 21

// 输出
// 4

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);
    i64 L, M, N;
    cin >> L >> N >> M;
    vector<i64> stone_pos(N);

    for (int i = 0; i < N; i++) {
        cin >> stone_pos[i];
    }

    auto max_remove_num = [&](i64 d) -> i64 {
        i64 removed_cnt = 0, cur_pos = 0;
        for (int i = 0; i < N; i++) {
            if (stone_pos[i] - cur_pos < d) {

                removed_cnt++;
            }
            else {
                cur_pos = stone_pos[i];
            }
        }
        // 最后判断终点与最后保留石头的距离
        if (L - cur_pos < d)
            removed_cnt++;
        return removed_cnt;
    };

    i64 l = 0, r = L; 

    while (l <= r) {
        i64 m = (l + r) >> 1;
        auto num = max_remove_num(m);

        if (num > M) {
            r = m - 1;
        } else if (num < M) {
            l = m + 1;
        } else {
            l = m + 1;
        }
    }

    cout << r << endl;
}
