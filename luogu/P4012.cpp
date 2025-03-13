// # P4016 负载平衡问题

// ## 题目描述

// $G$ 公司有 $n$ 个沿铁路运输线环形排列的仓库，每个仓库存储的货物数量不等。如何用最少搬运量可以使 $n$
// 个仓库的库存数量相同。搬运货物时，只能在相邻的仓库之间搬运。

// ## 输入格式

// 第一行一个正整数 $n$，表示有 $n$ 个仓库。

// 第二行 $n$ 个正整数，表示 $n$ 个仓库的库存量。

// ## 输出格式

// 输出最少搬运量。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 5
// 17 9 14 16 4
// ```

// ### 输出 #1

// ```
// 11
// ```

// ## 说明/提示

// $1 \leq n \leq 100$。

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 n;

    cin >> n;
    vector<i64> storages(n);

    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> storages[i];
        sum += storages[i];
    }

    auto avg = sum / n;

    // 仔细思考环形均分纸牌问题可以发现一个性质：必定至少有两个相邻的人不需要从别人那里获得纸牌（这是显然的，不妨设这两个人的位置为i和i+1，则环形序列中必定有满足条件a[i]≤Ta[i+1]≥T的两个相邻位置，这样a[i],a[i+1]之间没有交换，a[i]≤T可以从a[i−1]获得纸牌，a[i+1]≥T可以把多的纸牌给a[i+2]）。
    // 于是由上面的性质，我们直接破环成链，枚举相邻的不需要交换纸牌的两人（将其分别放在第一和最后一个位置）。
    // 按开始的序列顺序，像普通均分纸牌一样处理出s数组，那么假设枚举的位置为k，则类比普通均分纸牌求法，新的s[i]=s[i]−s[k]（注意s为前缀和），于是ans=∑∣s[i]−s[k]∣，我们套用中学数学知识可知当s[k]为s中位数时，ans最小。于是本题就解决了。

    // 前缀和
    vector<i64> s(n);

    s[0] = storages[0] - avg;
    for (int i = 1; i < n; i++) {
        s[i] = s[i - 1] + (storages[i] - avg);
    }

    i64 ans = 0;
    auto ss = s;
    nth_element(ss.begin(), ss.begin() + n / 2, ss.end());
    auto mid = ss[n / 2];

    // cout << mid << endl;

    for (int i = 0; i < n; i++) {

        ans += abs(mid - s[i]);
    }

    cout << ans << endl;
}
