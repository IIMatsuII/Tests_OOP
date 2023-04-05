#include "list.h"

list_t* list_create(size_t data_size)
{
    list_t* list = (list_t*)malloc(sizeof(list_t));
    if (list == NULL) {
        return NULL; // Ошибка выделения памяти
    }
    list->head = NULL;
    list->data_size = data_size;
    return list;
}

void list_destroy(list_t *list)
{
    list_node_t *current = list->head;
    while (current != NULL) {
        list_node_t *next = current->next;
        free(current->data); // Освобождаем память, выделенную для данных элемента списка
        free(current); // Освобождаем память, выделенную для элемента списка
        current = next;
    }
    free(list); // Освобождаем память, выделенную для списка
}

bool list_empty(list_t *list)
{
    return (list->head == NULL);
}

void list_append(list_t *list, void *data)
{
    list_node_t *new_node = (list_node_t*)malloc(sizeof(list_node_t));
    if (new_node == NULL) {
        return; // Ошибка выделения памяти
    }
    new_node->data = malloc(list->data_size);
    if (new_node->data == NULL) {
        free(new_node); // Ошибка выделения памяти
        return;
    }
    memcpy(new_node->data, data, list->data_size); // Копируем данные в новый узел
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        list_node_t *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

size_t list_length(list_t *list)
{
    size_t length = 0;
    list_node_t *current = list->head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

bool list_contains(list_t *list, void *data)
{
    list_node_t *current = list->head;
    while (current != NULL) {
        if (memcmp(current->data, data, list->data_size) == 0) {
            return true; // Элемент найден
        }
        current = current->next;
    }
    return false; // Элемент не найден
}

size_t list_index(list_t *list, void *data)
{
    size_t index = 0;
    list_node_t *current = list->head;
    while (current != NULL) {
        if (memcmp(current->data, data, list->data_size) == 0) {
            return index; // Элемент найден, возвращаем его индекс
        }
        index++;
        current = current->next;
    }
    return SIZE_MAX; // Элемент не найден, возвращаем максимальное значение size_t
}

void *list_pop(list_t *list) {
    if (list->head == NULL) {
        return NULL;
    }

    list_node_t *current = list->head;
    list_node_t *previous = NULL;

    // перемещаемся до конца списка
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // извлекаем последний элемент
    void *data = current->data;

    if (previous == NULL) {
        // список содержал только один элемент
        list->head = NULL;
    } else {
        // список содержал более одного элемента
        previous->next = NULL;
    }

    free(current);

    return data;
}

void list_remove(list_t *list, void *data) {
    list_node_t *current = list->head;
    list_node_t *previous = NULL;

    // Ищем первый узел, содержащий заданные данные
    while (current != NULL) {
        if (memcmp(current->data, data, list->data_size) == 0) {
            break;
        }
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        // Узел не найден
        return;
    }

    if (previous == NULL) {
        // Удаляемый узел - головной узел списка
        list->head = current->next;
    } else {
        // Удаляемый узел - не головной узел списка
        previous->next = current->next;
    }

    free(current->data);
    free(current);
}

void list_insert(list_t* list, size_t index, void* data)
{
    if (index > list_length(list) || list->head == NULL){
        list_append(list, data);
    } else {
        list_node_t *new_node = (list_node_t*)malloc(sizeof(list_node_t));
        new_node->data = malloc(list->data_size);
        memcpy(new_node->data, data, list->data_size);
        list_node_t *current = list->head;
        size_t i = 1;
        if (index == 0) {
            new_node->next = current->next;
            list->head = new_node;
        } else {
            while (i < index) {
                current = current->next;
                i++;
            }
            new_node->next = current->next;
            current->next = new_node;
        }

    }

}

void list_print_int(list_t *list, FILE *file) {
    if (list == NULL || list->head == NULL) {
        fprintf(file, "NULL");
        return;
    }

    list_node_t *node = list->head;
    fprintf(file, "(%d)", *(int *)node->data);
    node = node->next;

    while (node != NULL) {
        fprintf(file, " -> (%d)", *(int *)node->data);
        node = node->next;
    }

    fprintf(file, " -> NULL");
}