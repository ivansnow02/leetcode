// 问题描述
// 儿童节那天有 K 位小朋友到小明家做客。小明拿出了珍藏的巧克力招待小朋友们。

// 小明一共有 N 块巧克力，其中第 i 块是 Hi × Wi 的方格组成的长方形。为了公平起见，

// 小明需要从这 N 块巧克力中切出 K 块巧克力分给小朋友们。切出的巧克力需要满足：

// 形状是正方形，边长是整数;

// 大小相同;

// 例如一块 6×5 的巧克力可以切出 6 块 2×2 的巧克力或者 2 块 3×3 的巧克力。

// 当然小朋友们都希望得到的巧克力尽可能大，你能帮小明计算出最大的边长是多少么？

// 输入描述
// 第一行包含两个整数 N, K (1 ≤ N, K ≤ 10^5)。

// 以下 N 行每行包含两个整数 Hi, Wi (1 ≤ Hi, Wi ≤ 10^5)。

// 输入保证每位小朋友至少能获得一块 1x1 的巧克力。

// 输出描述
// 输出切出的正方形巧克力最大可能的边长。

// 输入输出样例
// 示例
// 输入
// 2 10
// 6 5
// 5 6

// 输出
// 2

#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

using i64 = long long;

// K children
i64 K;
// N pieces of chocolate
i64 N;


int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N >> K;

    vector<pair<i64, i64>> chocolate(N);

    for (int i = 0; i < N; i++) {
        cin >> chocolate[i].first >> chocolate[i].second;
        // if (chocolate[i].first > chocolate[i].second) {
        //     swap(chocolate[i].first, chocolate[i].second);
        // }
    }

    auto calculate = [&chocolate](i64 len) -> i64 {
        i64 cnt = 0;
        for (const auto &c: chocolate) {
            cnt += (c.first / len) * (c.second / len);
        }
        return cnt;
    };

    i64 l = 1, r = 10e5 + 9;

    while (l <= r) {
        auto mid = (l + r) >> 1;
        auto midn = calculate(mid);

        // cout << "mid:" << mid << "\tmidn:" << midn << endl;

        if (midn < K) {
            r = mid - 1;
        }else if (midn > K) {
            l = mid + 1;
        }else {
            l = mid + 1;
        }
    }

    cout << r;



}
