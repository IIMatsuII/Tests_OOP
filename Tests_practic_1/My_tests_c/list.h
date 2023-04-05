#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main() {
    // Создаем список и добавляем несколько элементов
    DoublyLinkedList* list = create_list();
    insert_head(list, 1);
    insert_tail(list, 2);
    insert_tail(list, 3);

    // Проверяем, что список содержит три элемента
    printf("List has %d nodes\n", get_size(list));

    // Проверяем, что голова списка содержит значение 1
    printf("Head value is %d\n", get_head(list)->value);

    // Проверяем, что хвост списка содержит значение 3
    printf("Tail value is %d\n", get_tail(list)->value);

    // Удаляем элемент с головы списка
    delete_head(list);

    // Проверяем, что список содержит два элемента
    printf("List has %d nodes\n", get_size(list));

    // Проверяем, что новая голова списка содержит значение 2
    printf("New head value is %d\n", get_head(list)->value);

    // Удаляем элемент с хвоста списка
    delete_tail(list);

    // Проверяем, что список содержит один элемент
    printf("List has %d nodes\n", get_size(list));

    // Проверяем, что голова и хвост списка содержат одно и то же значение
    printf("Head and tail values are both %d\n", get_head(list)->value);

    // Удаляем оставшийся элемент из списка
    delete_head(list);

    // Проверяем, что список теперь пустой
    printf("List has %d nodes\n", get_size(list));

    // Освобождаем память, выделенную для списка
    destroy_list(list);

    return 0;
}