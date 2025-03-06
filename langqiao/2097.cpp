// 青蛙过河

// 问题描述
// 小青蛙住在一条河边, 它想到河对岸的学校去学习。小青蛙打算经过河里的石头跳到对岸。

// 河里的石头排成了一条直线, 小青蛙每次跳跃必须落在一块石头或者岸上。不过, 每块石头有一个高度, 每次小青蛙从一块石头起跳,
// 这块石头的高度就会下降 1 , 当石头的高度下降到 0 时小青蛙不能再跳到这块石头上（某次跳跃后使石头高度下降到 0
// 是允许的)。

// 小青蛙一共需要去学校上 x 天课, 所以它需要往返 2x 次。当小青蛙具有一个跳跃能力 y 时, 它能跳不超过 y 的距离。

// 请问小青蛙的跳跃能力至少是多少才能用这些石头上完 x 次课。

// 输入格式
// 输入的第一行包含两个整数 n, x, 分别表示河的宽度和小青蛙需要去学校的天数。请注意 2x 才是实际过河的次数。

// 第二行包含 n−1 个非负整数 H1, H2, ⋯, Hn−1, 其中 Hi > 0 表示在河中与小青蛙的家相距 i 的地方有一块高度为 Hi 的石头, Hi
// = 0 表示这个位置没有石头。

// 输出格式
// 输出一行, 包含一个整数, 表示小青蛙需要的最低跳跃能力。

// 样例输入
// 5 1
// 1 0 1 0

// 样例输出
// 4

// 样例说明
// 由于只有两块高度为 1 的石头，所以往返只能各用一块。第 1 块石头和对岸的距离为 4，如果小青蛙的跳跃能力为 3
// 则无法满足要求。所以小青蛙最少需要 4 的跳跃能力。

// 评测用例规模与约定
// 对于 30% 的评测用例, n ≤ 100;

// 对于 60% 的评测用例, n ≤ 1000;

// 对于所有评测用例, 1 ≤ n ≤ 10^5, 1 ≤ x ≤ 10^9, 1 ≤ Hi ≤ 10^4。

// 运行限制
// 最大运行时间：1s
// 最大运行内存: 512M

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, x;
    cin >> n >> x;
    // 下标 0 为起点，下标 n 为对岸，只有下标 1~n-1 存储石头
    vector<i64> stones(n + 1, 0);
    for (int i = 1; i < n; i++) {
        cin >> stones[i];
    }
    // 这里不需要调整起点和终点的石头高度，因为它们不消耗

    // 预处理前缀和，前缀和仅涵盖 1...n-1 的石头
    vector<i64> prefix(n, 0); // prefix[0] = 0, prefix[i] (i>=1)表示和stones[1..i]
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + stones[i];
    }

    // 检查给定跳跃能力 y是否足够支持 2*x 次过河，
    // 即在所有区间 [j, j+y-1]（1 <= j <= n-y）中，窗口和的最小值是否>= 2*x。
    auto can_cross = [&](int y) -> bool {
        // 若 y > n-1，则没有任何窗口限制（直接可跳到对岸），但题中 y 最大为 n
        int windowCount = n - y; // 窗口起点 j = 1 ... (n-y)
        if (windowCount < 1) {
            return true;
        }
        i64 minFlow = numeric_limits<i64>::max();
        // 枚举所有窗口 [j, j+y-1]，j从1到 n-y+1
        for (int j = 1; j <= n - y; j++) {
            int r = j + y - 1; // 窗口结束位置最大为 n-1
            i64 sumWindow = prefix[r] - prefix[j - 1];
            minFlow = min(minFlow, sumWindow);
            if (minFlow < 2 * x) // 若已经小于要求，就可以提前返回false
                return false;
        }
        return (minFlow >= 2 * x);
    };

    int l = 1, r = n;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (can_cross(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
