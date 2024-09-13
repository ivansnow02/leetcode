#include "MyHeaders.hpp"
using namespace std;
/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 *
 * https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (75.27%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    174.1K
 * Total Submissions: 231.3K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，找到其最大深度。
 *
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 *
 * N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [1,null,3,2,4,null,5,6]
 * 输出：3
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树的深度不会超过 1000 。
 * 树的节点数目位于 [0, 10^4] 之间。
 *
 *
 */

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

// @lc code=start

class Solution {
private:
  uint res;
  auto traversal(const Node *cur, const uint depth) {
    res = max(res, depth);
    if (cur == nullptr)
      return;
    for (const auto child : cur->children) {
      traversal(child, depth + 1);
    }
  }
public:
  int maxDepth(Node *root) {
    res = 0;
    if (root == nullptr)
      return 0;
    traversal(root, 1);
    return res;
  }
};
// @lc code=end
