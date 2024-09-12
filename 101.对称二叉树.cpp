#include "MyHeaders.hpp"
#include <sstream>
using namespace std;
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (60.92%)
 * Likes:    2789
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  // bool isSymmetric(TreeNode *root) {
  //   queue<TreeNode *> q;
  //   if (root == nullptr) {
  //     return true;
  //   }
  //   q.emplace(root);
  //   while (!q.empty()) {
  //     auto n = q.size();
  //     vector<TreeNode *> v;
  //     for (auto i = 0; i < n; i++) {
  //       auto cur = q.front();
  //       q.pop();
  //       if (cur == nullptr) {
  //         v.emplace_back(nullptr);
  //         continue;
  //       }
  //       v.emplace_back(cur);
  //       q.emplace(cur->left);
  //       q.emplace(cur->right);
  //     }
  //     for (auto i = 0; i < v.size() / 2; i++) {
  //       if (v[i] == nullptr && v[v.size() - 1 - i] == nullptr) {
  //         continue;
  //       }
  //       if (v[i] == nullptr || v[v.size() - 1 - i] == nullptr) {
  //         return false;
  //       }
  //       if (v[i]->val != v[v.size() - 1 - i]->val) {
  //         return false;
  //       }
  //     }
  //   }
  //   return true;
  // }

  auto compare(const auto* left, const auto* right) -> decltype(auto) {
    if (left == nullptr && right == nullptr)
      return true;
    else if (left == nullptr && right != nullptr)
      return false;
    else if (left != nullptr && right == nullptr)
      return false;
    else if (left->val != right->val)
      return false;

    auto outside = compare(left->left, right->right);
    auto inside = compare(left->right, right->left);

    return outside && inside;
  }

  bool isSymmetric(TreeNode *root) {
    if (root == NULL)
      return true;
    return compare(root->left, root->right);
  }
};
// @lc code=end

//[1,2,2,3,4,4,3]
int main() {
  Solution s;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);
  cout << s.isSymmetric(root) << endl;
}
