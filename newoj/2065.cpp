// 题目描述
// 已知3个矩形的大小依次是a1×b1, a2×b2 和a3×b3。
// 用这3个矩形能拼出的所有多边形中，边数最少可以是多少？


// 输入格式
// 输入包含多组数据。
// 第一行包含一个整数T，代表数据组数。
// 以下T行，每行包含6个整数a1, b1, a2, b2, a3, b3。
// 其中a1, b1 是第一个矩形的边长，a2, b2 是第二个矩形的边长，a3, b3 是第三个矩形的边长。
// 对于10% 的评测用例，1≤T≤5，1≤a1; b1, a2; b2, a3, b3≤10，a1 = a2 = a3。
// 对于30% 的评测用例，1≤T≤5，1≤a1, b1, a2; b2, a3, b3≤10。
// 对于60% 的评测用例，1≤T≤10，1≤a1, b1, a2, b2, a3, b3≤20。
// 对于所有评测用例，1≤T≤1000，1≤a1, b1, a2, b2, a3, b3≤100。
// 输出格式
// 对于每组数据，输出一个整数代表答案。
// 输入样例 复制
// 2
// 2 3 4 1 2 4
// 1 2 3 4 5 6
// 输出样例 复制
// 4
// 6

#include <bits/stdc++.h>

using namespace std;



// 四边形时
// 1.当三个矩阵的边长有一边都相等时
// 2.像例子中那样，有两个矩阵的一个边相等，另外两个边之和跟第三个矩阵的一个边相等
bool is4(int x1, int x2, int x3 ,const vector<vector<int>> &rects) {
    if (x1 == x2 + x3 && rects[1][0] + rects[1][1] - x2 == rects[2][0] + rects[2][1] - x3) {
        return true;
    }
    if (x2 == x1 + x3 && rects[0][0] + rects[0][1] - x1 == rects[2][0] + rects[2][1] - x3) {
        return true;
    }
    if (x3 == x1 + x2 && rects[0][0] + rects[0][1] - x1 == rects[1][0] + rects[1][1] - x2) {
        return true;
    }
    if (x1 == x2 && x2 == x3) {
        return true;
    }
    return false;
}

// 六边形时
// 1.当两个矩阵的边长之和等于第三个矩阵的一条边
// 2.只有两个矩阵有一边相等
bool is6(int x1, int x2, int x3, const vector<vector<int>> &rects) {
    if (x1 == x2 + x3 || x2 == x1 + x3 || x3 == x1 + x2) {
        return true;
    }
    if (x1 == x2 || x2 == x3 || x3 == x1) {
        return true;
    }
    return false;
}
void solve() {
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    vector<vector<int>> rects(3, vector<int>(2));

    rects[0][0] = a1;
    rects[0][1] = a2;
    rects[1][0] = b1;
    rects[1][1] = b2;
    rects[2][0] = c1;
    rects[2][1] = c2;
    int ans = 8;

    for (int i1 = 0; i1 < 2; i1++) {
        for (int i2 = 0; i2 < 2; i2++) {
            for (int i3 = 0; i3 < 2; i3++) {
                auto x1 = rects[0][i1], x2 = rects[1][i2], x3 = rects[2][i3];
                if (is4(x1, x2, x3, rects)) {
                    ans = min(ans, 4);
                }
                if (is6(x1, x2, x3, rects)) {
                    ans = min(ans, 6);
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {

    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }
    return 0;
}
