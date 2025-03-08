// # P1803 凌乱的yyy / 线段覆盖

// ## 题目背景

// **Python 用户可以尝试使用 pypy3 提交试题。**

// 快 noip 了，yyy 很紧张！

// ## 题目描述

// 现在各大 oj 上有 $n$ 个比赛，每个比赛的开始、结束的时间点是知道的。

// yyy 认为，参加越多的比赛，noip 就能考的越好（假的）。

// 所以，他想知道他最多能参加几个比赛。

// 由于 yyy 是蒟蒻，如果要参加一个比赛必须善始善终，而且不能同时参加 $2$ 个及以上的比赛。

// ## 输入格式

// 第一行是一个整数 $n$，接下来 $n$ 行每行是 $2$ 个整数 $a_{i},b_{i}\ (a_{i}<b_{i})$，表示比赛开始、结束的时间。

// ## 输出格式

// 一个整数最多参加的比赛数目。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 3
// 0 2
// 2 4
// 1 3
// ```

// ### 输出 #1

// ```
// 2
// ```

// ## 说明/提示

// - 对于 $20\%$ 的数据，$n \le 10$；
// - 对于 $50\%$ 的数据，$n \le 10^3$；
// - 对于 $70\%$ 的数据，$n \le 10^{5}$；
// - 对于 $100\%$ 的数据，$1\le n \le 10^{6}$，$0 \le a_{i} < b_{i} \le 10^6$。
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 n;
    using Exam = struct {
        i64 start, end;
    };
    cin >> n;

    vector<Exam *> exams(n);


    for (int i = 0; i < n; i++) {
        exams[i] = new Exam();
        cin >> exams[i]->start >> exams[i]->end;
    }

    sort(exams.begin(), exams.end(), [](const Exam *a, const Exam *b) {
        if (a->end == b->end) {
            return a->start < b->start;
        }
        return a->end < b->end;
    });


    i64 t = -1;

    i64 cnt = 0;

    for (const auto &e: exams) {
        if (e->start < t) {
            continue;
        }
        t = e->end;
        cnt++;
    }

    cout << cnt;
}
