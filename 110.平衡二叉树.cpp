#include "MyHeaders.hpp"
#include <cstddef>
using namespace std;
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode.cn/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (58.69%)
 * Likes:    1548
 * Dislikes: 0
 * Total Accepted:    646.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是 平衡二叉树  
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4 <= Node.val <= 10^4
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
  // 后序遍历
  auto getHeight(TreeNode *cur) -> int {
    if (cur == nullptr) return 0; //!
    auto lHeight = getHeight(cur->left);
    if (lHeight == -1)
      return -1;
    auto rHeight = getHeight(cur->right);
    if (rHeight == -1)
      return -1;

    if (abs(lHeight - rHeight) > 1)
      return -1;
    return 1 + max(lHeight, rHeight);
  }

public:
  bool isBalanced(TreeNode *root) {

    auto flag = getHeight(root);
    return flag != -1;
}
};
// @lc code=end
