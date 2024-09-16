#include "MyHeaders.hpp"
#include <memory>
using namespace std;
/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode.cn/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (73.34%)
 * Likes:    593
 * Dislikes: 0
 * Total Accepted:    269.1K
 * Total Submissions: 366.8K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 *
 * 假设二叉树中至少有一个节点。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: root = [2,1,3]
 * 输出: 1
 *
 *
 * 示例 2:
 *
 * ⁠
 *
 *
 * 输入: [1,2,3,4,null,5,6,null,null,7]
 * 输出: 7
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [1,10^4]
 * -2^31  
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
  struct Node {
    unique_ptr<TreeNode> node;
    int depth;
  };

public:
  int findBottomLeftValue(TreeNode *root) {

    int maxDepth = 1;
    int res = root->val;
    queue<shared_ptr<Node>> st;
    st.emplace(make_shared<Node>(Node{make_unique<TreeNode>(*root), 1}));
    while (!st.empty()) {
      auto cur = st.front();
      st.pop();
      if (cur->node == nullptr) {
        continue;
      }
      if (maxDepth < cur->depth) {
        maxDepth = cur->depth;
        res = cur->node->val;
      }
      if (cur->node->left) {
        st.emplace(make_shared<Node>(
            Node{make_unique<TreeNode>(*(cur->node->left)), cur->depth + 1}));
      }
      if (cur->node->right) {
        st.emplace(make_shared<Node>(
            Node{make_unique<TreeNode>(*(cur->node->right)), cur->depth + 1}));
      }
    }
    return res;
  }
};
// @lc code=end
