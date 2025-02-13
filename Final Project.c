#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

// 定義學生結構體
typedef struct {
    char name[50];
    int id;          // 學號
    char course[50]; // 課程名稱
    float score;     // 分數
} Student;

void displayMenu() {
    printf("===== 學生成績管理系統 =====\n");
    printf("1. 添加學生資料\n");
    printf("2. 查看所有學生資料\n");
    printf("3. 刪除學生資料\n");
    printf("4. 統計數據\n");
    printf("5. 退出系統\n");
    printf("請選擇操作: ");
}

#define MAX_STUDENTS 100

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("學生資料已滿，無法添加更多！\n");
        return;
    }

    printf("輸入學生姓名: ");
    scanf("%s", students[*count].name);

    printf("輸入學號: ");
    scanf("%d", &students[*count].id);

    printf("輸入課程名稱: ");
    scanf("%s", students[*count].course);

    printf("輸入分數: ");
    scanf("%f", &students[*count].score);

    (*count)++;
    printf("學生資料添加成功！\n");
}

void viewStudents(Student students[], int count) {
    if (count == 0) {
        printf("目前沒有學生資料！\n");
        return;
    }

    printf("===== 學生資料清單 =====\n");
    for (int i = 0; i < count; i++) {
        printf("姓名: %s, 學號: %d, 課程: %s, 分數: %.2f\n",
               students[i].name, students[i].id, students[i].course, students[i].score);
    }
}

void deleteStudent(Student students[], int *count) {
    if (*count == 0) {
        printf("目前沒有學生資料！\n");
        return;
    }

    int id;
    printf("輸入要刪除的學生學號: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("學號 %d 的學生資料已刪除！\n", id);
            return;
        }
    }
    printf("未找到學號為 %d 的學生！\n", id);
}

void calculateStatistics(Student students[], int count) {
    if (count == 0) {
        printf("目前沒有學生資料！\n");
        return;
    }

    float totalScore = 0, maxScore = students[0].score, minScore = students[0].score;
    for (int i = 0; i < count; i++) {
        totalScore += students[i].score;
        if (students[i].score > maxScore) maxScore = students[i].score;
        if (students[i].score < minScore) minScore = students[i].score;
    }

    printf("平均分數: %.2f\n", totalScore / count);
    printf("最高分: %.2f\n", maxScore);
    printf("最低分: %.2f\n", minScore);
}

void saveToFile(Student students[], int count) {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("無法保存資料到檔案！\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
    printf("資料已保存！\n");
}

void loadFromFile(Student students[], int *count) {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("未找到檔案，從零開始。\n");
        return;
    }
    fread(count, sizeof(int), 1, file);
    fread(students, sizeof(Student), *count, file);
    fclose(file);
    printf("資料已載入！\n");
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    loadFromFile(students, &count); // 啟動時載入資料

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: viewStudents(students, count); break;
            case 3: deleteStudent(students, &count); break;
            case 4: calculateStatistics(students, count); break;
            case 5: saveToFile(students, count); printf("退出系統。\n"); break;
            default: printf("無效的選項，請重新選擇。\n");
        }
    } while (choice != 5);

    return 0;
}
