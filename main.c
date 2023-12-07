#include <stdio.h>
#include <string.h>

#define MAX_TODOS 100
#define MAX_TODO_LENGTH 256

typedef struct {
    int id;
    char text[MAX_TODO_LENGTH];
} todo;

int main() {
    todo todos[MAX_TODOS];
    int todoCount = 0;
    char input[MAX_TODO_LENGTH];

    while (1) {
        printf("Enter your todo item (or 'exit' to quit): ");
        fgets(input, MAX_TODO_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (todoCount < MAX_TODOS) {
            todos[todoCount].id = todoCount + 1;
            strncpy(todos[todoCount].text, input, MAX_TODO_LENGTH);
            todoCount++;
        } else {
            printf("Todo list is Full!\n");
            break;
        }
    }

    printf("\nYour Todo List:\n");
    for (int i = 0; i < todoCount; i++) {
        printf("Todo ID %d: %s\n", todos[i].id, todos[i].text);
    }

    return 0;
}
