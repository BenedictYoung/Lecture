/*
* 题目名称：今年暑假不AC
* 题目来源：HDU 2037
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=2037
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Program {
    int startTime;
    int endTime ;
};

Program arr[MAXN];

bool Compare(Program x, Program y) {
    return  x.endTime < y.endTime;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &arr[i].startTime, &arr[i].endTime);
        }
        sort(arr, arr + n, Compare);                    //按结束时间升序排序
        int currentTime = 0;                            //设置当前时间
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            if (currentTime <= arr[i].startTime) {      //选择看这个节目
                currentTime = arr[i].endTime;
                answer++;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
