#include "MyHeaders.hpp"
#include <cstddef>
#include <utility>
using namespace std;
/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 *
 * https://leetcode.cn/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (80.93%)
 * Likes:    1861
 * Dislikes: 0
 * Total Accepted:    977.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [4,2,7,1,3,6,9]
 * 输出：[4,7,2,9,6,3,1]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：root = [2,1,3]
 * 输出：[2,3,1]
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
 * 树中节点数目范围在 [0, 100] 内
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
public:
  auto inverse(TreeNode *cur) {
    if (cur ==nullptr || cur->left == nullptr && cur->right == nullptr)
      return;
    swap(cur->left, cur->right);
    inverse(cur->left);
    inverse(cur->right);

  }
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) return nullptr;
    inverse(root);
    return root;
  }
};
// @lc code=end
