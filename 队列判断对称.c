#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义一个结构体作为队列
struct queue {
    char data;           // 表示该节点的值
    struct queue *next;  // 指向下一个节点的指针
};

// 定义一个函数，用于在队列末尾插入一个节点
void enqueue(struct queue **head, char data) {
    // 创建一个新节点
    struct queue *new_node = (struct queue*) malloc(sizeof(struct queue));
    new_node->data = data;
    new_node->next = NULL;
    // 如果队列为空，则将新节点设置为头指针
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    // 找到队列的最后一个节点
    struct queue *last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    // 将新节点插入到队列的最后面
    last_node->next = new_node;
}

// 定义一个函数，用于从队列中删除一个节点
char dequeue(struct queue **head) {
    // 如果队列为空，则返回空字符
    if (*head == NULL) {
        return '\0';
    }
    struct queue *temp = *head;
    // 获取队列头部节点的值
    char value = temp->data;
    // 将头指针指向下一个节点
    *head = temp->next;
    // 释放原头部节点内存
    free(temp);
    // 返回队列头部节点的值
    return value;
}

// 定义一个函数，用于判断字符串是否对称
int is_symmetric(char *str) {
    int length = strlen(str);
    struct queue *queue_head = NULL;

    // 将字符串的前一半字符依次入队
    for (int i = 0; i < length / 2; i++) {
        enqueue(&queue_head, str[i]);
    }

    // 如果字符串长度为奇数，则跳过中间一个字符
    if (length % 2 != 0) {
        dequeue(&queue_head);
    }

    // 将字符串的后一半字符依次出队并与队列中的字符比较
    for (int i = length / 2; i < length; i++) {
        char c = dequeue(&queue_head);
        if (c != str[i]) {
            return 0;   // 字符不相等，说明字符串不对称
        }
    }

    return 1;   // 字符全部相等，说明字符串对称
}

int main() {
    char str1[] = "abcdcba";    // 对称字符串
    char str2[] = "hello";      // 非对称字符串

    printf("%s is symmetric: %d\n", str1, is_symmetric(str1));
    printf("%s is symmetric: %d\n", str2, is_symmetric(str2));

    return 0;
}
