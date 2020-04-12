/*
* 题目名称：计算两个矩阵的乘积
* 题目来源：北京邮电大学复试上机题
* 题目链接：http://t.cn/Aip4T3HX
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100;

struct Matrix {
    int matrix[MAXN][MAXN];
    int row, col;
    Matrix(int r, int c) : row(r), col(c) {}
};

Matrix Multiply(Matrix x, Matrix y) {           //矩阵乘法
    Matrix answer(x.row, y.col);
    for (int i = 0; i < answer.row; ++i) {
        for (int j = 0; j < answer.col; ++j) {
            answer.matrix[i][j] = 0;
            for (int k = 0; k < x.col; ++k) {
                answer.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
            }
        }
    }
    return answer;
}

Matrix FastExponentiation(Matrix x, int k) {    //矩阵快速幂
    Matrix answer(x.row, x.col);
    for (int i = 0; i < answer.row; ++i) {      //初始化为单位矩阵
        for (int j = 0; j < answer.col; ++j) {
            if (i == j) {
                answer.matrix[i][j] = 1;
            } else {
                answer.matrix[i][j] = 0;
            }
        }
    }
    while (k != 0) {
        if (k % 2 == 1) {                       //不断将k转换为二进制
            answer = Multiply(answer, x);
        }
        k /= 2;
        x = Multiply(x, x);                     //x不断平方
    }
    return answer;
}

void InputMatrix(Matrix &x) {                   //矩阵输入
     for (int i = 0; i < x.row; ++i) {
        for (int j = 0; j < x.col; ++j) {
            scanf("%d", &x.matrix[i][j]);
        }
    }
}

void OutputMatrix(Matrix x) {                   //矩阵输出
    for (int i = 0; i < x.row; ++i) {
        for (int j = 0; j < x.col; ++j) {
            if (j == 0) {
                printf("%d", x.matrix[i][j]);
            } else {
                printf(" %d", x.matrix[i][j]);
            }
        }
        printf("\n");
    }
    return ;
}

int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        Matrix x(n, n);
        InputMatrix(x);
        Matrix answer = FastExponentiation(x, k);
        OutputMatrix(answer);
    }
    return 0;
}
