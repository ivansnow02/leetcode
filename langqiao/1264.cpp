// 排个序

// 题目描述
// 给定一个长度为n的数组a。
// 给定一个长度为m的互不相同的数组p，意味着你可以交换a[pi]和a[pi+1]任意次。
// 请确定是否可以用仅允许的交换方式使得a数组非降序。

// 输入描述
// 第一行输入一个n和m。
// 第二行输入n个整数a1,a2,...,an。
// 第三行输入m个整数p1,p2,p3,...,pm。
// 1≤m<n≤10^3, 1≤ai≤n, 1≤pi<n

// 输出描述
// 如果可以输出YES，否则输出NO。

// 输入输出样例
// 示例1
// 输入:
// 3 2
// 3 2 1
// 1 2
// 输出:
// YES

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    cin >> n >> m;
    vector<int> a(n + 1), p(m + 1);
    vector<bool> flags(n + 1);


    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> p[i];
        flags[p[i]] = 1;
    }
    bool f = true;

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (a[j] > a[j + 1]) {
                if (flags[j]) {
                    swap(a[j], a[j + 1]);
                } else {
                    f = false;
                    break;
                }
            }
        }
        if (f) {
            break;
        }
    }

    auto x = f?"YES":"NO";
    cout << x;
}
