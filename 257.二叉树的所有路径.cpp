#include "MyHeaders.hpp"
#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode.cn/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (70.99%)
 * Likes:    1165
 * Dislikes: 0
 * Total Accepted:    422.2K
 * Total Submissions: 594.4K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序
 * ，返回所有从根节点到叶子节点的路径。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：["1"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
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
private:
  struct SNode {
    TreeNode *node;
    string s;
  };

public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    if (!root)
      return ans;
    stack<shared_ptr<SNode>> st;
    st.emplace(make_shared<SNode>(SNode{root, to_string(root->val)}));
    while (!st.empty()) {
      auto cur = st.top();
      st.pop();
      if (cur->node == nullptr)
        continue;
      if (cur->node->left)
        st.emplace(make_shared<SNode>(SNode{
            cur->node->left, cur->s + "->" + to_string(cur->node->left->val)}));
      if (cur->node->right)
        st.emplace(make_shared<SNode>(
            SNode{cur->node->right,
                  cur->s + "->" + to_string(cur->node->right->val)}));
      if (cur->node->left == nullptr && cur->node->right == nullptr) {
        ans.emplace_back(cur->s);
      }
    }
    return ans;
  }
};
// @lc code=end
