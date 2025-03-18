// 问题描述
// 阿坤老师是一位受人尊敬的音乐老师，他发现音乐的和谐之处不仅仅在于音符组合，还在于每个音符与整体音乐的和谐。
// 他将一段音乐分解成 N 个音符，每个音符有其特定的频率值 A_i。
// 阿坤老师认为，一个音符的和谐程度可以用它的频率值与整段音乐的平均频率值的绝对差来衡量，差值越小，音符越和谐。

// 阿坤老师想找出这段音乐中最和谐的音符，也就是与整个音乐的平均频率值的差最小的音符。
// 如果有多个音符满足这个条件，阿坤老师希望找出最早出现的音符。

// 请帮助阿坤老师找出这个最和谐的音符。

// 输入格式
// 输入的第一行包含一个整数 N（1 ≤ N ≤ 10^3）。
// 第二行包含 N 个整数 A_1, A_2, ..., A_N（1 ≤ A_i ≤ 10^5），表示每个音符的频率值。

// 输出格式
// 输出一个整数，表示最和谐音符的索引。索引从1开始。

// 样例输入
// 5
// 1 2 3 2 1

// 样例输出
// 2

// 样例解释
// 在这个例子中，整段音乐的平均频率值为 1.8，与它差值最小的音符是第二个音符，其频率为 2。

#include <bits/stdc++.h>
#include <cmath>
#include <limits>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 n;
    cin >> n;

    vector<i64> notes(n);
    i64 sum = 0;
    for (auto i = 0; i < n; i++) {
        cin >> notes[i];
        sum += notes[i];
    }

    auto avg = static_cast<double>(sum) / n;

    double minD = numeric_limits<double>::max();
    i64 index = 0;

    for (int i = 0; i < n; i++) {
        if (minD > fabs(static_cast<double>(notes[i]) - avg)) {
            minD = fabs(static_cast<double>(notes[i]) - avg);
            // cout << minD << endl;
            index = i;
        }
    }

    cout << ++index << endl;

}
