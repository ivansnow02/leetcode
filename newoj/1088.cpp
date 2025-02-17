// 输入两行表示两个非负整数，数字长度不超过1000，求和。
#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    int n = max(a.size(), b.size());
    string result;
    for (int i = 0; i < n; i++) {
        int digitA = (i < a.size() ? a[i] - '0' : 0);
        int digitB = (i < b.size() ? b[i] - '0' : 0);
        int sum = digitA + digitB + carry;
        result.push_back('0' + sum % 10);
        carry = sum / 10;
    }
    if(carry)
        result.push_back('0' + carry);
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    cout << add(a, b);
    return 0;
}
