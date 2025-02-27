// 外卖店优先级

// 题目描述
// "饱了么"外卖系统中维护着 N 家外卖店，编号 1 ∼ N。每家外卖店都有一个优先级，初始时 (0 时刻) 优先级都为 0。

// 每经过 1 个时间单位，如果外卖店没有订单，则优先级会减少 1，最低减到
// 0；而如果外卖店有订单，则优先级不减反加，每有一单优先级加 2。

// 如果某家外卖店某时刻优先级大于 5，则会被系统加入优先缓存中；如果优先级小于等于 3，则会被清除出优先缓存。

// 给定 T 时刻以内的 M 条订单信息，请你计算 T 时刻时有多少外卖店在优先缓存中?

// 输入描述
// 第一行包含 3 个整数 N, M, T。

// 以下 M 行每行包含两个整数 ts, id，表示 ts 时刻编号 id 的外卖店收到一个订单。

// 其中，1 ≤ N, M, T ≤ 10^5，1 ≤ ts ≤ T，1 ≤ id ≤ N。

// 输出描述
// 输出一个整数代表答案。

// 输入输出样例
// 示例
// 输入

// 2 6 6
// 1 1
// 5 2
// 3 1
// 6 2
// 2 1
// 6 2

// 输出

// 1

// 样例解释：
// 6 时刻时，1 号店优先级降到 3，被移除出优先缓存；2 号店优先级升到 6，加入优先缓存。所以是有 1 家店 (2 号)
// 在优先缓存中。

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int M, N, T;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    cin >> N >> M >> T;

    vector<int> shops(N + 1);
    unordered_map<int, unordered_map<int, int>> ts_ids;
    unordered_set<int> pcache;


    for (int i = 0; i < M; i++) {
        int ts, id;
        cin >> ts >> id;
        ts_ids[ts][id]++;
    }

    // for (auto x: ts_ids) {cout << x.first << ":";
    //     for (auto e: x.second) {
    //         cout << e << ' ';
    //     }
    //     cout << endl;

    //  }

    for (int i = 1; i <= T; i++) {
        // cout << "t" << i << endl;
        auto ids = ts_ids[i];

        for (int j = 1; j <= N; j++) {
            // 替换 ids.contains(j)
            if (ids.find(j) != ids.end()) {
                shops[j] += ids[j] * 2;
            } else {
                shops[j] = max(0, shops[j] - 1);
            }
            if (shops[j] > 5) {
                pcache.emplace(j);
            }

            // 替换 pcache.contains(j)
            if (shops[j] <= 3 && pcache.find(j) != pcache.end()) {
                pcache.erase(j);
            }
        }

        // for (auto id: ts_ids[i]) {
        //     shops[id].first += 2;
        //     shops[id].second = 1;
        //     if (shops[id].first > 5) {
        //         pcache.emplace(id);
        //     }
        // }


        // for (auto p: pcache) {
        //     if (p.second - i <= 3) {
        //         pcache.erase(p.first);
        //     }
        // }
    }

    cout << pcache.size();
}
