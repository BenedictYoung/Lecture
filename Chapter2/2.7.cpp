/*
* 题目名称：打印日期
* 题目来源：华中科技大学复试上机题
* 题目链接: http://t.cn/E9YP2a8
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int dayTable[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year, month, day;
    int number;                                 //记录天数
    while (scanf("%d%d", &year, &number) != EOF) {
        month = 0;                              //初始化月
        int row = IsLeapYear(year);
        while (number > dayTable[row][month]) { //确定月
            number -= dayTable[row][month];
            month++;
        }
        day = number;                           //确定日
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}
