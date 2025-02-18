// 输入两行表示两个非负整数，数字长度不超过1000，求差。

#include <bits/stdc++.h>
using namespace std;

string operator-(const string &a, const string &b) {
    bool negative = false;
    string u = a, d = b;

    // 确定谁更大，如果 a 小于 b，则交换，它们互换后结果取负
    if (a.size() < b.size() || (a.size() == b.size() && a < b)) {
        swap(u, d);
        negative = true;
    }

    // 反转字符串方便从低位开始做减法
    reverse(u.begin(), u.end());
    reverse(d.begin(), d.end());

    // d 不足位补 0
    while (d.size() < u.size())
        d.push_back('0');

    string res;
    int carry = 0, n = u.size();
    for (int i = 0; i < n; i++) {
        int u_digit = u[i] - '0';
        int d_digit = d[i] - '0';
        int diff = u_digit - d_digit - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res.push_back(diff + '0');
    }

    // 去掉可能多出的末尾 0（即高位的0，因为结果是反序）
    while (res.size() > 1 && res.back() == '0')
        res.pop_back();

    // 恢复正确数字顺序
    reverse(res.begin(), res.end());

    // 如果结果负数，结果前加负号（注意 "0" 不加负号）
    if (negative && res != "0")
        res.insert(res.begin(), '-');

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << (a - b);
}
