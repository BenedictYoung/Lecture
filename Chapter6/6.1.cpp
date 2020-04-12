/*
* 题目名称：二进制数
* 题目来源：北京邮电大学复试上机题
* 题目链接：http://t.cn/AiCuKTOv
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<int> binary;
        if (n == 0) {
            binary.push_back(0);
        } else {
            while (n != 0) {
                binary.push_back(n % 2);
                n /= 2;
            }
        }
        for (int i = binary.size() - 1; i >= 0; --i) {  //逆序输出
            printf("%d", binary[i]);
        }
        printf("\n");
    }
    return 0;
}
