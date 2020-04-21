/*
* 题目名称：Piggy-Bank
* 题目来源：HDU 1114
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1114
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

const int INF = INT_MAX / 10;
const int MAXN = 500 + 10;
const int MAXM = 1e4 + 10;

int dp[MAXM];
int value[MAXN];                        //物品价值
int weight[MAXN];                       //物品重量

int main() {
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--) {
        int e, f;
        scanf("%d%d", &e, &f);
        int m = f - e;                  //背包容量
        int n;                          //物品种类
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &value[i], &weight[i]);
        }
        for (int i = 1; i <= m; i++) {
            dp[i] = INF;                //注意初始化
        }
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = weight[i]; j <= m; ++j) {
                dp[j] = min(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        if (dp[m] == INF) {
            printf("This is impossible.\n");
        } else {
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[m]);
        }
    }
    return 0;
}
