/*
 * @lc app=leetcode.cn id=763 lang=cpp
 * @lcpr version=20004
 *
 * [763] 划分字母区间
 *
 * https://leetcode.cn/problems/partition-labels/description/
 *
 * algorithms
 * Medium (77.80%)
 * Likes:    1223
 * Dislikes: 0
 * Total Accepted:    295.2K
 * Total Submissions: 379.4K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
 *
 * 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
 *
 * 返回一个表示每个字符串片段的长度的列表。
 *
 *
 * 示例 1：
 *
 * 输入：s = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。
 *
 * 示例 2：
 *
 * 输入：s = "eccbbbbdec"
 * 输出：[10]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 500
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
public:
    vector<int> partitionLabels(string s) {
        int map[27] = {0};
        for (int i = 0; i < s.size(); i++) {
            map[s[i] - 'a'] = i;
        }
        vector<int> res;
        int r = 0, l = 0;

        for (int i = 0; i < s.size(); i++) {
            r = max(r, map[s[i] - 'a']);
            if (i == r) {

                res.emplace_back(r - l + 1);

                l = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end


/*
// @lcpr case=start
// "ababcbacadefegdehijhklij"\n
// @lcpr case=end

// @lcpr case=start
// "eccbbbbdec"\n
// @lcpr case=end

 */
