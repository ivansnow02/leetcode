#include "MyHeaders.hpp"
#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.40%)
 * Likes:    1262
 * Dislikes: 0
 * Total Accepted:    415.6K
 * Total Submissions: 573.5K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历，
 * postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * 输出：[3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入：inorder = [-1], postorder = [-1]
 * 输出：[-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder 和 postorder 都由 不同 的值组成
 * postorder 中每一个值都在 inorder 中
 * inorder 保证是树的中序遍历
 * postorder 保证是树的后序遍历
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
  auto traversal(vector<int> &inorder, vector<int> &postorder) -> TreeNode * {

    if (postorder.empty())
      return nullptr;

    auto rootVal = postorder.back();
    postorder.pop_back();
    auto root = new TreeNode{rootVal};

    if (inorder.size() == 1) {
      return root;
    }

    auto it = find(inorder.begin(), inorder.end(), rootVal);
    auto i = distance(inorder.begin(), it);

    vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
    vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());

    auto leftPostorder =
        vector<int>(postorder.begin(), postorder.begin() + leftInorder.size());
    auto rightPostorder =
        vector<int>(postorder.begin() + leftInorder.size(), postorder.end());

    root->left = traversal(leftInorder, leftPostorder);
    root->right = traversal(rightInorder, rightPostorder);

    return root;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return traversal(inorder, postorder);
  }
};
// @lc code=end
