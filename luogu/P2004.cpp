// # P2004 领地选择

// ## 题目描述

// 作为在虚拟世界里统帅千军万马的领袖，小 Z 认为天时、地利、人和三者是缺一不可的，所以，谨慎地选择首都的位置对于小 Z
// 来说是非常重要的。

// 首都被认为是一个占地 $C\times C$ 的正方形。小 Z 希望你寻找到一个合适的位置，使得首都所占领的位置的土地价值和最高。

// ## 输入格式

// 第一行三个整数 $N,M,C$，表示地图的宽和长以及首都的边长。

// 接下来 $N$ 行每行 $M$ 个整数，表示了地图上每个地块的价值。价值可能为负数。

// ## 输出格式

// 一行两个整数 $X,Y$，表示首都左上角的坐标。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 3 4 2
// 1 2 3 1
// -1 9 0 2
// 2 0 1 1
// ```

// ### 输出 #1

// ```
// 1 2
// ```

// ## 说明/提示

// 对于 $60\%$ 的数据，$N,M\le 50$。

// 对于 $90\%$ 的数据，$N,M\le 300$。

// 对于 $100\%$ 的数据，$1\le N,M\le 10^3$，$1\le C\le \min(N,M)$。

#include <bits/stdc++.h>
#include <limits>
#include <vector>
using namespace std;
using i64 = long long;

vector<vector<i64>> preSum;

i64 N, M, C;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    cin >> N >> M >> C;
    preSum.resize(N + 1, vector<i64>(M + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            preSum[i + 1][j + 1] = preSum[i + 1][j] + preSum[i][j + 1] + x - preSum[i][j];
        }
    }

    i64 maxSum = numeric_limits<i64>::min();
    int ansi = 0, ansj = 0;

    for (int i = 1; i + C - 1 <= N; i++) {
        for (int j = 1; j + C - 1 <= M; j++) {
            // 计算从 (i,j) 开始的 C×C 区域的和
            auto sum = preSum[i + C - 1][j + C - 1] - preSum[i + C - 1][j - 1] - preSum[i - 1][j + C - 1] +
                       preSum[i - 1][j - 1];
            if (sum > maxSum) {
                maxSum = sum;
                ansi = i;
                ansj = j;
            }
        }
    }

    cout << ansi << ' ' << ansj;
}
