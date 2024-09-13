#include "MyHeaders.hpp"
using namespace std;
/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode.cn/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Easy (81.95%)
 * Likes:    1173
 * Dislikes: 0
 * Total Accepted:    431.4K
 * Total Submissions: 526.2K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 *
 * 完全二叉树
 * 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第
 * h 层，则该层包含 1~ 2^h 个节点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,4,5,6]
 * 输出：6
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：0
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目范围是[0, 5 * 10^4]
 * 0
 * 题目数据保证输入的树是 完全二叉树
 *
 *
 *
 *
 * 进阶：遍历树来统计节点是一种时间复杂度为 O(n)
 * 的简单解决方案。你可以设计一个更快的算法吗？
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
// private:
//   int cnt = 0;
//   auto traversal(const TreeNode *cur) {
//     if (cur == nullptr)
//       return;
//     cnt++;
//     traversal(cur->left);
//     traversal(cur->right);
//   }

// public:
// /* O(n)*/
//   int countNodes(TreeNode *root) {
//     traversal(root);
//     return cnt;
//   }

public:
//O(log n * log n)
  auto countNodes(TreeNode *root) {
    if (root == nullptr)
      return 0;
    auto lDepth = 0, rDepth = 0;
    for (auto l = root->left; l; l = l->left) {
      lDepth++;
    }
    for (auto r = root->right; r; r = r->right) {
      rDepth++;
    }
    if (lDepth == rDepth) {
      return (2 << lDepth) - 1;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
// @lc code=end
