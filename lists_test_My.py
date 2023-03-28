import pytest

#from list_node import ListNode
#from my_list import MyList
from test_data_My import *

@pytest.mark.listnode
@pytest.mark.parametrize
def Test_doubly_linked_list_1():
    lst = Doubly_List
    assert lst.is_empty() == True


@pytest.mark.listnode
@pytest.mark.parametrize
def Test_doubly_linked_list_1():
    lst = Doubly_List
    lst.insert("Петров", 2000, 2019, {"math": 5, "physics": 4})
    lst.insert("Абуков", 2001, 2020, {"math": 4, "physics": 4})
    lst.insert("Сергеев", 1999, 2021, {"math": 3, "physics": 4})
    lst.insert("Бублов", 2002, 2022, {"math": 3, "physics": 3})
    lst.insert("Балаболов", 2004, 2023, {"math": 5, "physics": 5})

@pytest.mark.listnode
@pytest.mark.parametrize
def Test_doubly_linked_list_1():
    lst = Doubly_List
    assert lst.is_empty() == False

