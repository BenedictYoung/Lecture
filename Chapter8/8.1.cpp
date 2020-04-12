/*
* 题目名称：n的阶乘
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/Ai0ocOUY
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

long long Factorial(int n) {            //递归函数
    if (n == 0) {                       //递归出口
        return 1;
    } else {                            //递归调用
        return n * Factorial(n - 1);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", Factorial(n));
    }
    return 0;
}
