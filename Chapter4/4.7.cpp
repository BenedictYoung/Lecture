/*
* 题目名称：Oulipo
* 题目来源：POJ 3461
* 题目链接：http://poj.org/problem?id=3461
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXM = 10000 + 10;

int nextTable[MAXM];

void GetNextTable(string pattern) {                  //创建next表
    int m = pattern.size();
    int j = 0;
    nextTable[j] = -1;
    int t = nextTable[j];
    while (j < m) {
        if (t == -1 || pattern[j] == pattern[t]) {
            j++;
            t++;
            nextTable[j] = t;
        } else {
            t = nextTable[t];
        }
    }
    return ;
}

int KMP(string text, string pattern) {
    GetNextTable(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = 0;
    int j = 0;
    int number = 0;                             //记录匹配次数
    while (i < n) {
        if (j == -1 || text[i] == pattern[j]) {	//当前字符匹配成功
            i++;
            j++;
        } else {
            j = nextTable[j];					//当前字符匹配失败
        }
        if (j == m) {                           //模式串匹配成功
            number++;
            j = nextTable[j];
        }
    }
    return number;
}

int main() {
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--) {
        string pattern, text;
        cin >> pattern >> text;
        printf("%d\n", KMP(text, pattern));
    }
    return 0;
}
