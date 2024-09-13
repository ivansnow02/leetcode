#include "MyHeaders.hpp"
#include <cstddef>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 *
 * https://leetcode.cn/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (48.61%)
 * Likes:    1090
 * Dislikes: 0
 * Total Accepted:    229.2K
 * Total Submissions: 471.3K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 *
 *
 * 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot
 * 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
 *
 * 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree
 * 也可以看做它自身的一棵子树。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,4,5,1,2], subRoot = [4,1,2]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * root 树上的节点数量范围是 [1, 2000]
 * subRoot 树上的节点数量范围是 [1, 1000]
 * -10^4 <= root.val <= 10^4
 * -10^4 <= subRoot.val <= 10^4
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
  auto compare(TreeNode *r, TreeNode *l) {
    if (l == nullptr && r == nullptr)
      return true;
    else if (l != nullptr && r == nullptr)
      return false;
    else if (l == nullptr && r != nullptr)
      return false;
    else if (l->val != r->val)
      return false;

    return compare(l->left, r->left) && compare(l->right, r->right);
  }
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr && subRoot == nullptr)
      return true;

    stack<TreeNode *> st;
    st.emplace(root);
    while (!st.empty()) {
      auto cur = st.top();
      st.pop();
      if (cur == nullptr)
        continue;
      if (cur->val == subRoot->val) {
        if (compare(cur, subRoot)) {
          return true;
        }
      }
      if (cur->left)
        st.emplace(cur->left);
      if (cur->right)
        st.emplace(cur->right);
    }
    return false;
  }
};
// @lc code=end
