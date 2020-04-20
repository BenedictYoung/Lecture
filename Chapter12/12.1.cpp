/*
* 题目名称：N阶楼梯上楼问题
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/Aij9Fr3V
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 90 + 10;

long long dp[MAXN];

void Initial() {
    for (int i = 0; i < MAXN; ++i) {
        if (i == 0 || i == 1) {
            dp[i] = 1;
        } else {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    return ;
}

int main() {
    Initial();
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", dp[n]);
    }
    return 0;
}
