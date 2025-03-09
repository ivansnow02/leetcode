// 问题描述
// 某商场有 N 件商品，其中第 i 件的价格是 Ai。现在该商场正在进行 “买二赠一” 的优惠活动，具体规则是：每购买 2
// 件商品，假设其中较便宜的价格是 P（如果两件商品价格一样，则 P
// 等于其中一件商品的价格），就可以从剩余商品中任选一件价格不超过 P 的商品，免费获得这一件商品。可以通过反复购买 2
// 件商品来获得多件免费商品，但是每件商品只能被购买或免费获得一次。

// 小明想知道如果要拿下所有商品（包含购买和免费获得），至少要花费多少钱？

// 输入格式
// 第一行包含一个整数 N。

// 第二行包含 N 个整数，代表 A1, A2, A3, …, AN。

// 输出格式
// 输出一个整数，代表答案。

// 样例输入
// 7
// 1 4 2 8 5 7 1

// 样例输出
// 25

// 样例说明
// 小明可以先购买价格 4 和 8 的商品，免费获得一件价格为 1 的商品；再后买价格为 5 和 7 的商品，免费获得价格为 2
// 的商品；最后单独购买剩下的一件价格为 1 的商品。总计花费 4+8+5+7+1=25。不存在花费更低的方案。

// 评测用例规模与约定
// 对于 30% 的数据，1≤N≤20。

// 对于 100% 的数据，1≤N≤5×10^5，1≤Ai≤10^9。
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

using i64 = long long;
template<typename It, typename T>
It upper_bound_desc(It first, It last, const T &value) {
    int count = std::distance(first, last);
    while (count > 0) {
        It it = first;
        int step = count / 2;
        std::advance(it, step);
        if (*it > value) {
            first = ++it;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}
int main() {

    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 N;
    cin >> N;
    vector<i64> goods(N);
    vector<bool> visited(N, false);
    for (auto i = 0; i < N; i++) {
        cin >> goods[i];
    }

    sort(goods.begin(), goods.end(), greater<i64>());

    i64 ans = 0;
    i64 cnt = 0;
    i64 last = -1; // 购买的2件中的便宜的那件
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            cnt++;
            ans += goods[i];
            last = goods[i]; // last是买的第2件

            // cout << last << ' ';
        }

        if (cnt == 2) { // 买了2个
            cnt = 0;
            auto x = upper_bound_desc(goods.begin(), goods.end(), last / 2) - goods.begin();
            // cout << x << ' ';

            while (x < N && (visited[x] || goods[x] > last)) {
                x++;
            }
            if (x < N) {
                visited[x] = 1;
            }
            // cout << goods[x] << endl;
        }


    }

    cout << ans << endl;
}
