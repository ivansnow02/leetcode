// # [蓝桥杯 2023 省 A] 填空问题

// ## 题目描述

// ## A. 幸运数

// 小蓝认为如果一个数含有偶数个数位，并且前面一半的数位之和等于后面一半的数位之和，则这个数是他的幸运数字。例如 $2314$
// 是一个幸运数字，因为它有 $4$ 个数位，并且 $2+3=1+4$。现在请你帮他计算从 $1$ 至 $100000000$
// 之间共有多少个不同的幸运数字。

// ## B. 有奖问答

// 小蓝正在参与一个现场问答的节目。活动中一共有 $30$ 道题目，每题只有答对和答错两种情况，每答对一题得 $10$
// 分，答错一题分数归零。

// 小蓝可以在任意时刻结束答题并获得目前分数对应的奖项，之后不能再答任何题目。最高奖项需要 $100$ 分，所以到达 $100$
// 分时小蓝会直接停止答题。

// 已知小蓝最终实际获得了 $70$ 分对应的奖项，请问小蓝所有可能的答题情况有多少种？

// ## 输入格式

// 这是一道结果填空的题，你只需要算出结果后提交即可。本题的结果为一个整数，在提交答案时只填写这个整数，填写多余的内容将无法得分。

// 您可以通过提交答案文件的方式进行提交。你需要将你的答案放在 `1.out` 和 `2.out` 中，其中 `1.out` 对应 A
// 题的答案，`2.out` 对应 B 题的答案。

// 输入文件包含一个字符，代表题目编号（`A` 或 `B`），你需要输出对应的答案。

// 以下模板供参考：

// ```cpp
// #include<bits/stdc++.h>
// using namespace std;

// char pid;
// int main() {
//     cin >> pid;
//     if(pid == 'A')
//         puts("Answer for Problem A");
//     else
//         puts("Answer for Problem B");
//     return 0;
// }
// ```

// ## 输出格式

// ## 提示

// 第十四届蓝桥杯大赛软件赛省赛 C/C++ 大学 A 组 A-B

#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;

void A() {
    ll cnt = 0;
    for (ll i = 1; i <= 100000000; i++) {
        ll sum1 = 0, sum2 = 0;

        string s = to_string(i);
        if (s.length() % 2 == 1) {
            continue;
        }
        for (auto j = 0; j < s.length() / 2; j++) {
            sum1 += s[j] - '0';
        }
        for (auto j = s.length() / 2; j < s.length(); j++) {
            sum2 += s[j] - '0';
        }
        if (sum1 == sum2) {
            cnt++;
            cout << i << ' ' << sum1 << ' ' << sum2 << endl;
        }
    }
    cout << cnt;
}

void B() {
    // dp[i][j] 回答第i题获得j*10分的方案数
    int dp[31][11];

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= 30; i++) {
        for (int j = 0; j <= min(i, 9); j++) {
            dp[i][0] += dp[i - 1][j];
        }
        for (int j = 1; j <= 10; j++) {
            dp[i][j] = dp[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int i = 1; i <= 30; i++) {
        ans += dp[i][7];
    }
    cout << ans;
}
char pid;
int main() {
    // A();
    //  B();
    cin >> pid;
    if (pid == 'A')
        puts("4430091");
    else
        // puts("8335366");
        puts("4165637");//?
    return 0;
}
