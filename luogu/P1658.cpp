// # P1658 购物

// ## 题目描述

// 你就要去购物了，现在你手上有 $N$
// 种不同面值的硬币，每种硬币有无限多个。为了方便购物，你希望带尽量少的硬币，但要能组合出 $1$ 到 $X$ 之间的任意值。

// ## 输入格式

// 第一行两个数 $X, N$，以下 $N$ 个数，表示每种硬币的面值。

// ## 输出格式

// 最少需要携带的硬币个数，如果无解输出 `-1`。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 20 4
// 1 2 5 10
// ```

// ### 输出 #1

// ```
// 5
// ```

// ## 说明/提示

// 对于 $30\%$ 的数据，满足 $N \le 3$，$X \le 20$；

// 对于 $100\%$ 的数据，满足 $N \le 10$，$X \le 10^3$。

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 X, N;
    cin >> X >> N;

    // 检查是否有面值为1的硬币，这是能够组成任意值的必要条件
    bool hasOne = 0;
    vector<i64> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
        if (coins[i] == 1) {
            hasOne = 1;
        }
    }
    // 如果没有面值为1的硬币，就无法组成任意值，输出-1
    if (!hasOne) {
        cout << -1 << endl;
        return 0;
    }

    // 对硬币面值进行排序，便于后续贪心选择
    sort(coins.begin(), coins.end());

    // s表示当前可以组合出的连续值的上限，初始为1（因为有面值为1的硬币）
    // ans表示需要的最少硬币数量
    i64 s = 1, ans = 0;

    // 贪心策略：每次选择不超过s+1的最大面值硬币
    // 这样可以保证组合出[1,s+v]范围内的所有值
    while (s <= X) {
        // 找到不超过s+1的最大面值硬币
        // lower_bound返回第一个>=s+1的位置，再减1得到<s+1的最大值
        i64 v = coins[lower_bound(coins.begin(), coins.end(), s + 1) - 1 - coins.begin()];
        // 增加一枚硬币
        ans++;
        // 更新可组合的连续值上限
        // 定理：如果可以组合[1,s]内的任意值，再加一个面值v的硬币（v≤s+1）
        // 则可以组合[1,s+v]内的任意值
        s = s + v;
    }

    cout << ans << endl;
}
