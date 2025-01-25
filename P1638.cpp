// # 逛画展

// ## 题目描述

// 博览馆正在展出由世上最佳的 $m$ 位画家所画的图画。

// 游客在购买门票时必须说明两个数字，$a$ 和 $b$，代表他要看展览中的第 $a$ 幅至第 $b$ 幅画（包含 $a,b$）之间的所有图画，而门票的价钱就是一张图画一元。

// Sept 希望入场后可以看到所有名师的图画。当然，他想最小化购买门票的价格。

// 请求出他购买门票时应选择的 $a,b$，数据保证一定有解。

// 若存在多组解，**输出 $a$ 最小的那组**。

// ## 输入格式

// 第一行两个整数 $n,m$，分别表示博览馆内的图画总数及这些图画是由多少位名师的画所绘画的。

// 第二行包含 $n$ 个整数 $a_i$，代表画第 $i$ 幅画的名师的编号。

// ## 输出格式

// 一行两个整数 $a,b$。

// ## 样例 #1

// ### 样例输入 #1

// ```
// 12 5
// 2 5 3 1 3 2 4 1 1 5 4 3
// ```

// ### 样例输出 #1

// ```
// 2 7
// ```

// ## 提示

// #### 数据规模与约定

// - 对于 $30\%$ 的数据，有 $n\le200$，$m\le20$。
// - 对于 $60\%$ 的数据，有 $n\le10^5$，$m\le10^3$。
// - 对于 $100\%$ 的数据，有 $1\leq n\le10^6$，$1 \leq a_i \leq m\le2\times10^3$。

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    vector<int> a(n + 1), sum(m + 1);

    for (int i = 1; i <= n; i++) {

        cin >> a[i];
    }

    int l = 1, r = 1;
    long long cnt = 0;
    int ans = numeric_limits<int>::max(), ansL, ansR;

    while (l <= r && r <= n + 1 && l > 0) {
        // 先往右扩展到包含所有画家
        if (cnt < m) {
            r++;
            if (sum[a[r - 1]]++ == 0) {
                cnt++;
            }
        } else {
            // 判断是否是最小花费
            if (ans > r - l) {
                ans = r - l;
                ansR = r - 1;
                ansL = l;
            }
            // 移动左指针
            if (--sum[a[l]] == 0)
                cnt--;
            l++;

        }

    }

    cout << ansL << ' ' << ansR << endl;
    return 0;
}
