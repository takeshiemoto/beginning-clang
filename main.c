#include <stdio.h>
#include <string.h>

#define MAX_TODOS 100
#define MAX_TODO_LENGTH 256

typedef struct {
    int id;
    char text[MAX_TODO_LENGTH];
} Todo;

void writeTodoToCSV(const Todo todos[], int count) {
    // ファイルを書き込みモードで開く
    FILE *file = fopen("data.csv", "w");
    if(file == NULL) {
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

int main() {
    Todo todos[MAX_TODOS];
    int todoCount = 0;
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

        if (todoCount < MAX_TODOS) {
            todos[todoCount].id = todoCount + 1;
            // strncpyは第三引数の長さ分コピーする
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

    // CSVファイルに書き込む
    writeTodoToCSV(todos, todoCount);

    return 0;
}
