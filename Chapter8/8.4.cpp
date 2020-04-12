/*
* 题目名称：二叉树
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/Ai0Ke6I0
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int CountNodes(int m, int n) {
    if (m > n) {                    //递归出口
        return 0;
    } else {                        //递归调用
        return 1 + CountNodes(m * 2, n) + CountNodes(m * 2 + 1, n);
    }
}

int main() {
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        printf("%d\n", CountNodes(m, n));
    }
    return 0;
}
