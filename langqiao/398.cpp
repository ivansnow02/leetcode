// 瑞士轮

// 题目描述
// 在双人对决的竞技性比赛，如乒乓球、羽毛球、国际象棋中，最常见的赛制是淘汰赛和循环赛。前者的特点是比赛场数少，每场都紧张刺激，但偶然性较高。后者的特点是较为公平，偶然性较低，但比赛过程往往十分冗长。

// 本题中介绍的瑞士轮赛制，因最早使用于 1895
// 年在瑞士举办的国际象棋比赛而得名。它可以看作是淘汰赛与循环赛的折衷，既保证了比赛的稳定性，又能使赛程不至于过长。

// 2 * N 名编号为 1 到 2N 的选手共进行 R
// 轮比赛。每轮比赛开始前，以及所有比赛结束后，都会按照总分从高到低对选手进行一次排名。选手的总分为第一轮开始前的初始分数加上已参加过的所有比赛的得分和。总分相同的，约定编号较小的选手排名靠前。

// 每轮比赛的对阵安排与该轮比赛开始前的排名有关：第 1 名和第 2 名、第 3 名和第 4 名、......、第 2K−1 名和第 2K
// 名、...... 、第 2N−1 名和第 2N 名，各进行一场比赛。每场比赛胜者得 1 分，负者得 0
// 分。也就是说除了首轮以外，其它轮比赛的安排均不能事先确定，而是要取决于选手在之前比赛中的表现。

// 现给定每个选手的初始分数及其实力值，试计算在 R 轮比赛过后，排名第 Q
// 的选手编号是多少。我们假设选手的实力值两两不同，且每场比赛中实力值较高的总能获胜。

// 输入描述
// 输入的第一行是三个正整数 N、R、Q，每两个数之间用一个空格隔开，表示有 2 * N 名选手、R 轮比赛，以及我们关心的名次 Q。

// 第二行是 2 * N 个非负整数 s1, s2, ..., s2N，每两个数之间用一个空格隔开，其中 si 表示编号为 i 的选手的初始分数。

// 第三行是 2 * N 个正整数 w1, w2, ..., w2N，每两个数之间用一个空格隔开，其中 wi 表示编号为 i 的选手的实力值。

// 其中，1 ≤ N ≤ 10^5，1 ≤ R ≤ 50，1 ≤ Q ≤ 2N，0 ≤ s1, s2, ..., s2N ≤ 10^8，1 ≤ w1, w2, ..., w2N ≤ 10^8。

// 输出描述
// 输出只有一行，包含一个整数，即 R 轮比赛结束后，排名第 Q 的选手的编号。

// 输入输出样例
// 示例
// 输入
// 2 4 2
// 7 6 6 7
// 10 5 20 15

// 输出
// 1

#include <bits/stdc++.h>
#include <functional>
#include <vector>

using namespace std;

using i64 = long long;

// 2*N gamers
i64 N;
// R rounds
i64 R;
// Qth gamer
i64 Q;

struct Gamer {
    i64 id;
    i64 score;
    i64 power;
    // Gamer(i64 id = 0, i64 s = 0, i64 p = 0) : id(id), score(s), power(p) {}
    void compete_with(Gamer *a) {
        if (this->power > a->power) {
            this->score++;
        } else {
            a->score++;
        }
    }
};

vector<Gamer *> gamers;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N >> R >> Q;
    gamers.resize(2 * N + 1);

    for (int i = 1; i <= 2 * N; i++) {
        gamers[i] = new Gamer();
        gamers[i]->id = i;
        cin >> gamers[i]->score;
    }
    for (int i = 1; i <= 2 * N; i++) {
        cin >> gamers[i]->power;
    }

    auto sort_gamers = []() {
        sort(gamers.begin() + 1, gamers.end(), [](Gamer *a, Gamer *b) {
            if (a->score == b->score) {
                return a->id < b->id;
            }
            return a->score > b->score;
        });
    };


    sort_gamers();
    auto competition = []() {
        for (int i = 1; i <= 2 * N - 1; i += 2) {
            gamers[i]->compete_with(gamers[i + 1]);
        }
    };

    for (int i = 0; i < R; i++) {
        competition();
        sort_gamers();
    }

    cout << gamers[Q]->id;
}
