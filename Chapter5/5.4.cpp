/*
* 题目名称：Zero-complexity Transposition
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/AiKa20bt
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<long long> sequence;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        while (n--) {
            long long number;
            scanf("%lld", &number);
            sequence.push(number);
        }
        while (!sequence.empty()) {
            printf("%lld ", sequence.top());
            sequence.pop();
        }
        printf("\n");
    }
    return 0;
}
