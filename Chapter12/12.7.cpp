/*
* 题目名称：点菜问题
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiYOrkXr
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000 + 10;

int dp[MAXN];
int value[MAXN];                        //物品价值
int weight[MAXN];                       //物品重量

int main() {
    int n, m;                           //n件物品，m容量的背包
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &weight[i], &value[i]);
        }
        for (int i = 0; i <= m; ++i) {
            dp[i] = 0;                      //初始化
        }
        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= weight[i]; --j) {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}

