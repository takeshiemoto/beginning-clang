#include <stdio.h>
#include <string.h>
#include "recursively.h"

#define MAX_TODOS 100
#define MAX_TODO_LENGTH 256

typedef struct {
    int id;
    char text[MAX_TODO_LENGTH];
} Todo;

typedef enum {
    ADD_NEW_TODO,
    LIST_TODO,
    INVALID_CHOICE
} Choice;

Choice getUserChoice() {
    char choice[10];
    printf("Enter 'new' to add new TODOs or 'list' to display existing TODOs: ");
    fgets(choice, 10, stdin);
    choice[strcspn(choice, "\n")] = 0;

    if (strcmp(choice, "list") == 0) {
        return LIST_TODO;
    }
    if (strcmp(choice, "new") == 0) {
        return ADD_NEW_TODO;
    }
    return INVALID_CHOICE;
}

void addNewTodo(Todo *todos, int *todoCount) {
    char input[MAX_TODO_LENGTH];

    while (1) {
        printf("Enter your todo item (or 'exit' to quit): ");
        fgets(input, MAX_TODO_LENGTH, stdin);

        // strcspnは改行文字の位置を返す
        // 改行文字を終端文字に置き換える
        input[strcspn(input, "\n")] = 0;

        // strcmpは文字列が等しい場合に0を返す
        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (*todoCount < MAX_TODOS) {
            todos[*todoCount].id = *todoCount + 1;
            // strncpyは第三引数の長さ分コピーする
            strncpy(todos[*todoCount].text, input, MAX_TODO_LENGTH);
            (*todoCount)++;
        } else {
            printf("Todo list is Full!\n");
            break;
        }
    }
}

void readTodosFromCSV() {
    FILE *file = fopen("data.csv", "r");
    char buffer[1024];

    if (file == NULL) {
        printf("No existing TODO list found.\n");
        return;
    }

    while (fgets(buffer, 1024, file)) {
        printf("%s", buffer);
    }

    fclose(file);

}

void writeTodoToCSV(const Todo todos[], int count) {
    // ファイルを書き込みモードで開く
    FILE *file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Unable to create file\n");
        return;
    }

    // fprintfはファイルに書き込む
    fprintf(file, "ID, Text\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s\n", todos[i].id, todos[i].text);
    }

    fclose(file);
}

/**
 * Constant
 */
const double TAX = 0.1;

/**
 * Enum
 */
enum {
    OK, NG
};

enum {
    GOOD = 1, BAD = 0
};

enum {
    SMALL = 1, MIDDLE, BIG
};

int main() {
    // 初期化していない変数はいい加減な値が入っている
    int x;
    printf("%d\n", x);

    printf("%d\n", OK);
    printf("%d\n", NG);
    printf("%d\n", GOOD);
    printf("%d\n", BAD);
    printf("%d\n", SMALL);
    printf("%d\n", MIDDLE);
    printf("%d\n", BIG);
    return 0;
}
