/*
* 题目名称：Catch That Cow
* 题目来源：POJ 3278
* 题目链接：http://poj.org/problem?id=3278
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 10;

bool visit[MAXN];

struct Status {
    int position;
    int time;
    Status(int p, int t): position(p), time(t) {}
};

int BFS(int n, int k) {
    queue<Status> myQueue;
    myQueue.push(Status(n, 0));             //压入初始状态
    visit[n] = true;                        //起点已访问
    int answer = 0;
    while (!myQueue.empty()) {
        Status current = myQueue.front();
        myQueue.pop();
        if (current.position == k) {        //查找成功
            answer = current.time;
        }
        for (int i = 0; i < 3; ++i) {       //转入不同状态
            Status next = current;
            if (i == 0) {
                next.position += 1;
            } else if (i == 1) {
                next.position -= 1;
            } else {
                next.position *= 2;
            }
            if (next.position < 0 || next.position >= MAXN || visit[next.position]) {
                continue;                   //新状态不合法
            }
            next.time++;
            myQueue.push(next);             //压入新的状态
            visit[next.position] = true;    //该点已访问
        }
    }
    return answer;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    memset(visit, false, sizeof(visit));
    printf("%d\n", BFS(n, k));
    return 0;
}
