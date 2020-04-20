/*
* 题目名称：最大上升子序列和
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiYNAGD3
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000 + 10;

int arr[MAXN];
int dp[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = arr[i];                 //初始化为arr[i]
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            answer = max(answer, dp[i]);    //dp数组的最大值
        }
        printf("%d\n", answer);
    }
    return 0;
}
