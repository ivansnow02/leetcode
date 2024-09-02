#include "MyHeaders.hpp"
using namespace std;
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.08%)
 * Likes:    4523
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 4.3M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "()"
 *
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "()[]{}"
 *
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "(]"
 *
 * 输出：false
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "([])"
 *
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 *
 *
 */

// @lc code=start
class Solution {
private:
  stack<char> st;
  bool checkClose(char c) {
    if (st.empty())
      return false;
    char top = st.top();
    st.pop();
    if ((c == ')' && top == '(') || (c == ']' && top == '[') ||
        (c == '}' && top == '{')) {
      return true;
    }
    return false;
  }

public:
  bool isValid(string s) {
    for (auto c : s) {
      switch (c) {
      case '(':
      case '[':
      case '{':
        st.push(c);
        break;
      case ')':
      case ']':
      case '}':
        if (checkClose(c) == false)
          return false;
        break;
      }
    }
    return st.empty(); // 最后检查栈是否为空
  }
};
// @lc code=end
