// 题目描述
// n皇后问题：n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 上面布局用序列2 4 6 1 3 5表示，第i个数字表示第i行皇后放的列号。
// 按照这种格式输出前3个解，并统计总解数。
// 输入格式
// 输入一个正整数n，6≤n≤13
// 输出格式
// 前三行，每行n个数字表示一组解。
// 第四行输出总解数。
// 输入样例 复制
// 6
// 输出样例 复制
// 2 4 6 1 3 5
// 3 6 2 5 1 4
// 4 1 5 2 6 3
// 4

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
vector<vector<i64>> res;
i64 N;
vector<vector<bool>> board;
vector<pair<i64, i64>> queens;
bool check(i64 x, i64 y) {
    // // column
    // for (int i = x; i >= 0; i--) {
    //     if (board[i][y]) {
    //         return false;
    //     }
    // }

    // // // row
    // // for (int j = y; j < N; j++) {
    // //     if (board[x][j]) {
    // //         return false;
    // //     }
    // // }

    // // angle
    // for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
    //     if (board[i][j]) {
    //         return false;
    //     }
    // }
    // for (int i = x, j = y; i >= 0 && j < N; i--, j++) {
    //     if (board[i][j]) {
    //         return false;
    //     }
    // }

    // 1 2
    // 3 4

    for (const auto &q: queens) {
        if (x == q.first || y == q.second || abs(q.first - x) == abs(q.second - y)) {
            return false;
        }
    }
    return true;
}
vector<i64> solution;
void dfs(int xx) {
    if (xx >= N) {
        res.emplace_back(solution);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!check(xx, i)) {
            continue;
        }
        // board[xx][i] = true;
        queens.emplace_back(xx, i);
        solution.emplace_back(i + 1);
        dfs(xx + 1);
        solution.pop_back();
        // board[xx][i] = false;
        queens.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    cin >> N;

    // board.resize(N);

    // for (int i = 0; i < N; i++) {
    //     board[i].resize(N);
    // }

    dfs(0);

    for (int i = 0; i < 3; i++) {
        for (auto x: res[i]) {
            cout << x << ' ';
        }
        cout << endl;
    }

    cout << res.size() << endl;
}
