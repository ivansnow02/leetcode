#include "MyHeaders.hpp"
#include <cstddef>
using namespace std;
/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 *
 * https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (73.72%)
 * Likes:    1134
 * Dislikes: 0
 * Total Accepted:    427K
 * Total Submissions: 579K
 * Testcase Example:  '[1,2,3,4,5,6,7]'
 *
 * 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
 *
 *
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 *
 * 填充它的每个 next
 * 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next
 * 指针设置为 NULL。
 *
 * 初始状态下，所有 next 指针都被设置为 NULL。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [1,2,3,4,5,6,7]
 * 输出：[1,#,2,3,#,4,5,6,7,#]
 * 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next
 * 指针，以指向其下一个右侧节点，如图 B
 * 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#'
 * 标志着每一层的结束。
 *
 *
 *
 *
 * 示例 2:
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数量在 [0, 2^12 - 1] 范围内
 * -1000 <= node.val <= 1000
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你只能使用常量级额外空间。
 * 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 *
 *
 */
// Definition for a Node.
// class Node {
// public:
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;

//   Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//   Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//   Node(int _val, Node *_left, Node *_right, Node *_next)
//       : val(_val), left(_left), right(_right), next(_next) {}
// };
// @lc code=start

class Solution {
public:
  // Node *connect(Node *root) {
  //   queue<Node *> q;
  //   if (root != nullptr)
  //     q.emplace(root);

  //   while (!q.empty()) {
  //     auto n = q.size();
  //     for (auto i = 0; i < n ; i++) {
  //       auto cur = q.front();
  //       q.pop();
  //       auto nxt = cur;
  //       if (!q.empty())
  //         nxt = q.front();
  //       if (nxt != cur && i < n - 1)
  //         cur->next = nxt;
  //       if (cur->left != nullptr)
  //         q.emplace(cur->left);
  //       if (cur->right != nullptr)
  //         q.emplace(cur->right);
  //     }
  //   }
  //   return root;
  // }
  auto traversal(Node *left, Node *right) {
    if (right == nullptr && left == nullptr)
      return;
    left->next = right;
    traversal(left->left, left->right);
    traversal(left->right, right->left);
    traversal(right->left, right->right);
  }
  auto connect(Node *root) {
    if (root == nullptr)
      return root;
    traversal(root->left, root->right);
    return root;
  }
};
// 4 5
// cur = 3
// nxt = 4
// @lc code=end
