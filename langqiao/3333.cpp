// 问题描述
// 肖恩提出了一种新的排序方法。

// 该排序方法需要一个标准数组 B 和一个待排序数组 A。
// 在确保对于所有位置 i 都有 A[i] > B[i] 的前提下，肖恩可以自由选择 A 数组的排序结果。
// 请计算按照这种排序方法，待排序数组 A 可能的结果有多少种。

// 对于任意一个位置 i，如果两次排序后 A[i] 不是同一个数字，那么这两种排序方式就被称为是不同的。
// 结果可能很大，你需要将结果对 10^9 + 7 取余。

// 输入描述
// 第一行输入一个数字 n，为两个数组的长度。

// 第二行输入 n 个数字，表示待排序数组 A 中的所有元素。

// 第三行输入 n 个数字，表示标准数组 B 中的所有元素。

// 数据保证
// 1 ≤ n ≤ 10^5, 1 ≤ A[i] ≤ 10^9, 1 ≤ B[i] ≤ 10^9。

// 输出描述
// 输出一个数字，表示所有的排列数对 10^9 + 7 取余后的结果。

// 样例输入
// 5
// 2 3 5 6 8
// 1 2 3 4 5

// 样例输出
// 4

// 说明
// 一共有以下四种符合条件的排序后的 A 数组：
// 2, 3, 5, 6, 8
// 2, 3, 6, 5, 8
// 2, 3, 8, 5, 6
// 2, 3, 5, 8, 6

#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
typedef long long i64 ;

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    cin >> n;

    vector<i64> A(n), B(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // 8 6 5 3 2
    sort(A.begin(), A.end(), greater<i64>());
    // 5 4 3 2 1
    sort(B.begin(), B.end(), greater<i64>());

    int a_i = 0, b_i = 0;
    // 记录当前有多少个 A 数组的元素大于当前的 B 数组元素
    int cnt = 0;
    i64 ans = 1;

    while (b_i < n) {
        while (A[a_i] > B[b_i] && a_i < n) {
            cnt++;
            a_i++;
        }
        // 每次选择一个 A 数组的元素后，可供选择的 A 数组元素数量就会减少
        ans *= cnt--;
        ans %= i64(1e9+7);
        b_i++;
    }
    cout << ans << endl;
}
