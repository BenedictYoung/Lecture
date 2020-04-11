/*
* 题目名称：叠筐
* 题目来源：HDU 2074
* 题目链接: http://acm.hdu.edu.cn/showproblem.php?pid=2074
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

const int MAXN = 80 + 10;

using namespace std;

char matrix[MAXN][MAXN];

int main() {
    int n; 								     	    //叠框大小
    char center;                                    //中心花色字符
    char outside;                                   //外筐花色字符
    bool firstCase = true;                          //第一组数据标志
    while (scanf("%d %c %c", &n, &center, &outside) != EOF) {
        if (firstCase == true) {
            firstCase = false;
        } else {
            printf("\n");
        }
        for (int i = 0; i <= n / 2; ++i) {  	    //(i, i)是每圈左上角坐标
            int j = n - i - 1;               		//(j, j)是每圈右下角坐标
            int length = n - 2 * i;               	//求当前圈的边长
            char current;                           //求当前圈填充字符
            if ((n / 2 - i) % 2 == 0) {
                current = center;
            } else {
                current = outside;
            }
            for (int k = 0; k < length; ++k) {    	//为当前圈赋值
                matrix[i][i + k] = current;         //上边赋值
                matrix[i + k][i] = current;         //左边赋值
                matrix[j][j - k] = current;         //下边赋值
                matrix[j - k][j] = current;         //右边赋值
            }
        }
        if (n != 1) {                           	//剔除4个角
            matrix[0][0] = ' ';
            matrix[0][n - 1] = ' ';
            matrix[n - 1][0] = ' ';
            matrix[n - 1][n - 1] = ' ';
        }
        for (int i = 0; i < n; ++i) {               //逐行逐列打印
            for (int j = 0; j < n; ++j) {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
