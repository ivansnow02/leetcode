#include "MyHeaders.hpp"
#include <memory>
using namespace std;
/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode.cn/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (63.18%)
 * Likes:    733
 * Dislikes: 0
 * Total Accepted:    326.6K
 * Total Submissions: 516.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: root = [3,9,20,null,null,15,7]
 * 输出: 24
 * 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 *
 *
 * 示例 2:
 *
 *
 * 输入: root = [1]
 * 输出: 0
 *
 *
 *
 *
 * 提示:
 *
 *
 * 节点数在 [1, 1000] 范围内
 * -1000 <= Node.val <= 1000
 *
 *
 *
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
  int sumOfLeftLeaves(TreeNode *root) {
    auto ans = 0;
    stack<shared_ptr<TreeNode>> st;
    st.emplace(make_shared<TreeNode>(*root));
    if (root->left == nullptr && root->right == nullptr) {
        return 0;
      }
    while (!st.empty()) {
      auto cur = st.top();
      st.pop();
      if (cur == nullptr)
        continue;
      if (cur->left != nullptr && cur->left->right == nullptr &&
          cur->left->left == nullptr) {
        ans += cur->left->val;
      }
      if (cur->left != nullptr)
        st.emplace(make_shared<TreeNode>(*(cur->left)));
      if (cur->right != nullptr)
        st.emplace(make_shared<TreeNode>(*(cur->right)));
    }
    return ans;
  }
};
// @lc code=end
