#include "MyHeaders.hpp"
#include <memory>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode.cn/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (38.34%)
 * Likes:    2420
 * Dislikes: 0
 * Total Accepted:    992.9K
 * Total Submissions: 2.6M
 * Testcase Example:  '[2,1,3]'
 *
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 *
 * 有效 二叉搜索树定义如下：
 *
 *
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [2,1,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：false
 * 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在[1, 10^4] 内
 * -2^31 <= Node.val <= 2^31 - 1
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
  vector<int> v;
  bool flag = false;
  auto traversal(unique_ptr<TreeNode> cur) {
    if (cur == nullptr)
      return;
    if (cur->left)
      traversal(make_unique<TreeNode>(*(cur->left)));
    if (!v.empty() && v.back() >= cur->val) {
      flag = true;
      return;
    }
    v.emplace_back(cur->val);
    if (cur->right)
      traversal(make_unique<TreeNode>(*(cur->right)));
  }
public:
  bool isValidBST(TreeNode *root) {
    traversal(make_unique<TreeNode>(*root));
    if (flag)
      return false;
    for (auto i = 1; i < v.size(); i++) {
      if (v[i - 1] >= v[i])
        return false;
    }
    return true;
  }
};
// @lc code=end
