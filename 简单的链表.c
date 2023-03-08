#include <stdio.h>
#include <stdlib.h>

// 定义结点类型
typedef struct Node {
    int data;  // 数据域
    struct Node *next;  // 指针域，指向下一个结点
} Node;

int main() {
    Node *head = NULL;  // 头结点指针初始化为空
    Node *tail = NULL;  // 尾结点指针初始化为空

    // 逐行添加结点，输入-1结束
    while (1) {
        int x;
        printf("请输入结点的数据值（-1结束）：");
        scanf("%d", &x);

        if (x == -1) {
            break;
        }

        // 新建结点
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = x;  // 设置结点的数据域为输入的值
        new_node->next = NULL;  // 新结点的下一个结点指针为空

        if (head == NULL) {  // 如果头结点为空，说明链表中还没有结点
            head = new_node;  // 头结点指针指向新结点
            tail = new_node;  // 尾结点指针也指向新结点
        } else {  // 如果链表中已经有结点
            tail->next = new_node;  // 将尾结点的下一个结点指向新结点
            tail = new_node;  // 将尾结点指针指向新结点
        }
    }

    // 输出链表中的结点
    printf("链表中的结点为：\n");
    Node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    // 释放链表的内存空间
    p = head;
    while (p != NULL) {
        Node *temp = p;
        p = p->next;
        free(temp);
    }

    return 0;
}
////我们使用一个循环输出链表中的所有结点，然后再用另一个循环释放链表的内存空间。最后返回0，结束程序。

在输出链表中的结点时，我们定义了一个指针 p，初始值为头结点指针 head。通过一个循环，每次输出当前结点的数据域，然后将指针 p 指向下一个结点，直到 p 为空，循环结束。

在释放链表的内存空间时，我们同样定义了一个指针 p，初始值为头结点指针 head。通过一个循环，我们先将当前结点指针赋值给临时指针 temp，然后将指针 p 指向下一个结点，最后释放 temp 所指向的内存空间。这样依次释放所有结点的内存空间，链表被完全释放。
