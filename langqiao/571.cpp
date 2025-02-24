// FBI树

// 题目描述
// 我们可以把由 “0” 和 “1” 组成的字符串分为三类：全 “0” 串称为 B 串，全 “1” 串称为 I 串，既含 “0” 又含 “1” 的串则称为 F 串。

// FBI树是一种二叉树，它的结点类型也包括 F 结点，B 结点和 I 结点三种。由一个长度为 2^N 的 “01” 串 S 可以构造出一棵 FBI 树 T，递归的构造方法如下：

// T 的根结点为 R，其类型与串 S 的类型相同；

// 若串 S 的长度大于 1，将串 S 从中间分开，分为等长的左右子串 S1 和 S2 ；由左子串 S1 构造 R 的左子树 T1，由右子串 S2 构造 R 的右子树 T2。

// 现在给定一个长度为 2^N 的 “01” 串，请用上述构造方法构造出一棵FBI树，并输出它的后序遍历序列。

// 输入描述
// 第一行是一个整数 N（0≤N≤10）。

// 第二行是一个长度为 2^N 的 “01” 串。

// 输出描述
// 输出一个字符串，即 FBI 树的后序遍历序列。

// 输入输出样例
// 示例 1
// 输入

// 3
// 10001011

// 输出

// IBFBBBFIBFIIIFF

#include <bits/stdc++.h>
using namespace std;

int N;

struct Node {
    char val;
    Node *l_child, *r_child;
    Node(char v) : val(v), l_child(nullptr), r_child(nullptr) {}

};

Node *build_tree(const string &bs) {
    // 若串 S 的长度大于 1，将串 S 从中间分开，分为等长的左右子串 S1 和 S2 ；由左子串 S1 构造 R 的左子树 T1，由右子串 S2
    // 构造 R 的右子树 T2。
    if (bs.size() == 1) {
        switch (bs[0]) {
            case '0':
                return new Node('B');
            case '1':
                return new Node('I');
        }
    }
    auto l_bs = bs.substr(0, bs.size() / 2);
    auto r_bs = bs.substr(bs.size() / 2);

    Node *cur = new Node(' ');

    auto tlc = build_tree(l_bs);
    auto trc = build_tree(r_bs);

    if (tlc->val == 'I' && trc->val == 'I') {
        cur->val = 'I';
    }else if (tlc->val == 'B' && trc->val == 'B') {
        cur->val = 'B';
    } else {
        cur->val = 'F';
    }
    cur->l_child = tlc;
    cur->r_child = trc;

    // delete (tlc);
    // delete (trc);

    return cur;
}

void traversal(const Node *cur) {
    if (cur == nullptr) {
        return;
    }
    traversal(cur->l_child);
    traversal(cur->r_child);
    cout << cur->val;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> N;
    string s;

    cin >> s;
    auto root = build_tree(s);

    traversal(root);
    return 0;
}
