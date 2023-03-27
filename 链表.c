#include <stdio.h>
#include <stdlib.h>

// 定义一个结构体作为链表的节点
struct node {
    int data;           // 表示该节点的值
    struct node *next;  // 指向下一个节点的指针
};

// 定义一个函数，用于在链表开头插入一个节点
void insert_at_beginning(struct node **head, int data) {
    // 创建一个新节点
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    // 将新节点的 next 指向当前头指针所指向的节点
    new_node->next = *head;
    // 将头指针指向新节点
    *head = new_node;
}

// 定义一个函数，用于在链表末尾插入一个节点
void insert_at_end(struct node **head, int data) {
    // 创建一个新节点
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    // 如果链表为空，则将新节点设置为头指针
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    // 找到链表的最后一个节点
    struct node *last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    // 将新节点插入到链表的最后面
    last_node->next = new_node;
}

// 定义一个函数，用于在某个节点后面插入一个节点
void insert_after_node(struct node *prev_node, int data) {
    // 如果给定的前置节点为空，则无法插入
    if (prev_node == NULL) {
        printf("Previous node is not in the list\n");
        return;
    }
    // 创建一个新节点
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    // 将新节点的 next 指向前置节点的下一个节点
    new_node->next = prev_node->next;
    // 将前置节点的 next 指向新节点
    prev_node->next = new_node;
}

// 定义一个函数，用于删除链表中某个值等于给定值的节点
void delete_node_by_value(struct node **head, int value) {
    // 如果链表为空，则无法删除
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    // 特殊处理头节点
    if ((*head)->data == value) {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    // 找到要删除节点的前一个节点
    struct node *curr_node = *head;
    while (curr_node->next != NULL) {
        if (curr_node->next->data == value) {
            struct node *temp = curr_node->next;
            curr_node->next = temp->next;
            free(temp);
            return;
        }
        curr_node = curr_node->next;
    }
    // 如果没有找到要删除的节点，则打印提示信息
    printf("Value not found in the list\n");
}

// 定义一个函数，用于打印整个链表
void print_list(struct node *head) {
    // 遍历链表，依次打印每个节点的值
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}
int main() {
    // 初始化头指针为NULL
    struct node *head = NULL;

    // 在链表开头插入 1、2、3 三个节点
    insert_at_beginning(&head, 3);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 1);

    // 在链表末尾插入 4、5 两个节点
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);

    // 在第二个节点后插入一个值为6的新节点
    struct node *second_node = head->next;
    insert_after_node(second_node, 6);

    // 删除值为3的节点
    delete_node_by_value(&head, 3);

    // 打印整个链表
    print_list(head);

    return 0;
}
