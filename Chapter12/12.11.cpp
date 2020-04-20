/*
* 题目名称：Monkey Banana Problem
* 题目来源：LightOJ 1004
* 题目链接：http://lightoj.com/volume_showproblem.php?problem=1004
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100 + 10;

int dp[2 * MAXN][MAXN];
int matrix[2 * MAXN][MAXN];

int main() {
    int caseNumber;
    scanf("%d", &caseNumber);
    for (int current = 1; current <= caseNumber; ++current) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                scanf("%d", &matrix[i][j]);
                dp[i][j] = matrix[i][j];
            }
        }
        for (int i = n; i < 2 * n - 1; ++i) {
            for (int j = 0; j <= 2 * (n - 1) - i; ++j) {
                scanf("%d", &matrix[i][j]);
                dp[i][j] = matrix[i][j];
            }
        }
        for (int i = 2 * (n - 1) - 1; i >= n - 1; --i) {
            for (int j = 0; j <= 2 * (n - 1) - i; ++j) {
                if (j == 0) {                           //最左端
                    dp[i][j] += dp[i + 1][j];
                } else if (j == 2 * (n - 1) - i) {      //最右端
                    dp[i][j] += dp[i + 1][j - 1];
                } else {
                    dp[i][j] += max(dp[i + 1][j], dp[i + 1][j - 1]);
                }
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        printf("Case %d: %d\n", current, dp[0][0]);
    }
    return 0;
}
