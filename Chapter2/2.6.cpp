/*
* 题目名称：今年的第几天？
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9jXK5A
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int dayTable[2][13] = {                     //预处理
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool IsLeapYear(int year) {            		//判断是否为闰年
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year, month, day;
    while (scanf("%d%d%d", &year, &month, &day) != EOF) {
        int number = 0;            			//记录天数
        int row = IsLeapYear(year);         //判断用哪一行
        for (int j = 0; j < month; ++j) {   //逐月添加天数
            number += dayTable[row][j];
        }
        number += day;
        printf("%d\n", number);
    }
    return 0;
}
