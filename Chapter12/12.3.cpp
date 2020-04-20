/*
* 题目名称：最大子矩阵
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiYSemJz
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

const int maxn = 100 + 10;
const int INF = INT_MAX;

int matrix[maxn][maxn];                     //原矩阵
int total[maxn][maxn];                      //辅助矩阵
int arr[maxn];                              //一维数组
int dp[maxn];


int MaxSubsequence(int n) {
    int maximum = -INF;
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

int MaxSubmatrix(int n) {
    int maximal = -INF;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            for (int k = 0; k < n; ++k) {   //获得一维数组
                if (i == 0) {
                    arr[k] = total[j][k];
                } else {
                    arr[k] = total[j][k] - total[i - 1][k];
                }
            }
            int current = MaxSubsequence(n);
            maximal = max(maximal, current);
        }
    }
    return maximal;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {       //初始化辅助函数
            for (int j = 0; j < n; ++j) {
                if (i == 0) {
                    total[i][j] = matrix[i][j];
                } else {
                    total[i][j] = total[i - 1][j] + matrix[i][j];
                }
            }
        }
        int answer = MaxSubmatrix(n);
        printf("%d\n", answer);
    }
    return 0;
}
