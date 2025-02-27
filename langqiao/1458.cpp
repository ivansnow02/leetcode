// 请求出操作完成后的序列。

// 输入描述
// 输入的第一行包含两个整数 n, m，分别表示序列的长度和操作次数。

// 接下来 m 行描述对序列的操作，其中第 i 行包含两个整数 p_i, q_i
// p_i 表示操作类型和参数。当 p_i = 0 时，表示将 a_1, a_2, ⋅⋅⋅, a_q_i 降序排列；
// 当 p_i = 1 时，表示将 a_q_i, a_q_i+1, ⋯, a_n 升序排列。

// 输出描述
// 输出一行，包含 n 个整数，相邻的整数之间使用一个空格分隔，表示操作完成后的序列。

// 输入输出样例
// 示例
// 输入
// 3 3
// 0 3
// 1 2
// 0 2
// 输出
// 3 1 2

// 样例说明
// 原数列为 (1, 2, 3)。
// 第 1 步后为 (3, 2, 1)。
// 第 2 步后为 (3, 1, 2)。
// 第 3 步后为 (3, 1, 2)，与第 2 步操作后相同，因为前两个数已经是降序了。

// 评测用例规模与约定
// 对于 30% 的评测用例，n, m ≤ 1000；
// 对于 60% 的评测用例，n, m ≤ 5000；
// 对于所有评测用例，1 ≤ n, m ≤ 100000，0 ≤ p_i ≤ 1，1 ≤ q_i ≤ n。

// 运行限制
// 最大运行时间：2s
// 最大运行内存: 256M


// 60

#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
vector<int> nums;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    nums.resize(n);

    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    while (m--) {
        int p, q;
        cin >> p >> q;

        if (p == 0) {
            sort(nums.begin(), nums.begin() + q, greater<int>());
        }
        if (p == 1) {
            sort(nums.begin() + q - 1, nums.end(), less<int>());
        }
        // cout << endl;
        // for (int i = 0; i < n; i++) {
        //     cout << nums[i] << ' ';
        // }
        // cout << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';

    }
}
