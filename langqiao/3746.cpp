// 问题描述
// 在一个阳光明媚的早晨，小桥收到了一份神秘的礼物——一只魔法盒子。这个盒子有四个按钮，每个按钮都有特殊的功能：

// 按钮 A：“添加”，将一个神秘物品（每个物品都有一个独特的编号）放入盒子中。
// 按钮 B：“移除”，将盒子中最早放入的物品移出。
// 按钮 C：“查看”，查看盒子中最早放入的物品。
// 按钮 D：“计数”，查看当前盒子中有多少个物品。
// 然而，如果盒子是空的，那么按钮 B 和按钮 C 就无法正常工作。此时，盒子会显示错误信息：
// 如果按下按钮 B，盒子会显示“lan”。如果按下按钮 C，盒子会显示“qiao”。

// 小桥需要你的帮助，他会给你一系列的按钮操作，你需要帮他解读盒子的反馈。

// 输入格式
// 第一行，一个整数 n，表示操作的次数。

// 接下来 n 行，每行表示一个操作。格式如下：

// “1 x”，表示按下按钮 A，将编号为 x 的物品放入盒子。
// “2”，表示按下按钮 B，移除一个物品。
// “3”，表示按下按钮 C，查看物品。
// “4”，表示按下按钮 D，查看物品个数。

// 输出格式
// 输出若干行，对于每个操作，按照上述盒子的反馈原则输出结果。

// 每条输出之间应当用空行隔开。

// 样例输入
// 7
// 3
// 2
// 4
// 3
// 3
// 3
// 2

// 样例输出
// qiao
// lan
// 0
// qiao
// qiao
// qiao
// lan

#include <bits/stdc++.h>
using namespace std;
queue<int> box;

// “1 x”，表示按下按钮 A，将编号为 x 的物品放入盒子。
auto put(const int& x) {
    box.emplace(x);
}
// “2”，表示按下按钮 B，移除一个物品。
auto erase() {
    if (box.empty()) {
        cout << "lan" << endl;
        return;
    }
    box.pop();
}
// “3”，表示按下按钮 C，查看物品。
auto display() {
    if (box.empty()) {
        cout << "qiao" << endl;
        return;
    }
    cout << box.front() << endl;
}
// “4”，表示按下按钮 D，查看物品个数。
auto amount() { cout << box.size() << endl; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int flag;
        cin >> flag;
        switch (flag) {
            case 1: {
                int x;
                cin >> x;
                put(x);
                break;
            }
            case 2: {
                erase();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                amount();
                break;
            }
        }
    }
}
