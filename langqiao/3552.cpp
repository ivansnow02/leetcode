#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 初始化第一行，表示输入数据
bool ha[5][5] = {{1, 0, 1, 0, 1}};
i64 ans = 0;

// 辅助函数，d 表示当前行（1 到 4），pos 表示当前行中正在处理的位置
void dfs_row(int d, int pos) {
    // 当前行共有 5-d 个门电路待赋值
    if (pos == 5 - d) {
        if (d == 4) { // 如果已经确定到最后一行，检查顶点输出
            if (ha[4][0] == 1)
                ans++;
        } else {
            // 本行填完后，递归处理下一行
            dfs_row(d + 1, 0);
        }
        return;
    }

    // 对当前门电路尝试3种操作
    for (int op = 0; op < 3; op++) {
        int a = ha[d - 1][pos];
        int b = ha[d - 1][pos + 1];
        int res;
        if (op == 0) { // 与门
            res = a & b;
        } else if (op == 1) { // 或门
            res = a | b;
        } else { // 异或门
            res = a ^ b;
        }
        ha[d][pos] = res;
        dfs_row(d, pos + 1);
        // 不需要回退赋值，因为后续赋值会覆盖原值
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    dfs_row(1, 0);
    cout << ans;
    return 0;
}
