/*
* 题目名称：素数判断
* 题目来源：哈尔滨工业大学复试上机题
* 题目链接：http://t.cn/AiCuWE0Q
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool Judge(int x) {                     //判断是否为质数
    if (x < 2) {                        //小于2必定不是
        return false;
    }
    int bound = sqrt(x);                //确定判断上界
    for (int i = 2; i <= bound; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (Judge(n)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
