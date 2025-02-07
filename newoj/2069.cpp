// 题目描述
// 给定 L,R，问 L≤x≤R 中有多少个 x 满足存在整数 y,z，使得 x = y2 - z2。
// 输入格式
// 输入一行包含两个整数 L,R，用一个空格分隔。
// 对于 40% 的评测用例，L,R≤5000；
// 对于 100% 的评测用例，1≤L≤R≤1,000,000,000。
// 输出格式
// 输出一行包含一个整数满足题目给定条件的 x 的数量。
// 输入样例 复制
// 1 5
// 输出样例 复制
// 4
// 数据范围与提示
// 1 = 12 - 02 ；
// 3 = 22 - 12 ；
// 4 = 22 - 02 ；
// 5 = 32 - 22 。

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    long long L, R;

    cin >> L >> R;


    cout << (R + 1) / 2 + R / 4 - (L / 2 + (L - 1) / 4) << endl;
    
}
