// 完全二叉树的权值

// 题目描述
// 给定一棵包含 N 个节点的完全二叉树，树上每个节点都有一个权值，按从上到下、从左到右的顺序依次是 A1, A2, ⋅⋅⋅ AN，如下图所示：

// 现在小明要把相同深度的节点的权值加在一起，他想知道哪个深度的节点权值之和最大？如果有多个深度的权值和同为最大，请你输出其中最小的深度。

// 注：根的深度是 1。

// 输入描述
// 第一行包含一个整数 N（1≤N≤10^5）。

// 第二行包含 N 个整数 A1, A2, ⋅⋅⋅ AN（−10^5 ≤ Ai ≤ 10^5）。

// 输出描述
// 输出一个整数代表答案。

// 输入输出样例
// 示例
// 输入
// 7
// 1 6 5 4 3 2 2

// 输出
// 2

#include <bits/stdc++.h>
using namespace std;
typedef long long int64 ;

int N;

vector<int> tree;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> N;

    tree.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> tree[i];
    }

    auto calcu_index = [](int level) -> int {
        return (1 << --level);
    };

    auto calcu_size = [](int level) -> int { return (1 << --level); };

    int level = ceil(log2(N + 1));

    int64 tmax = numeric_limits<int64>::min();
    int64 ans;

    for (int i = 1; i <= level; i++) {
        int64 sum = 0;
        for (int j = calcu_index(i); j < min(calcu_index(i) + calcu_size(i), N); j++) {
            sum += tree[j];
        }
        if (tmax < sum) {
            tmax = sum;
            ans = i;
        }
    }

    cout << ans;
}
