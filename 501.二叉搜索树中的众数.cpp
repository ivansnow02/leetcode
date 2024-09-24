#include "MyHeaders.hpp"
#include <limits>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (55.57%)
 * Likes:    771
 * Dislikes: 0
 * Total Accepted:    225.8K
 * Total Submissions: 406.1K
 * Testcase Example:  '[1,nullptr,2,2]'
 *
 * 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有
 * 众数（即，出现频率最高的元素）。
 *
 * 如果树中有不止一个众数，可以按 任意顺序 返回。
 *
 * 假定 BST 满足如下定义：
 *
 *
 * 结点左子树中所含节点的值 小于等于 当前节点的值
 * 结点右子树中所含节点的值 大于等于 当前节点的值
 * 左子树和右子树都是二叉搜索树
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,nullptr,2,2]
 * 输出：[2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 10^4] 内
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 *
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptrptr), right(nullptrptr) {}
 *     TreeNode(int x) : val(x), left(nullptrptr), right(nullptrptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  // private:
  //   unordered_map<int, int> umap;
  //   auto traversal(unique_ptr<TreeNode> cur) {
  //     if (cur == nullptrptr)
  //       return;
  //     if (cur->left)
  //       traversal(make_unique<TreeNode>(*(cur->left)));
  //     umap[cur->val]++;
  //     if (cur->right)
  //       traversal(make_unique<TreeNode>(*(cur->right)));
  //   }

  // public:
  //   vector<int> findMode(TreeNode *root) {
  //     vector<int> ans;
  //     if (root == nullptrptr)
  //       return ans;

  //     traversal(make_unique<TreeNode>(*root));
  //     vector<pair<int, int>> t(umap.begin(), umap.end());

  //     ranges::sort(t, [](auto x, auto y) { return x.second > y.second; });
  //     auto f = t.front().second;
  //     for (auto i :t) {
  //       if (i.second == f) {
  //         ans.emplace_back(i.first);
  //       }
  //     }
  //     return ans;
  //   }

private:
  int maxCount = 0; // 最大频率
  int count = 0;    // 统计频率
  TreeNode *pre = nullptr;
  vector<int> result;
  void searchBST(TreeNode *cur) {
    if (cur == nullptr)
      return;

    searchBST(cur->left); // 左
                          // 中
    if (pre == nullptr) { // 第一个节点
      count = 1;
    } else if (pre->val == cur->val) { // 与前一个节点数值相同
      count++;
    } else { // 与前一个节点数值不同
      count = 1;
    }
    pre = cur; // 更新上一个节点

    if (count == maxCount) { // 如果和最大值相同，放进result中
      result.emplace_back(cur->val);
    }

    if (count > maxCount) { // 如果计数大于最大值频率
      maxCount = count;     // 更新最大频率
      result.clear(); // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
      result.emplace_back(cur->val);
    }

    searchBST(cur->right); // 右
    return;
  }

public:
  vector<int> findMode(TreeNode *root) {
    count = 0;
    maxCount = 0;
    pre = nullptr; // 记录前一个节点
    result.clear();

    searchBST(root);
    return result;
  }
};
// @lc code=end
