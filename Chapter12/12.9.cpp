/*
* 题目名称：珍惜现在，感恩生活
* 题目来源：HDU 2191
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=2191
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

const int INF = INT_MAX / 10;
const int MAXN = 1e4 + 10;

int dp[MAXN];
int value[MAXN];                    //物品价值
int weight[MAXN];                   //物品重量
int amount[MAXN];                   //物品数目
int newValue[MAXN];                 //拆分后物品价值
int newWeight[MAXN];                //拆分后物品重量

int main() {
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--) {
        int n, m;
        scanf("%d%d", &m, &n);      //n件物品，m容量的背包
        int number = 0;             //分解后物品数量
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &weight[i], &value[i], &amount[i]);
            for (int j = 1; j <= amount[i]; j <<= 1) {
                newValue[number] = j * value[i];
                newWeight[number] = j * weight[i];
                number++;
                amount[i] -= j;
            }
            if (amount[i] > 0) {
                newValue[number] = amount[i] * value[i];
                newWeight[number] = amount[i] * weight[i];
                number++;
            }
        }
        for (int i = 0; i <= m; ++i) {
            dp[i] = 0;              //初始化
        }
        for (int i = 0; i < number; ++i) {
            for (int j = m; j >= newWeight[i]; --j) {
                dp[j] = max(dp[j], dp[j - newWeight[i]] + newValue[i]);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
