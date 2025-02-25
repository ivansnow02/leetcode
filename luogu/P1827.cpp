// # P1827 [USACO3.4] 美国血统 American Heritage

// ## 题目描述

// 农夫约翰非常认真地对待他的奶牛们的血统。然而他不是一个真正优秀的记帐员。他把他的奶牛
// 们的家谱作成二叉树，并且把二叉树以更线性的“树的中序遍历”和“树的前序遍历”的符号加以记录而 不是用图形的方法。

// 你的任务是在被给予奶牛家谱的“树中序遍历”和“树前序遍历”的符号后，创建奶牛家谱的“树的
// 后序遍历”的符号。每一头奶牛的姓名被译为一个唯一的字母。（你可能已经知道你可以在知道树的两
// 种遍历以后可以经常地重建这棵树。）显然，这里的树不会有多于 $26$ 个的顶点。

// 这是在样例输入和样例输出中的树的图形表达方式：


// ```plain
// 　　　　　　　　 C
// 　　　　　　   /  \
// 　　　　　　  /　　\
// 　　　　　　 B　　  G
// 　　　　　　/ \　　/
// 　　　　   A   D  H
// 　　　　　　  / \
// 　　　　　　 E   F

// ```

// 附注：

// - 树的中序遍历是按照左子树，根，右子树的顺序访问节点；
// - 树的前序遍历是按照根，左子树，右子树的顺序访问节点；
// - 树的后序遍历是按照左子树，右子树，根的顺序访问节点。

// ## 输入格式

// 第一行一个字符串，表示该树的中序遍历。

// 第二行一个字符串，表示该树的前序遍历。

// ## 输出格式

// 单独的一行表示该树的后序遍历。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// ABEDFCHG
// CBADEFGH
// ```

// ### 输出 #1

// ```
// AEFDBHGC
// ```

// ## 说明/提示

// 题目翻译来自NOCOW。

// USACO Training Section 3.4

#include <bits/stdc++.h>
#include <memory>

using namespace std;

struct Node {
    char val;
    shared_ptr<Node> l_child, r_child;

    Node() {}
    Node(char v) : val(v), l_child(nullptr), r_child(nullptr) {}
};

shared_ptr<Node> build_tree(const string &pre, const string &mid) {
    if (pre.empty() || mid.empty()) {
        return nullptr;
    }
    if (pre.size() == 1) {
        return make_shared<Node>(pre[0]);
    }

    auto root = make_shared<Node>(pre[0]);

    auto m_root = mid.find(pre[0]);

    auto l_mid = mid.substr(0, m_root);
    auto r_mid = mid.substr(m_root + 1);

    // cout << "mid" << l_mid << "," << r_mid <<endl;
    auto l_pre = pre.substr(1, m_root);
    auto r_pre = pre.substr(m_root + 1);
    // cout << "pre" << l_pre << "," << r_pre << endl;

    root->l_child = build_tree(l_pre, l_mid);
    root->r_child = build_tree(r_pre, r_mid);

    return root;
}

void post_order_traversal(shared_ptr<Node> root) {
    if (root == nullptr) {
        return;
    }

    post_order_traversal(root->l_child);
    post_order_traversal(root->r_child);

    cout << root->val;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string pre, mid;
    cin >> mid >> pre;

    auto root = build_tree(pre, mid);

    post_order_traversal(root);
    cout << endl;
}
