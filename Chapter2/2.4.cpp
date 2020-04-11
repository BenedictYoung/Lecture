/*
* 题目名称：输出梯形
* 题目来源：清华大学复试上机题
* 题目链接：无
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int h;
    while (scanf("%d", &h) != EOF) {
        int row = h;                        	//行数
        int col = h + (h - 1) * 2;       		//列数
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (j < col - (h + 2 * i)) {	//输出空格
                    printf(" ");
                } else {                        //输出星号
                    printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}

