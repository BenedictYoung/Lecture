/*
* 题目名称：Common Subsequence
* 题目来源：HDU 1159
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1159
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000 + 10;

char str1[MAXN];
char str2[MAXN];
int dp[MAXN][MAXN];

int main() {
    while (scanf("%s%s", str1 + 1, str2 +1) != EOF) {   //从下标1开始输入
        int n = strlen(str1 + 1);
        int m = strlen(str2 + 1);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0) {                 //边界情况初始化
                    dp[i][j] = 0;
                    continue;
                }
                if (str1[i] == str2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
