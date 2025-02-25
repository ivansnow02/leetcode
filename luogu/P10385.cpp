// # [蓝桥杯 2024 省 A] 艺术与篮球

// ## 题目描述

// 小蓝出生在一个艺术与运动并重的家庭中。
// 妈妈是位书法家，她希望小蓝能通过练习书法，继承她的艺术天赋，并练就一手好字。爸爸是一名篮球教练，他希望小蓝能通过篮球锻炼身体，培养运
// 动的激情和团队合作的精神。
// 为了既满足妈妈的期望，又不辜负爸爸的心意，小蓝决定根据日期的笔画数来安排自己的练习。首先，他会将当天的日期按照
// `YYYYMMDD` 的格式 转换成一个 $8$ 位数，然后将这 $8$ 位数对应到汉字上，计算这些汉字的总笔画数。如果总笔画数超过
// $50$，他就去练习篮球；如果总笔画数不超过 $50$，他就去练习书法。 例如，在 $2024$ 年 $1$ 月 $1$
// 日这天，日期可表示为一个 $8$ 位数字 $20240101$，其转换为汉字是“二零二四零一零一”。日期的总笔画数为 $2 + 13 + 2 + 5 +
// 13 + 1 + 13 + 1 = 50$，因此在这天，小蓝会去练习书法。 以下是汉字的笔画数对照表：

// |汉字|笔画数|汉字|笔画数|
// | -----------: | -----------: | -----------: | -----------: |
// |零 |$13 $|五 |$4$|
// |一 |$1$|  六 |$4$|
// |二 |$2$|  七 |$2$|
// |三 |$3$|  八 |$2$|
// |四 |$5$| 九 |$2$|

// 现在，请你帮助小蓝统计一下，在 $2000$ 年 $1$ 月 $1$ 日到 $2024$ 年 $4$ 月 $13$ 日
// 这段时间内，小蓝有多少天是在练习篮球？

// ## 输入格式

// 这是一道结果填空题，你只需要算出结果后提交即可。本题的结果为一个整数，在提交答案时只填写这个整数，填写多余的内容将无法得分。

// ## 输出格式

// 这是一道结果填空题，你只需要算出结果后提交即可。本题的结果为一个整数，在提交答案时只填写这个整数，填写多余的内容将无法得分。

#include <cstddef>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// const vector NUMS = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};

// const vector DAYS = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// int calculateNum(int year, int month, int day) {
//     int res = 0;
//     string s = to_string(year);
//     auto sMonth = to_string(month);
//     if (sMonth.length() == 1) {
//         sMonth = '0' + sMonth;
//     }
//     auto sDay = to_string(day);
//     if (sDay.length() == 1) {
//         sDay = '0' + sDay;
//     }
//     s = s + sMonth + sDay;

//     for (auto c: s) {
//         res += NUMS[c - '0'];
//     }

//     return res;
// }

// bool isLeapYear(int year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }


int main() {
    ios::sync_with_stdio(false);

    // int year = 2000;
    // int month = 1;
    // int day = 1;

    // int ans = 0;
    // while (true) {
    //     if (year == 2024 && month == 4 && day == 13) {
    //         break;
    //     }

    //     auto n = calculateNum(year, month, day);
    //     if (n > 50) {
    //         ans++;
    //     }

    //     day++;

    //     int maxDay = (month == 2 && isLeapYear(year)) ? 29 : DAYS[month];
    //     if (day > maxDay) {
    //         day -= maxDay;
    //         month++;
    //     }

    //     if (month > 12) {
    //         month -= 12;
    //         year++;
    //     }
    // }
    // cout << ans;

    // cout << calculateNum(2024,01,01);
    cout << 3228;
}
