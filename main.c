#include <stdio.h>
#include <string.h>
#include "todo.h"
#include "todo.c"
int main() {
    char command[10];
    char desc[100];
    int index;

    load_tasks();

    printf("=== To-Do List App ===\n");

    while (1) {
        printf("\nCommands: add, list, done, quit\n");
        printf("> ");
        scanf_s("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Task Description: ");
            getchar(); // flush newline
            fgets(desc, sizeof(desc), stdin);
            desc[strcspn(desc, "\n")] = 0; // remove newline
            add_task(desc);
        } else if (strcmp(command, "list") == 0) {
            list_tasks();
        } else if (strcmp(command, "done") == 0) {
            printf("Task Number: ");
            scanf_s("%d", &index);
            mark_done(index);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command!\n");
        }
    }

    return 0;
}
