/*
* 题目名称：猫狗收容所
* 题目来源：程序员面试金典
* 题目链接：无
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct animal {
    int number;                                     //动物编号
    int order;                                      //收容次序
    animal(int n, int o): number(n), order(o) {}
};

queue<animal> cats;
queue<animal> dogs;

int main() {
    int n;
    scanf("%d", &n);
    int order = 0;
    for (int i = 0; i < n; ++i) {
        int event;
        scanf("%d", &event);
        if (event == 1) {
            int number;                             //动物编号
            scanf("%d", &number);
            if (0 < number) {
                dogs.push(animal(number, order++));
            } else {
                cats.push(animal(number, order++));
            }
        } else {
            int type;                               //收养方式
            scanf("%d", &type);
            if (type == 0 && !dogs.empty() && !cats.empty()) {
                if (dogs.front().order < cats.front().order) {
                    printf("%d ", dogs.front().number);
                    dogs.pop();
                } else {
                    printf("%d ", cats.front().number);
                    cats.pop();
                }
            } else if (type == 0 && dogs.empty() && !cats.empty()) {
                printf("%d ", cats.front().number);
                cats.pop();
            } else if (type == 0 && !dogs.empty() && cats.empty()) {
                printf("%d ", dogs.front().number);
                dogs.pop();
            } else if (type == 1 && !dogs.empty()) {
                printf("%d ", dogs.front().number);
                dogs.pop();
            } else if (type == -1 && !cats.empty()) {
                printf("%d ", cats.front().number);
                cats.pop();
            }
        }
    }
    printf("\n");
    return 0;
}
