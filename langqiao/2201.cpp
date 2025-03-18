// 问题描述
// 这天，小明在搬砖。

// 他一共有 n 块砖, 他发现第 i 砖的重量为 w_i, 价值为 v_i。
// 他突然想从这些砖中选一些出来从下到上堆成一座塔, 并且对于塔中的每一块砖来说,
// 它上面所有砖的重量和不能超过它自身的价值。

// 他想知道这样堆成的塔的总价值（即塔中所有砖块的价值和）最大是多少。

// 输入格式
// 输入共 n + 1 行, 第一行为一个正整数 n, 表示砖块的数量。
// 后面 n 行, 每行两个正整数 w_i, v_i 分别表示每块砖的重量和价值。

// 输出格式
// 一行, 一个整数表示答案。

// 样例输入
// 5
// 4 4
// 1 1
// 5 2
// 5 5
// 4 3

// 样例输出
// 10

// 样例说明
// 选择第 1、2、4 块砖, 从上到下按照 2、1、4 的顺序堆成一座塔, 总价值为 4 + 1 + 5 = 10

// 评测用例规模与约定
// 对于 20% 的数据, 保证 n ≤ 10;
// 对于 100% 的数据, 保证 n ≤ 1000; w_i ≤ 20; v_i ≤ 20000。

#include <bits/stdc++.h>
#include <vector>

using namespace std;

using i64 = long long;

struct Brick {
    i64 w, v;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 n;
    i64 sumW = 0;

    cin >> n;

    vector<Brick *> bricks(n + 1);


    for (int i = 1; i <= n; i++) {
        bricks[i] = new Brick();
        cin >> bricks[i]->w >> bricks[i]->v;
        sumW += bricks[i]->w;
    }

    sort(bricks.begin() + 1, bricks.end(), [](auto a, auto b) {
        return a->w + a->v < b->w + b->v; });



    // dp[j]: the max value j can contain when have already found 0 ~ i bricks
    vector<i64> dp(sumW + 1);

    i64 ans = 0;



    for (int i = 1; i <= n; i++) {
        for (int j = sumW; j >= bricks[i]->w; j--) {

            // the sum of the bricks' weight above should not be greater than its value
            if (j - bricks[i]->w > bricks[i]->v) {
                continue;
            }
            dp[j] = max(dp[j - bricks[i]->w] + bricks[i]->v, dp[j]);

            ans = max(ans, dp[j]);
        }
    }

    cout << ans << endl;


    // // Debug: print the dp array
    //     for (int j = 0; j <= sumW; j++) {
    //         cout << dp[j] << "  ";
    //     }
    //     cout << endl;




}
