// 全球变暖

// 题目描述
// 你有一张某海域 NxN 像素的照片，"."表示海洋、"#"表示陆地，如下所示：

// .......
// .##....
// .##....
// ....##.
// ..####.
// ...###.
// .......

// 其中"上下左右"四个方向上连在一起的一片陆地组成一座岛屿。例如上图就有 2 座岛屿。

// 由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。

// 例如上图中的海域未来会变成如下样子：

// .......
// .......
// .......
// .......
// ....#..
// .......
// .......

// 请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。

// 输入描述
// 第一行包含一个整数 N (1≤N≤1000)。

// 以下 N 行 N 列代表一张海域照片。

// 照片保证第 1 行、第 1 列、第 N 行、第 N 列的像素都是海洋。

// 输出一个整数表示答案。

// 输入输出样例
// 示例
// 输入
// 7
// .......
// .##....
// .##....
// ....##.
// ..####.
// ...###.
// .......

// 输出
// 1

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
vector<string> mmap;


int N;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

i64 dfs(int xx, int yy, vector<vector<bool>> &vis) {
    if (mmap[xx][yy] == '.' || vis[xx][yy] == true) {
        return 0;
    }
    vis[xx][yy] = true;

    i64 flag = 1;
    for (const auto &dir: dirs) {
        auto x = xx + dir.first;
        auto y = yy + dir.second;

        if (x < 0 || x >= N || y < 0 || y >= N) {
            continue;
        }
        i64 landCnt = 0;
        for (const auto &dir: dirs) {
            auto nx = xx + dir.first;
            auto ny = yy + dir.second;

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }

            if (mmap[nx][ny] == '#') {
                landCnt++;
            }
        }
        if (landCnt == 4) {
            flag = 2;
        }

        flag = max(flag, dfs(x, y, vis));
    }
    return flag;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    cin >> N;
    mmap.resize(N);
    vector<vector<bool>> vis(N, vector<bool>(N));
    for (auto &s: mmap) {
        cin >> s;
    }

    i64 highland = 0, islands = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mmap[i][j] == '#') {
                auto t = dfs(i, j, vis);
                if (t >= 1) {
                    islands++;

                    if (t == 2) {
                        highland++;
                    }
                }
            }
        }
    }
    cout << islands - highland << endl;
}
