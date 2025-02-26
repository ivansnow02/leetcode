// // 题目描述
// // 某石油公司计划建造一条由东向西的主输油管道。该管道要穿过一个有n口油井的油田。
// // 从每口油井都要有一条输油管道沿最短路径(或南或北)与主管道相连。
// // 如果给定n口油井的位置，即它们的x 坐标（东西向）和y 坐标（南北向）
// // 应如何确定主管道的最优位置，即使各油井到主管道之间的输油管道长度总和最小的位置
// // 输入格式
// // 输入第一行为正整数n(1<=n<=10000)
// // 接下来n行，每行两个整数x,y，表示第i个油井的位置(-10000<=x,y<=10000)
// // 输出格式
// // 输出一行整数表示答案
// // 输入样例 复制
// // 5
// // 1 2
// // 2 2
// // 1 3
// // 3 -2
// // 3 3
// // 输出样例 复制
// // 6

// #include <bits/stdc++.h>
// using namespace std;
// // n口油井
// int n;
// vector<int> ys;

// // 三分
// int solution(int y) {
//     int sum = 0;
//     for (auto yi: ys) {
//         sum += abs(yi - y);
//     }

//     return sum;
// }

// int tri_search() {
//     int l = -10000, r = 10000;
//     while (r - l > 2) {
//         int mid1 = l + (r - l) / 3;
//         int mid2 = r - (r - l) / 3;
//         if (solution(mid1) > solution(mid2)) {
//             l = mid1;
//         } else {
//             r = mid2;
//         }
//     }
//     return min({solution(l), solution(r), solution((l + r) / 2)});

// }

// int main() {
//     ios::sync_with_stdio(0), cin.tie(nullptr);

//     cin >> n;
//     ys.resize(n);

//     for (int i = 0; i < n; i++) {
//         int t;
//         cin >> t >> ys[i];
//     }

//     cout << tri_search() << endl;
// }

#include <bits/stdc++.h>
using namespace std;
// n口油井
int n;
vector<int> ys;
// 排序中位数
int solution(int y) {
    int sum = 0;
    for (auto yi: ys) {
        sum += abs(yi - y);
    }

    return sum;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    cin >> n;
    ys.resize(n);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t >> ys[i];
    }

    sort(ys.begin(), ys.end());

    cout << solution(ys[n / 2]);

}
