/*
* 题目名称：XXX定律
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/E937wDs
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        int step = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = (3 * n + 1) / 2;
            }
            step++;
        }
        printf("%d\n", step);
    }
}
