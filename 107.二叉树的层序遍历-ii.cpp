#include "MyHeaders.hpp"
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Medium (74.48%)
 * Likes:    810
 * Dislikes: 0
 * Total Accepted:    356.6K
 * Total Submissions: 478.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。
 * （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[15,7],[9,20],[3]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 *
 * 示例 3：
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
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.emplace(root);
    while (!q.empty()) {
      vector<int> v;
      auto size = q.size();
      for (auto i = 0; i < size; i++) {
        auto node = q.front();
        q.pop();
        if (node == nullptr)
          continue;
        v.emplace_back(node->val);
        if (node->left)
          q.emplace(node->left);
        if (node->right)
          q.emplace(node->right);
      }
      if (!v.empty())
        ans.emplace_back(v);
    }
    if (!ans.empty())
      reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
