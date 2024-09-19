#include "MyHeaders.hpp"
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.97%)
 * Likes:    2376
 * Dislikes: 0
 * Total Accepted:    710.5K
 * Total Submissions: 986.4K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
 * inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) {
      return nullptr;
    }
    auto rootVal = preorder.front();
    auto root = new TreeNode{rootVal};

    if (inorder.size() == 1)
      return root;

    auto i =
        distance(inorder.begin(), find(inorder.begin(), inorder.end(), rootVal));

    auto leftInorder = vector<int>(inorder.begin(), inorder.begin() + i);
    auto rightInorder = vector<int>(inorder.begin() + i + 1, inorder.end());



    auto leftPreorder =
        vector<int>(preorder.begin() + 1, preorder.begin() + leftInorder.size() + 1);
    auto rightPreorder =
        vector<int>(preorder.begin() + leftInorder.size() + 1, preorder.end());

    root->left = buildTree(leftPreorder, leftInorder);
    root->right = buildTree(rightPreorder, rightInorder);

    return root;
  }
};
// @lc code=end
