/*
* 题目名称：日期累加
* 题目来源：北京理工大学复试上机题
* 题目链接：http://t.cn/E9Yw0Cr
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

int NumberOfYear(int year) {                    //返回该年天数
    if (IsLeapYear(year)) {
        return 366;
    } else {
        return 365;
    }
}

int main() {
    int year, month, day;
    int number;
    int caseNumber;                             //组数
    scanf("%d", &caseNumber);
    while (caseNumber--) {
        scanf("%d%d%d%d", &year, &month, &day, &number);
        int row = IsLeapYear(year);
        for (int j = 0; j < month; ++j) {
            number += dayTable[row][j];
        }
        number += day;
        while (number > NumberOfYear(year)) {   //确定年
            number -= NumberOfYear(year);
            year++;
        }
        month = 0;
        row = IsLeapYear(year);
        while (number > dayTable[row][month]) {
            number -= dayTable[row][month];
            month++;
        }
        day = number;
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}
