#include "MyHeaders.hpp"
#include <climits>
#include <cmath>
#include <memory>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (66.54%)
 * Likes:    376
 * Dislikes: 0
 * Total Accepted:    163K
 * Total Submissions: 244.9K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 给定一棵二叉树的根节点 root
 * ，请找出该二叉树中每一层的最大值。
 *
 *
 *
 * 示例1：
 *
 *
 *
 *
 * 输入: root = [1,3,2,5,3,null,9]
 * 输出: [1,3,9]
 *
 *
 * 示例2：
 *
 *
 * 输入: root = [1,2,3]
 * 输出: [1,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 二叉树的节点个数的范围是 [0,10^4]
 * -2^31 <= Node.val <= 2^31 - 1
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
  vector<int> largestValues(TreeNode *root) {
    vector<int> ans;
    queue<TreeNode *> q;
    q.emplace(root);
    while (!q.empty()) {
      auto size = q.size();
      priority_queue<int> pq;
      for (auto i = 0; i < size; i++) {
        auto cur = q.front();
        q.pop();
        if (cur == nullptr)
          continue;
        pq.emplace(cur->val);
        if (cur->left != nullptr)
          q.emplace(cur->left);
        if (cur->right != nullptr)
          q.emplace(cur->right);
      }
      if (!pq.empty())
        ans.emplace_back(pq.top());
    }
    return ans;
  }
};
// @lc code=end
