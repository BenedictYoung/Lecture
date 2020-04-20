/*
* 题目名称：复数集合
* 题目来源：北京邮电大学复试上机题
* 题目链接：http://t.cn/Ai98yYlt
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

struct Complex {
    int real;                                   //实部
    int imag;                                   //虚部
    Complex(int r, int i): real(r), imag(i) {}
    bool operator< (Complex c) const {          //重载小于号
        if (real * real + imag * imag == c.real * c.real + c.imag * c.imag) {
            return imag > c.imag;
        } else {
            return real * real + imag * imag < c.real * c.real + c.imag * c.imag;
        }
    }
};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        priority_queue<Complex> myPriorityQueue;
        while (n--) {
            string str;
            cin >> str;
            if (str == "Pop") {
                if (myPriorityQueue.empty()) {
                    printf("empty\n");
                } else {
                    Complex current = myPriorityQueue.top();
                    myPriorityQueue.pop();
                    printf("%d+i%d\n", current.real, current.imag);
                    printf("SIZE = %d\n", myPriorityQueue.size());
                }
            } else {
                int a, b;
                scanf("%d+i%d", &a, &b);
                myPriorityQueue.push(Complex(a, b));
                printf("SIZE = %d\n", myPriorityQueue.size());
            }
        }
    }
    return 0;
}
