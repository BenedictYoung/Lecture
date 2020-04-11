/*
* 题目名称：找X
* 题目来源：哈尔滨工业大学复试上机题
* 题目链接：http://t.cn/E9gHFnS
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 200 + 10;

int arr[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int x;
        scanf("%d", &x);
        int answer = -1;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == x) {
                answer = i;
                break;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
