// # 玉蟾宫

// ## 题目背景

// 有一天，小猫 rainbow 和 freda 来到了湘西张家界的天门山玉蟾宫，玉蟾宫宫主蓝兔盛情地款待了它们，并赐予它们一片土地。

// ## 题目描述

// 这片土地被分成 $N\times M$ 个格子，每个格子里写着 'R' 或者 'F'，R 代表这块土地被赐予了 rainbow，F 代表这块土地被赐予了 freda。

// 现在 freda 要在这里卖萌。。。它要找一块矩形土地，要求这片土地都标着 'F' 并且面积最大。

// 但是 rainbow 和 freda 的 OI 水平都弱爆了，找不出这块土地，而蓝兔也想看 freda 卖萌（她显然是不会编程的……），所以它们决定，如果你找到的土地面积为 $S$，它们每人给你 $S$ 两银子。

// ## 输入格式

// 第一行两个整数 $N$，$M$，表示矩形土地有 $N$ 行 $M$ 列。

// 接下来 $N$ 行，每行 $M$ 个用空格隔开的字符 'F' 或 'R'，描述了矩形土地。

// ## 输出格式

// 输出一个整数，表示你能得到多少银子，即 ($3\times \text{最大 'F' 矩形土地面积}$) 的值。

// ## 样例 #1

// ### 样例输入 #1

// ```
// 5 6
// R F F F F F
// F F F F F F
// R R R F F F
// F F F F F F
// F F F F F F
// ```

// ### 样例输出 #1

// ```
// 45
// ```

// ## 提示

// 对于 $50\%$ 的数据，$1 \leq N, M \leq 200$。
// 对于 $100\%$ 的数据，$1 \leq N, M \leq 1000$。

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, M;

    cin >> N >> M;

    vector<vector<char>> land(N, vector<char>(M));
    vector<vector<int>> h(N, vector<int>(M, 1)); // 悬线高度， 如果同一列上一行格子不是障碍，h[i][j] = h[i-1][j] + 1
    vector<vector<int>> l(N, vector<int>(M)); // 往左可以找到的最远的非障碍格的列坐标
    vector<vector<int>> r(N, vector<int>(M)); // 往右可以找到的最远非障碍格的列坐标

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> land[i][j];

            r[i][j] = l[i][j] = j;
        }

        // l
        for (int j = 1; j < M; j++) {
            if (land[i][j] == 'F' && land[i][j - 1] == 'F') {
                l[i][j] = l[i][j - 1];
            }
        }

        // r
        for (int j = M - 2; j >= 0; j--) {
            if (land[i][j] == 'F' && land[i][j + 1] == 'F') {
                r[i][j] = r[i][j + 1];

            }
        }
    }

    // h
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i > 0 && land[i][j] == 'F') {
                if (land[i - 1][j] == 'F') {
                    h[i][j] = h[i - 1][j] + 1;
                    l[i][j] = max(l[i][j], l[i - 1][j]);
                    r[i][j] = min(r[i][j], r[i - 1][j]);
                }
                ans = max((r[i][j] - l[i][j] + 1) * h[i][j], ans);
            }
        }
    }

    cout << 3*ans<<endl;


}
