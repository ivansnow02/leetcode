// 错误票据

// 题目描述
// 某涉密单位下发了某种票据，并要在年终全部收回。
// 每张票据有唯一的ID号。全年所有票据的ID号是连续的，但ID的开始数码是随机选定的。
// 因为工作人员疏忽，在录入ID号的时候发生了一处错误，造成了某个ID断号，另外一个ID重号。
// 你的任务是通过编程，找出断号的ID和重号的ID。
// 假设断号不可能发生在最大和最小号。

// 输入描述
// 要求程序首先输入一个整数N (N<100)表示后面数据行数。
// 接着读入N行数据。
// 每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于10^5）。

// 输出描述
// 要求程序输出1行，含两个整数m, n，用空格分隔。
// 其中，m表示断号ID，n表示重号ID。

// 输入输出样例
// 示例
// 输入
// 2
// 5 6 8 11 9
// 10 12 9
// 输出
// 7 9

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N;
vector<int> ids;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    cin >> N;
    cin.ignore(); // 忽略输入缓冲区中的换行符

    ids.reserve(105);

    while (N--) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        int t;
        while (iss >> t) {
            ids.emplace_back(t);
        }
    }

    sort(ids.begin(), ids.end());
    int m, n;


    for (int i = 0; i < ids.size() - 1; i++) {


        if (ids[i] == ids[i + 1]) {
            n = ids[i];
        } else if (ids[i] != ids[i + 1] - 1) {
            m = ids[i] + 1;
        }
    }

    cout << m << ' ' << n;
}
