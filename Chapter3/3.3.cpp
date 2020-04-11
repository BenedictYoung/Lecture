/*
* 题目名称：成绩排序
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9gyHM1
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;

struct Student {
    string name;                                    //姓名
    int score;                                      //成绩
    int order;                                      //次序
};

Student arr[MAXN];

bool CompareDescending(Student x, Student y) {      //降序比较函数
    if (x.score == y.score) {                       //成绩相等比较次序
        return x.order < y.order;
    } else {                                        //成绩不等比较成绩
        return x.score > y.score;
    }
}

bool CompareAscending(Student x, Student y) {       //升序比较函数
    if (x.score == y.score) {                       //成绩相等比较次序
        return x.order < y.order;
    } else {                                        //成绩不等比较成绩
        return x.score < y.score;
    }
}

int main() {
    int n;
    int type;
    while (scanf("%d%d", &n, &type) != EOF) {
        for (int i = 0; i < n; ++i) {
            cin >> arr[i].name >> arr[i].score;
            arr[i].order = i;
        }
        if (type == 0) {                            //选择比较函数
            sort(arr, arr + n, CompareDescending);
        } else {
            sort(arr, arr + n, CompareAscending);
        }
        for (int i = 0; i < n; ++i) {
            cout << arr[i].name << " " << arr[i].score << endl;
        }
    }
    return 0;
}
