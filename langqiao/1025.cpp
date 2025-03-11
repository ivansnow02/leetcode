// 题目描述
// 有 n 位同学同时找老师答疑。每位同学都预先估计了自己答疑的时间。

// 老师可以安排答疑的顺序，同学们要依次进入老师办公室答疑。 一位同学答疑的过程如下：

// 首先进入办公室，编号为 i 的同学需要 si 毫秒的时间。
// 然后同学问问题老师解答，编号为 i 的同学需要 ai 毫秒的时间。
// 答疑完成后，同学很高兴，会在课程群里面发一条消息，需要的时间可以忽略。
// 最后同学收拾东西离开办公室，需要 ei 毫秒的时间。一般需要 10 秒、20 秒或 30 秒，即 ei 取值为 10000，20000 或 30000。
// 一位同学离开办公室后，紧接着下一位同学就可以进入办公室了。

// 答疑从 0 时刻开始。老师想合理的安排答疑的顺序，使得同学们在课程群里面发消息的时刻之和最小。

// 输入描述
// 输入第一行包含一个整数 n，表示同学的数量。

// 接下来 n 行，描述每位同学的时间。其中第 i 行包含三个整数 si, ai, ei，意义如上所述。

// 其中有 1 ≤ n ≤ 1000，1 ≤ si ≤ 60000，1 ≤ ai ≤ 10^6，ei ∈ 10000, 20000, 30000，即 ei 一定是 10000、20000、30000 之一。

// 输出描述
// 输出一个整数，表示同学们在课程群里面发消息的时刻之和最小是多少。

// 输入输出样例
// 示例
// 输入
// 3
// 10000 10000 10000
// 20000 50000 20000
// 30000 20000 30000

// 输出
// 280000

// 证明：
// 假设同学 i 进入办公室的时间于解答时间的和为 Ai , 离开办公室的时间为 Bi
// 对于同学 1 与同学 2 而言，所用时间为：
// A1, B1
// A2, B2
// 若同学 1 先进教室，则答案为 ans1 = (A1) + (A1 + B1 + A2)
// 若同学 2 先进教室，则答案为 ans2 = (A2) + (A2 + B2 + A1)
// 可以发现 ans1 与 ans2 的关系等同于 (A1 + B1) 与 (A2 + B2) 的关系
// 所以：每名同学进入教室的优先级只与其所消耗的时间和有关，和越小，优先级越高

#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

using i64 = long long;
struct Student {
    i64 s, a, e;
};
vector<Student*> students;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    i64 n;
    cin >> n;

    students.resize(n);

    for (int i = 0; i < n; i++) {
        students[i] = new Student();
        cin >> students[i]->s >> students[i]->a >> students[i]->e;
    }


    sort(students.begin(), students.end(), [](auto a, auto b) { return (a->s + a->a + a->e) < (b->s + b->a + b->e); });
    // cout << "------------------students-----------------------\n";

    // for (int i = 0; i < n; i++) {
    //    cout << students[i]->s << ' '<< students[i]->a <<' '<< students[i]->e<<endl;
    // }

    // cout << endl;
    i64 ans = students[0]->s + students[0]->a;
    i64 sum = ans;
    for (int i = 1; i < n; i++) {
        ans += students[i - 1]->e + students[i]->s + students[i]->a;
        sum += ans;
    }

    cout << sum << endl;

}
