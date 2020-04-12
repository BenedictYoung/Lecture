/*
* 题目名称：最小公倍数
* 题目来源：HDU 1108
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1108
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", a * b / GCD(a, b));
    }
    return 0;
}
