/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=20003
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (60.87%)
 * Likes:    2945
 * Dislikes: 0
 * Total Accepted:    980.4K
 * Total Submissions: 1.6M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * 示例 2：
 *
 * 输入：digits = ""
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
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
    string s;
    vector<string> ans;
    vector<string> map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backTrack(const string &digits, int depth) {
        if (depth == digits.size()) {
            ans.emplace_back(s);
            return;
        }
        string letters = map[digits[depth] - '0'];
        for (auto x: letters) {
            s.push_back(x);
            backTrack(digits, depth + 1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        s.clear();
        ans.clear();
        if (digits.size() == 0) {
            return ans;
        }
        backTrack(digits, 0);
        return ans;
    }

};
// @lc code=end


/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */
