#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, V;
  cin >> V >> n;
  vector<int> items(n);
  for (int i = 0; i < n; i++) {
    cin >> items[i];
  }
  // // 从下标为[0-i]的物品里任意取，放进容量为j的背包剩余的空间
  // vector<vector<int>> dp(n, vector<int>(V + 1, V));

  // // 初始化
  // for (int j = 0; j <= V; j++) {
  //   if (j < items[0])
  //     dp[0][j] = j;
  //   else
  //     dp[0][j] = j - items[0];

  // }

  // for (int i = 1; i < n; i++) {
  //   for (int j = 0; j <= V; j++) {
  //     dp[i][j] = dp[i - 1][j]; // 不放
  //     if (j >= items[i]) {
  //       // 看看是不放i的空间小
  //       // 还是放i的空间小
  //       // 那么背包要先留出物品i的容量
  //       // 剩下j-items[i]的空间来放[0..i-1]的物品
  //       dp[i][j] = min(dp[i][j], dp[i - 1][j - items[i]]);
  //     }
  //   }
  // }

  // // for (auto x : dp) {
  // //   for (auto y : x)
  // //     cout << y << '|';
  // //   cout << endl;

  // // }

  // cout << dp[n - 1][V] << endl;


  // 1维dp
  vector<int> dp(V + 1, V); // 容量为j的背包所生育的最小空间

  for (int j = 0; j <= V; j++) {
    if (j < items[0])
      dp[j] = j;
    else
      dp[j] = j - items[0];
  }

  for (int i = 1; i < n; i++) {
    for (int j = V; j >= items[i]; j--) {
      dp[j] = min(dp[j], dp[j - items[i]]);
    }
  }

  cout << dp[V] << endl;

  return 0;
}
