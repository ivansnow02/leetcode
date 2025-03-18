// 卡牌游戏

// 题目描述：
// 你手上有 n 张卡牌，要求将其填入框中，使得结果最小。
// 每张卡有两面：即每张卡有两个数字。
// 6 不能当作 9 使用，同理，9 也不能当作 6 使用。
// 框与框之间有计算符号。计算符号以 - 和 + 间隔。
// 例如：当 n=8 时，填入的框格式为：-O+O-O+O-O+O-O+O。
// 填入卡牌时，不一定需要按照卡牌和框的顺序进行填写（即可以进行位置的调换）。

// 输入描述：
// 第一行一个正整数 n。
// 接下来 n 行：每行两个整数 Ai 和 Bi，分别表示每张卡牌的正面和反面。
// 其中，n ≤ 5·10^5 且 |Ai|, |Bi| ≤ 10^7。

// 输出描述：
// 输出一行一个整数，表示最小结果。

// 输入输出样例
// 示例 1
// 输入：
// 6
// -8 12
// 0 5
// 7 -3
// 10 -7
// -2 7
// 1 4

// 输出：
// -34

// for example: sum = - 12 + 0 = -12, or , - 5 + -8 = -13
// - 12 + 8 = -4; -5 + 0 = - 5
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 n;

    cin >> n;

    vector<pair<i64, i64>> cards(n);

    for (int i = 0; i < n; i++) {
        cin >> cards[i].first >> cards[i].second;

        // first is smaller than second
        if (cards[i].first > cards[i].second) {
            swap(cards[i].first, cards[i].second);
        }
    }

    // if n is an odd number, there is n/2+1 neg and n/2 pos
    // 8 = 4 + 4
    // 9 = 5 + 4

    // 具体来说，对于一张卡牌 (x, y) 来说（保证 x ≤ y）：
    // 如果把卡牌放在正号位置，贡献 x；
    // 如果放在负号位置，贡献 -y；
    // 相互比较，两种选择的差值为 x+y（即将卡牌当作负号时，比当正号时少了 x+y）。
    // 因此，对某张卡来说，将它放在负号位置能够使结果减少 x+y。所以最有利的策略应该是把那些 x+y 较大的卡牌选为负号卡牌。
    sort(cards.begin(), cards.end(), [](auto a, auto b) { return a.first + a.second > b.first + b.second; });

    i64 ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        ans -= cards[i].second;
        // cout << " - " << cards[i].second;
    }
    for (int i = (n + 1) / 2; i < n; i++) {
        ans += cards[i].first;
        // cout << " + " << cards[i].first;
    }

    cout << ans << endl;
}
