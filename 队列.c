#include <stdio.h>
#include <stdlib.h>
#定义了一个结构体作为队列的节点，每个节点包含一个数据成员 data 和一个指向下一个节点的指针 next。
#在主函数中，我们首先初始化头指针为 NULL，然后依次调用各个函数来操作队列，并最终打印整个队列的数据。



// 定义一个结构体作为队列
struct queue {
    int data;           // 表示该节点的值
    struct queue *next;  // 指向下一个节点的指针
};

// 定义一个函数，用于在队列末尾插入一个节点
void enqueue(struct queue **head, int data) {
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
int dequeue(struct queue **head) {
    // 如果队列为空，则返回 0
    if (*head == NULL) {
        return 0;
    }
    struct queue *temp = *head;
    // 获取队列头部节点的值
    int value = temp->data;
    // 将头指针指向下一个节点
    *head = temp->next;
    // 释放原头部节点内存
    free(temp);
    // 返回队列头部节点的值
    return value;
}

// 定义一个函数，用于打印整个队列
void print_queue(struct queue *head) {
    // 遍历队列，依次打印每个节点的值
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // 初始化头指针为NULL
    struct queue *head = NULL;

    // 将 1、2、3 依次插入队列中
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);

    // 打印整个队列
    printf("Queue: ");
    print_queue(head);

    // 从队列中删除一个节点
    int value = dequeue(&head);
    printf("Dequeued value: %d\n", value);

    // 再次打印整个队列
    printf("Queue: ");
    print_queue(head);

    return 0;
}
