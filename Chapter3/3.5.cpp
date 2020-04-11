/*
* 题目名称：查找
* 题目来源：北京邮电大学复试上机题
* 题目链接：http://t.cn/E9g8aaR
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int arr[MAXN];

bool BinarySearch(int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2; //中间位置
        if (arr[middle] < target) {             //小于关键字，舍弃左边
            left = middle + 1;
        } else if (target < arr[middle]) {      //大于关键字，舍弃右边
            right = middle - 1;
        } else {
            return true;                        //查找成功
        }
    }
    return false;
}

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);                     //先排序再查找
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            int target;
            scanf("%d", &target);
            if (BinarySearch(n, target)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}
