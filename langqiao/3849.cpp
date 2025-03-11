// 问题描述
// 一共有 n 个身份证，编号 1∼n，还有 m 个门，可以进入第 i 个门的身份证编号是 l_i∼r_i，请问 n 个身份证中，所有门都可进入的身份证有几个。

// 输入格式
// 第一行有两个整数 n, m。

// 接下来 m 行，每行两个整数，按顺序表示每个门可以进入的身份证编号 l_i∼r_i。

// 输出格式
// 输出一个整数表示所有门都可以进入的身份证个数。

// 样例输入
// 4 2
// 1 3
// 2 4

// 样例输出
// 2

// 说明
// 保证对于所有数据有：1 ≤ n, m ≤ 1×10^5, 1 ≤ l_i, r_i ≤ n。

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {

    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 n, m;
    cin >> n >> m;

    vector<i64> d(n+1);

    for (int i = 0; i < m; i++) {
        i64 li, ri;
        cin >> li >> ri;

        d[li] += 1;
        if (ri + 1 <= n) {
            d[ri + 1] -= 1;
        }
    }

    vector<i64> res(n + 1);
    res[1] = d[1];

    for (int i = 2; i <= n; i++) {
        res[i] = res[i-1] + d[i];
    }

    // for (auto x: d) {
    //     cout << x << ' ';
    // }
    // cout << endl;
    // for (auto x: res) {
    //     cout << x << ' ';
    // }
    // cout << endl;
    i64 ans = 0;

    for (int i = 1; i <= n; i++) {
        if (res[i] == m) {
            ans++;
        }
    }

    cout << ans;

}
