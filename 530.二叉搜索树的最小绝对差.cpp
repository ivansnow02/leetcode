#include "MyHeaders.hpp"
#include <algorithm>
#include <limits>
#include <memory>
using namespace std;
/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (62.82%)
 * Likes:    584
 * Dislikes: 0
 * Total Accepted:    276.5K
 * Total Submissions: 439.9K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 *
 * 差值是一个正数，其数值等于两值之差的绝对值。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [4,2,6,1,3]
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,0,48,null,null,12,49]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目范围是 [2, 10^4]
 * 0 <= Node.val <= 10^5
 *
 *
 *
 *
 * 注意：本题与 783
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
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
  int getMinimumDifference(TreeNode *root) {
    traversal(make_unique<TreeNode>(*root));
    auto minn = numeric_limits<int>::max();
    for (auto i = 1; i < v.size(); i++) {
      minn = ranges::min(minn, abs(v[i] - v[i - 1]));
    }
    return minn;
  }
};
// @lc code=end
