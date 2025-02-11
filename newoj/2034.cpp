// 题目描述
// 爱丽丝要完成一项修剪灌木的工作。
// 有 N 棵灌木整齐的从左到右排成一排。
// 爱丽丝在每天傍晚会修剪一棵灌木，让灌木的高度变为 0 厘米。
// 爱丽丝修剪灌木的顺序是从最左侧的灌木开始，每天向右修剪一棵灌木。
// 当修剪了最右侧的灌木后，她会调转方向，下一天开始向左修剪灌木。
// 直到修剪了最左的灌木后再次调转方向。然后如此循环往复。
// 灌木每天从早上到傍晚会长高 1 厘米，而其余时间不会长高。
// 在第一天的早晨，所有灌木的高度都是 0 厘米。爱丽丝想知道每棵灌木最高长到多高。
// 输入格式
// 一个正整数N ，含义如题面所述。
// 30%的测试数据：1<N≤10；
// 100%的测试数据：1<N≤10000。
// 输出格式
// 输出 N 行，每行一个整数，第 i 行表示从左到右第 i 棵树最高能长到多高。
// 输入样例 复制
// 3
// 输出样例 复制
// 4
// 2
// 4

#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;

    // vector<int> bushes(N);
    // vector<int> maxHeight(N);

    // int cur = 0, flag = 0;

    // for (int i = 0; i < 50000; i++) {
    //     // 早
    //     for (int j = 0; j < N; j++) {
    //         bushes[j]++;
    //         maxHeight[j] = max(maxHeight[j], bushes[j]);
    //     }

    //     // 晚
    //     bushes[cur] = 0;

    //     if (flag == 0) {
    //         cur++;

    //         if (cur == N - 1) {
    //             flag = 1;
    //         }
    //     } else {
    //         cur--;

    //         if (cur == 0) {
    //             flag = 0;
    //         }
    //     }
    // }
    // for (auto x: maxHeight) {
    //     cout << x << endl;

    // }

    // 由于每棵灌木都会在2N天内被剪为0，所以不会无限长高。其中的第i棵，它左边有i-1棵，右边有n-i棵。爱丽丝分别从左右绕回来，各需要2i和2(n-i-1)天，取最大值就是高度。i从0开始。
    for (int i = 0; i < N; i++)
        cout << max(i, N - i - 1) * 2 << endl;
}
