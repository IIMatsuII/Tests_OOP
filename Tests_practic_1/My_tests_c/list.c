#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Структура, содержащая информацию о студенте
typedef struct Student {
    char surname[50];
    int birth_year;
    int admission_year;
    int grades[5];
    struct Student* next;
    struct Student* prev;
} Student;

// Функция для создания нового узла списка
Student* create_node(const char* surname, int birth_year, int admission_year, int grades[]);
Student* create_node(const char* surname, int birth_year, int admission_year, int grades[]) {
    Student* new_node = (Student*) malloc(sizeof(Student));
    strcpy(new_node->surname, surname);
    new_node->birth_year = birth_year;
    new_node->admission_year = admission_year;
    memcpy(new_node->grades, grades, 5 * sizeof(int));
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Функция для добавления узла в конец списка
void append(Student* *head_ref, const char* surname, int birth_year, int admission_year, int grades[]);
void append(Student* *head_ref, const char* surname, int birth_year, int admission_year, int grades[]) {
    Student* new_node = create_node(surname, birth_year, admission_year, grades);
    if (*head_ref == NULL) {
        // Если список пуст, новый узел становится его головой
        *head_ref = new_node;
    } else {
        // Иначе ищем последний узел и добавляем новый узел после него
        Student* last_node = *head_ref;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}

// Функция для удаления узла из списка
void delete_node(Student** head_ref, Student* node_to_delete);
void delete_node(Student** head_ref, Student* node_to_delete) {
    if (*head_ref == NULL || node_to_delete == NULL) {
        return;
    }

    if (*head_ref == node_to_delete) {
        *head_ref = node_to_delete->next;
    }

    if (node_to_delete->next != NULL) {
        node_to_delete->next->prev = node_to_delete->prev;
    }

    if (node_to_delete->prev != NULL) {
        node_to_delete->prev->next = node_to_delete->next;
    }

    node_to_delete->next = NULL;
    node_to_delete->prev = NULL;
    free(node_to_delete);
}
// Функция для перемещения студентов с нечетным годом поступления в другой список
void move_odd_admissions(Student** original_list_ref, Student** other_list_ref);
void move_odd_admissions(Student** original_list_ref, Student** other_list_ref) {
    Student* current_node = *original_list_ref;
    while (current_node != NULL) {
        if (current_node->admission_year % 2 == 1) {
            // Сохраняем указатель на следующий узел
            Student* next_node = current_node->next;

            // Удаляем узел из оригинального списка
            delete_node(original_list_ref, current_node);

            // Добавляем узел в другой список
            append(other_list_ref, current_node->surname, current_node->birth_year, current_node->admission_year, current_node->grades);

            // Переходим к следующему узлу
            current_node = next_node;
        } else {
            current_node = current_node->next;
        }
    }
}
// Функция для вывода информации о студенте
void print_student_info(Student* student);
void print_student_info(Student* student) {
    printf("Surname: %s\n", student->surname);
    printf("Birth year: %d\n", student->birth_year);
    printf("Admission year: %d\n", student->admission_year);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", student->grades[i]);
    }
    printf("\n");
}

// Функция для вывода всех студентов в списке
void print_list(Student* head);
void print_list(Student* head) {
    Student* current_node = head;
    while (current_node != NULL) {
        print_student_info(current_node);
        current_node = current_node->next;
    }
}

int main(void);
int main(void) {
    // Создаем список студентов
    Student* student1 = create_node("Ivanov", 2000, 2020, (int[]) {5, 4, 5, 4, 5});
    Student* student2 = create_node("Petrov", 2001, 2021, (int[]) {3, 3, 3,4, 4});
    Student* student3 = create_node("Sidorov", 1999, 2019, (int[]) {4, 5, 4, 5, 5});
    Student* student4 = create_node("Smirnov", 2002, 2022, (int[]) {4, 4, 4, 4, 4});

Student* head = student1;
student1->next = student2;
student2->prev = student1;
student2->next = student3;
student3->prev = student2;
student3->next = student4;
student4->prev = student3;

printf("Original list:\n");
print_list(head);

// Создаем другой список для студентов с нечетным годом поступления
Student* other_list = NULL;

// Перемещаем студентов с нечетным годом поступления в другой список
move_odd_admissions(&head, &other_list);

printf("Original list after moving odd admissions:\n");
print_list(head);

printf("Other list:\n");
print_list(other_list);

return 0;

}