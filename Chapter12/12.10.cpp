/*
* 题目名称：The Triangle
* 题目来源：POJ 1163
* 题目链接：http://poj.org/problem?id=1163
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100 + 10;

int dp[MAXN][MAXN];
int matrix[MAXN][MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            scanf("%d", &matrix[i][j]);
            dp[i][j] = matrix[i][j];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    printf("%d\n", dp[0][0]);
    return 0;
}
