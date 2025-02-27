// 第几个幸运数字

// 题目描述
// 本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

// 到 X 星球旅行的游客都被发给一个整数，作为游客编号。

// X 星的国王有个怪癖，他只喜欢数字 3, 5 和 7。

// 国王规定，游客的编号如果只含有因子：3, 5, 7，就可以获得一份奖品。

// 我们来看前 10 个幸运数字是：
// 3, 5, 7, 9, 15, 21, 25, 27, 35, 45

// 因而第 11 个幸运数字是：49

// 小明领到了一个幸运数字 59084709587505，他去领奖的时候，人家要求他准确地说出这是第几个幸运数字，否则领不到奖品。

// 请你帮小明计算一下，59084709587505 是第几个幸运数字。

#include <algorithm>
#include <cmath>
#include <iostream>
#include <mutex>
#include <set>
#include <thread>
#include <vector>
using namespace std;
using i64 = long long;

const i64 TARGET = 59084709587505LL;
const i64 MAX_VALUE = TARGET + 1; // 我们只需要计算到目标值

mutex mtx;
set<i64> nums;

// 检查数字是否超出范围并添加到集合
void add_number(i64 num) {
    if (num <= MAX_VALUE) {
        lock_guard<mutex> lock(mtx);
        nums.insert(num);
    }
}

// 计算a的b次方，带溢出检查
i64 safe_pow(i64 a, int b, i64 limit) {
    i64 result = 1;
    for (int i = 0; i < b; ++i) {
        if (result > limit / a) // 检查乘法是否会溢出
            return limit + 1;
        result *= a;
    }
    return result;
}

// 工作函数，处理3^i的一部分范围
void worker(int start_i, int end_i) {
    for (int i = start_i; i <= end_i; i++) {
        i64 pow3 = safe_pow(3, i, MAX_VALUE);
        if (pow3 > MAX_VALUE)
            break;

        for (int j = 0;; j++) {
            i64 pow5 = safe_pow(5, j, MAX_VALUE);
            if (pow3 * pow5 > MAX_VALUE || pow5 > MAX_VALUE / pow3)
                break;

            for (int k = 0;; k++) {
                i64 pow7 = safe_pow(7, k, MAX_VALUE);

                if (pow7 > MAX_VALUE / (pow3 * pow5) || pow7 > MAX_VALUE)
                    break;

                i64 num = pow3 * pow5 * pow7;
                if (num > MAX_VALUE)
                    break;

                add_number(num);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 计算大致的上限
    int max_i = static_cast<int>(log(MAX_VALUE) / log(3)) + 1;

    // 创建线程数（根据CPU核心数调整）
    const int num_threads = thread::hardware_concurrency() ? thread::hardware_concurrency() : 4;
    vector<thread> threads;

    // 划分任务
    int chunk_size = (max_i + num_threads - 1) / num_threads;

    for (int t = 0; t < num_threads; t++) {
        int start_i = t * chunk_size;
        int end_i = min((t + 1) * chunk_size - 1, max_i);

        if (start_i <= end_i) {
            threads.emplace_back(worker, start_i, end_i);
        }
    }

    // 等待所有线程完成
    for (auto &t: threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    // 查找目标值的位置
    auto it = nums.find(TARGET);
    if (it != nums.end()) {
        int index = distance(nums.begin(), it);
        cout << index << endl;
    } else {
        cout << TARGET << " 不是幸运数字" << endl;
    }

    return 0;
}
