// # [蓝桥杯 2024 省 A] 训练士兵

// ## 题目描述

// 在蓝桥王国中，有 $n$ 名士兵，这些士兵需要接受一系列特殊的训练，以提升他们的战斗技能。对于第 $i$ 名士兵来说，进行一次训练所需的成本为 $p_i$ 枚金币，而要想成为顶尖战士，他至少需要进行 $c_i$ 次训练。
// 为了确保训练的高效性，王国推出了一种组团训练的方案。该方案包含每位士兵所需的一次训练，且总共只需支付 $S$ 枚金币（组团训练方案可以多次购买，即士兵可以进行多次组团训练）。
// 作为训练指挥官，请你计算出最少需要花费多少金币，才能使得所有的士兵都成为顶尖战士？

// ## 输入格式

// 输入的第一行包含两个整数 $n$ 和 $S $，用一个空格分隔，表示士兵的数量和进行一次组团训练所需的金币数。
// 接下来的 $n$ 行，每行包含两个整数 $p_i$ 和 $c_i$，用一个空格分隔，表示第 $i$ 名士兵进行一次训练的金币成本和要成为顶尖战士所需的训练次数。

// ## 输出格式

// 输出一行包含一个整数，表示使所有士兵成为顶尖战士所需的最少金币数。

// ## 样例 #1

// ### 样例输入 #1

// ```
// 3 6
// 5 2
// 2 4
// 3 2
// ```

// ### 样例输出 #1

// ```
// 16
// ```

// ## 提示

// 花费金币最少的训练方式为：进行 $2$ 次组团训练，花费 $2 × 6 = 12$ 枚金币，此时士兵 $1, 3$ 已成为顶尖战士；再花费 $4$ 枚金币，让士兵 $2$ 进行两次训练，成为顶尖战士。总花费为 $12 + 4 = 16$。

// 对于 $40\%$ 的评测用例，$1 ≤ n ≤ 10^3，1 ≤ p_i
// , c_i ≤ 10^5，1 ≤ S ≤ 10^7$。

// 对于所有评测用例，$1 ≤ n ≤ 10^5，1 ≤ p_i
// , c_i ≤ 10^6，1 ≤ S ≤ 10^{10}$。

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

typedef long long ll;

ll n, S;

struct Soldier {
    ll p, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> S;
    vector<shared_ptr<Soldier>> soldiers;
    soldiers.reserve(n);

    // sum_p 用于记录所有剩余士兵个体训练时每轮训练的总成本
    ll sum_p = 0;
    for (int i = 0; i < n; i++) {
        ll pi, ci;
        cin >> pi >> ci;
        sum_p += pi;
        soldiers.emplace_back(make_shared<Soldier>(Soldier{pi, ci}));
    }

    // 按照所需训练轮数升序排序
    sort(soldiers.begin(), soldiers.end(), [](auto a, auto b) { return a->c < b->c; });

    ll global = 0; // 表示已经通过组团训练累计的全局训练轮数
    ll ans = 0; // 总花费

    // 遍历所有士兵，补齐其训练轮数
    for (int i = 0; i < n; i++) {
        // 当前士兵所需的总训练轮数
        ll required = soldiers[i]->c;
        // 还需要补充的轮数（如果 global 已经达到要求，则不需要额外训练）
        ll need = (required > global ? required - global : 0);

        // 尽可能采用组团训练，因为它可以同时训练所有剩余士兵，
        // 前提是所有剩余士兵个体训练一轮的总成本 (sum_p) 高于组团训练成本 S
        while (need > 0 && sum_p > S) {
            ans += S; // 一次组团训练花费 S
            global++; // 所有剩余士兵的训练轮数同时增加 1
            need--; // 当前士兵也获得了一轮训练
        }

        // 如果组团训练条件不满足或已经不需要补充的轮数还剩下，
        // 则对当前士兵采用个体训练补齐剩余的训练轮数
        if (need > 0) {
            ans += need * soldiers[i]->p;
            // 注意：个体训练只影响当前士兵，其它士兵 global 不变
        }
        // 当前士兵已经训练达到要求，将其个体训练成本移除
        sum_p -= soldiers[i]->p;
    }

    cout << ans << endl;
    return 0;
}
