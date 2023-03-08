#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char data[MAX_LENGTH];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;  // 初始化栈顶指针
}

void push(Stack *s, char c) {
    if (s->top >= MAX_LENGTH - 1) {  // 判断栈是否已满
        printf("栈已满，无法入栈\n");
        return;
    }
    s->data[++(s->top)] = c;  // 将元素入栈
}

char pop(Stack *s) {
    if (s->top == -1) {  // 判断栈是否为空
        printf("栈已空，无法出栈\n");
        return '\0';
    }
    return s->data[(s->top)--];  // 将栈顶元素出栈并返回
}

int isSymmetric(char *str) {
    int len = strlen(str);  // 获取字符串长度
    Stack s;
    initStack(&s);  // 初始化栈

    // 将字符串前半部分入栈
    for (int i = 0; i < len / 2; i++) {
        push(&s, str[i]);
    }

    // 从字符串后半部分开始逐个比较栈顶元素和字符串当前位置的字符是否相等
    int i = len / 2 + (len % 2);  // i 初始值为字符串的中间位置
    while (i < len) {
        if (str[i] != pop(&s)) {
            return 0;  // 如果不相等，说明字符串不对称
        }
        i++;
    }

    return 1;  // 如果所有字符都相等，说明字符串对称
}

int main() {
    char str[MAX_LENGTH];
    printf("请输入字符串：");
    scanf("%s", str);

    if (isSymmetric(str)) {
        printf("字符串 %s 对称\n", str);
    } else {
        printf("字符串 %s 不对称\n", str);
    }

    return 0;
}
