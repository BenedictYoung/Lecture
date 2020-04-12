/*
* 题目名称：鸡兔同笼
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/E9ewERU
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int a;
    while (scanf("%d", &a) != EOF) {
        int minimum = 0;
        int maxmum = 0;
        if (a % 2 == 0) {                       //偶数才有解
            minimum = a / 4 + (a % 4) / 2;
            maxmum = a / 2;
        }
        printf("%d %d\n", minimum, maxmum);
    }
    return 0;
}
