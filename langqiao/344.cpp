// 图书管理员

// 题目描述
// 图书馆中每本书都有一个图书编码，可以用于快速检索图书，这个图书编码是一个正整数。

// 每位借书的读者手中有一个需求码，这个需求码也是一个正整数。如果一本书的图书编码恰好以读者的需求码结尾，那么这本书就是这位读者所需要的。

// 小 D 刚刚当上图书馆的管理员，她知道图书馆里所有书的图书编码，她请你帮她写一个程序，对于每一位读者，求出他所需要的书中图书编码最小的那本书，如果没有他需要的书，请输出-1。

// 输入描述
// 输入的第一行，包含两个正整数 n 和 q，以一个空格分开，分别代表图书馆里书的数量和读者的数量。

// 接下来的 n 行，每行包含一个正整数，代表图书馆里某本书的图书编码。

// 接下来的 q 行，每行包含两个正整数，以一个空格分开，第一个正整数代表图书馆里读者的需求码的长度，第二个正整数代表读者的需求码。

// 其中，1 ≤ n ≤ 1000，1 ≤ q ≤ 1000，所有的图书编码和需求码均不超过 10^7。

// 输出描述
// 输出文件有 q 行，每行包含一个整数，如果存在第 i 个读者所需要的书，则在第 i 行输出第 i 个读者所需要的书中图书编码最小的那本书的图书编码，否则输出-1。

// 输入输出样例
// 示例
// 输入

// 5 5
// 2123
// 1123
// 23
// 24
// 24
// 2 23
// 3 123
// 3 124
// 2 12
// 2 12

// 输出

// 23
// 1123
// -1
// -1
// -1

#include <bits/stdc++.h>
#include <string>
using namespace std;

bool ends_with(const string &str, const string &suffix) {
    if (str.length() < suffix.length()) {
        return false;
    }
    return str.substr(str.length() - suffix.length()) == suffix;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    int n, q;

    cin >> n >> q;
    vector<int> books(n), readers(q);
    string reader;
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    sort(books.begin(), books.end());


    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        cin >> reader;
        auto flag = false;
        for (auto s: books) {
            if (ends_with(to_string(s), reader)) {
                cout << s << endl;
                flag = true;
                break;
            }
        }
        if (flag == false) {
            cout << -1 << endl;
        }
    }
}
