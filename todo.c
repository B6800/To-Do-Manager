#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "todo.h"

#define MAX_TASKS 100

Task tasks[MAX_TASKS];
int task_count = 0;

void load_tasks() {
    FILE *file = fopen("tasks.txt", "r");
    if (!file) return;
    while (fscanf(file, "%d %[^\n]", &tasks[task_count].done, tasks[task_count].description) != EOF) {
        task_count++;
    }
    fclose(file);
}

void save_tasks() {
    FILE *file = fopen("tasks.txt", "w");
    if (!file) return;
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d %s\n", tasks[i].done, tasks[i].description);
    }
    fclose(file);
}

void add_task(const char *desc) {
    if (task_count >= MAX_TASKS) {
        printf("Task list full!\n");
        return;
    }
    strcpy(tasks[task_count].description, desc);
    tasks[task_count].done = 0;
    task_count++;
    save_tasks();
}

void list_tasks() {
    for (int i = 0; i < task_count; i++) {
        printf("[%d] %s %s\n", i+1, tasks[i].done ? "[Done]" : "[ ]", tasks[i].description);
    }
}

void mark_done(int index) {
    if (index < 1 || index > task_count) {
        printf("Invalid task number!\n");
        return;
    }
    tasks[index-1].done = 1;
    save_tasks();
}
