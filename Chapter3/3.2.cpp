/*
* 题目名称：成绩排序
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9d3ysv
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Student {
    int number;                                     //学号
    int score;                                      //成绩
};

Student arr[MAXN];

bool Compare(Student x, Student y) {                //比较函数
    if (x.score == y.score) {                       //成绩相等比较学号
        return x.number < y.number;
    } else {                                        //成绩不等比较成绩
        return x.score < y.score;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &arr[i].number, &arr[i].score);
    }
    sort(arr, arr + n, Compare);                    //按照比较函数排序
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", arr[i].number, arr[i].score);
    }
    return 0;
}
