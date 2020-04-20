/*
* 题目名称：最大序列和
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AiYSlQMU
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

const int maxn = 1e6 + 10;
const int INF = INT_MAX;

long long arr[maxn];
long long dp[maxn];

long long MaxSubsequence(int n) {
    long long maximum = -INF;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[i] = arr[i];
        } else {
            dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        }
        maximum = max(maximum, dp[i]);
    }
    return maximum;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
        }
        long long answer = MaxSubsequence(n);
        printf("%lld\n", answer);
    }
    return 0;
}
