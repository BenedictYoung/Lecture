/*
* 题目名称：拦截导弹
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiYCeV3m
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 25 + 10;

int height[MAXN];                           //导弹高度
int dp[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &height[i]);
        }
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;                      //初始化为1
            for (int j = 0; j < i; ++j) {
                if (height[i] <= height[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            answer = max(answer, dp[i]);    //dp数组的最大值
        }
        printf("%d\n", answer);
    }
    return 0;
}
