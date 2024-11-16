/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=20003
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode.cn/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (60.40%)
 * Likes:    1461
 * Dislikes: 0
 * Total Accepted:    466.4K
 * Total Submissions: 772.2K
 * Testcase Example:  '"25525511135"'
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 *
 *
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
 * 和 "192.168@1.1" 是 无效 IP 地址。
 *
 *
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.'
 * 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 *
 *
 * 示例 2：
 *
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 *
 *
 * 示例 3：
 *
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 20
 * s 仅由数字组成
 *
 *
 */


// @lcpr-template-start
#include <cctype>
#include <string>
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
    vector<string> result;
    string path;
    bool restrain(string &ss, int l, int r) {
        string s = ss.substr(l, r - l + 1);
        if (s.empty()) {
            return false;
        }
        if (s[0] == '0' && s.size() > 1 || s.size() > 3) {
            return false;
        }
        for (auto c: s) {
            if (!isdigit(c)) {
                return false;
            }
        }
        if (s.size() == 3 && s > "255") {
            return false;
        }
        return true;
    }
    void backTrack(string &s, int start, int t) {
        if (t == 3) {
            if (restrain(s, start, s.size() - 1)) {
                result.emplace_back(s);
                return;
            }
        }

        for (int i = start; i < s.size(); i++) {

            s.insert(s.begin() + i + 1, '.');
            if (restrain(s, start, i)) {
                backTrack(s, i + 2, t + 1);
            }
            s.erase(s.begin() + i + 1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backTrack(s, 0, 0);
        return result;
    }
};
// @lc code=end


/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */
