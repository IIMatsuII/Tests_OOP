#import pytest

#from list_node import ListNode
#from my_list import MyList
from test_data_My import Node, Doubly_List, Students



def test_doubly_linked_list_1():
    lst = Doubly_List()
    assert lst.is_empty() == True


def test_doubly_linked_list_2():
    students_list = Doubly_List()
    students_list.append(Students("Петров", 2000, 2019, {"math": 5, "physics": 4}))
    students_list.append(Students("Абуков", 2001, 2020, {"math": 4, "physics": 4}))
    students_list.append(Students("Сергеев", 1999, 2021, {"math": 3, "physics": 4}))
    students_list.append(Students("Бублов", 2002, 2022, {"math": 3, "physics": 3}))
    students_list.append(Students("Пантелеев", 2002, 2022, {"math": 4, "physics": 4}))
    students_list.append(Students("Керб", 2002, 2022, {"math": 3, "physics": 3}))
    students_list.append(Students("Балаболов", 2004, 2023, {"math": 5, "physics": 5}))

    odd_admission_list = Doubly_List()
    students_list.filter_enqueue(lambda s: s.admission_y % 2 != 0, odd_admission_list)

    pointer = odd_admission_list.head
    while pointer is not None:
        assert pointer.student.admission_y % 2 == 1
        pointer = pointer.next

def test_doubly_linked_list_3():
    students_list = Doubly_List()
    students_list.append(Students("Петров", 2000, 2019, {"math": 5, "physics": 4}))
    students_list.append(Students("Абуков", 2001, 2020, {"math": 4, "physics": 4}))
    students_list.append(Students("Сергеев", 1999, 2021, {"math": 3, "physics": 4}))
    students_list.append(Students("Бублов", 2002, 2022, {"math": 3, "physics": 3}))
    students_list.append(Students("Пантелеев", 2002, 2022, {"math": 4, "physics": 4}))
    students_list.append(Students("Керб", 2002, 2022, {"math": 3, "physics": 3}))
    students_list.append(Students("Балаболов", 2004, 2023, {"math": 5, "physics": 5}))

    odd_admission_list = Doubly_List()
    students_list.filter_enqueue(lambda s: s.admission_y % 2 != 0, odd_admission_list)

    pointer = students_list.head
    while pointer is not None:
        assert pointer.student.admission_y % 2 == 0
        pointer = pointer.next
