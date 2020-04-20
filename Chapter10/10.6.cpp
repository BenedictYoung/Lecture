/*
* 题目名称：哈夫曼树
* 题目来源：北京邮电大学复试上机题
* 题目链接：http://t.cn/AiCuGMki
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        priority_queue<int, vector<int>, greater<int> > myPriorityQueue;
        while (n--) {
            int x;
            scanf("%d", &x);
            myPriorityQueue.push(x);
        }
        int answer = 0;
        while (1 < myPriorityQueue.size()) {
            int a = myPriorityQueue.top();
            myPriorityQueue.pop();
            int b = myPriorityQueue.top();
            myPriorityQueue.pop();
            answer += a + b;
            myPriorityQueue.push(a + b);
        }
        printf("%d\n", answer);
    }
    return 0;
}
