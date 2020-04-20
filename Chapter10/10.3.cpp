/*
* 题目名称：二叉排序树
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/Ai9PAkkv
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int x): data(x), leftChild(NULL), rightChild(NULL) {}
};

TreeNode* Insert(TreeNode* root, int x, int father) {
    if (root == NULL) {                                 //创建新节点
        root = new TreeNode(x);
        printf("%d\n", father);                         //输出父节点
    } else if (x < root->data) {                        //插入左子树
        root->leftChild = Insert(root->leftChild, x, root->data);
    } else {                                            //插入右子树
        root->rightChild = Insert(root->rightChild, x, root->data);
    }
    return root;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        TreeNode* root = NULL;                          //建立空树
        for (int i = 0; i < n; ++i) {                   //逐个插入
            int x;
            scanf("%d", &x);
            root = Insert(root, x, -1);
        }
    }
    return 0;
}

