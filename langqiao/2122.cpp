// 数位排序

// 问题描述
// 小蓝对一个数的数位之和很感兴趣, 今天他要按照数位之和给数排序。当 两个数各个数位之和不同时, 将数位和较小的排在前面,
// 当数位之和相等时, 将数值小的排在前面。

// 例如, 2022 排在 409 前面, 因为 2022 的数位之和是 6, 小于 409 的数位 之和 13 。

// 又如, 6 排在 2022 前面, 因为它们的数位之和相同, 而 6 小于 2022 。

// 给定正整数 n, m, 请问对 1 到 n 采用这种方法排序时, 排在第 m 个的元素是多少?

// 输入格式
// 输入第一行包含一个正整数 n 。

// 第二行包含一个正整数 m 。

// 输出格式
// 输出一行包含一个整数, 表示答案。

// 样例输入
// 13
// 5

// 样例输出
// 3

// 样例说明
// 1 到 13 的排序为: 1, 10, 2, 11, 3, 12, 4, 13, 5, 6, 7, 8, 9 。第 5 个数为 3 。

// 评测用例规模与约定
// 对于 30% 的评测用例, 1 ≤ m ≤ n ≤ 300 。对于 50% 的评测用例, 1 ≤ m ≤ n ≤ 1000 。对于所有评测用例, 1 ≤ m ≤ n ≤ 10^6 。

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 计算数位和
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }

    sort(nums.begin(), nums.end(), [](int a, int b) {
        int sumA = digitSum(a);
        int sumB = digitSum(b);
        if (sumA != sumB) {
            return sumA < sumB;
        } else {
            return a < b;
        }
    });

    cout << nums[m - 1] << endl;

    return 0;
}
