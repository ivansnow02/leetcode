/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=20003
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (74.18%)
 * Likes:    1886
 * Dislikes: 0
 * Total Accepted:    477.2K
 * Total Submissions: 643.3K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 *
 *
 * 示例 2：
 *
 * 输入：s = "a"
 * 输出：[["a"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 16
 * s 仅由小写英文字母组成
 *
 *
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
private:
    vector<vector<string>> result;
    vector<string> ans;
    bool isPalindrome(const string &s) {
        for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void backTrack(const string &s, int start) {
        if (start == s.size()) {
            result.emplace_back(ans);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            string ss = s.substr(start, i - start + 1);
            ans.emplace_back(ss);
            if (isPalindrome(ss))
                backTrack(s, i + 1);
            ans.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        backTrack(s, 0);
        return result;
}
};
// @lc code=end


/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */
