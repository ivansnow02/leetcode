
// 问题描述
// 在蓝桥学院的新餐厅，学生们在取餐窗口形成了一条长队。小蓝，餐厅的经理，希望能够实时了解队伍最前面和最后面的学生编号。

// 你需要执行以下三种操作：

// 学生进入队列：编号为 x 的学生排到队伍的末尾。
// 学生离开队列：最前面的学生拿到餐后离开队伍。
// 查询队列状态：输出当前队伍最前面和最后面的学生编号（两个编号之间用一个空格隔开）。
// 请注意，学生们可能会在吃完饭后再次排队。

// 输入格式
// 首先，你会看到一个整数 q，表示你需要执行的操作次数。

// 接下来的 q 行，每行将包含一个或两个整数，代表一次操作：

// 1 x：编号为 x 的学生加入队伍。
// 2：最前面的学生拿到餐并离开队伍。
// 3：输出当前队伍最前面和最后面的学生编号（两个编号之间用一个空格隔开）。
// 数据范围保证：1 ≤ x, q ≤ 10^5。进行操作 2 和 3 时，队伍一定非空。每个学生的编号都是唯一的。

// 输出格式
// 对于每一次的 3 操作，输出一行包含两个整数，即当前队伍最前面和最后面的学生编号。

// 样例输入
// 5
// 1 1
// 1 3
// 3
// 2
// 3

// 样例输出
// 1 3
// 3 3

// 说明
// 对于给出的样例，队伍的变化过程如下：

// 编号为 1 的学生加入队伍，队列变为 q=[1]。
// 编号为 3 的学生加入队伍，队列变为 q=[1, 3]。
// 输出队伍最前面和最后面的学生编号，分别为 1 和 3。
// 最前面的学生拿到餐并离开队伍，队列变为 q=[3]。
// 输出队伍最前面和最后面的学生编号，分别为 3 和 3。

#include <bits/stdc++.h>


using namespace std;

queue<int> q;

void enter_queue(const int &x) { q.emplace(x); }
void leave_queue() { q.pop(); }
void display_queue() { cout << q.front() << ' ' << q.back() << endl; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;

    cin >> t;

    while (t--) {

        int x;

        cin >> x;

        switch (x) {
            case 1: {
                int tx;
                cin >> tx;
                enter_queue(tx);
                break;
            }
            case 2: {
                leave_queue();
                break;
            }
            case 3: {
                display_queue();
                break;
            }
        }

    }
}
