// 求阶乘

// 问题描述
// 满足 N! 的末尾恰好有 K 个 0 的最小的 N 是多少?

// 如果这样的 N 不存在输出 -1 。

// 输入格式
// 一个整数 K 。

// 输出格式
// 一个整数代表答案。

// 样例输入
// 2

// 样例输出
// 10

// 评测用例规模与约定
// 对于 30% 的数据, 1 ≤ K ≤ 10^6 。

// 对于 100% 的数据, 1 ≤ K ≤ 10^18 。


// 0 only comes from 2*5, since 2 is more than 5, so we only need to count 5

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using i64 = unsigned long long;

// 10! = 10 * ... * 5 * ... * 1 = two 5 = xxxx00


int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    // K 0s
    i64 K;

    cin >> K;

    auto five_nums = [](i64 K) -> i64 {
        i64 cnt = 0;
        while (K) {
            cnt += (K /= 5);
        }
        return cnt;
    };

    i64 l = 0, r = numeric_limits<long long>::max();

    while (l <= r) {
        i64 mid = (l + r) >> 1;
        i64 t = five_nums(mid);
        // cout << "mid:" << mid << "\tt:"<< t << endl;

        if (t > K) {
            r = mid - 1;
        }
        else if (t < K) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }


    if (five_nums(l) == K)
        cout << l;
    else
        cout << -1;

    // 0 1 2 3 4 5 6 7 8 9 10
    //       l r

}
