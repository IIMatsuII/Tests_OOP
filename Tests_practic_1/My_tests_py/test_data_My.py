class Students:
    def __init__(self, surname, birth_y, admission_y, gradses):
        self.surname = surname
        self.birth_y = birth_y
        self.admission_y = admission_y
        self.gradses = gradses
    def __str__(self):
        return f"{self.surname}, {self.birth_y}, {self.admission_y}, {self.gradses}"        

class Node:
    def __init__(self, student = None):
        self.student = student
        self.next = None
        self.prev = None

class Doubly_List:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, student):
        new_node = Node(student)

        if not self.head:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node

    def remove(self, node):
        if node.prev:
            node.prev.next = node.next
        else:
            self.head = node.next

        if node.next:
            node.next.prev = node.prev
        else:
            self.tail = node.prev

    def filter_enqueue(self, condition, other_list):
        current = self.head
        while current:
            if condition(current.student):
                other_list.append(current.student)
                self.remove(current)
            current = current.next
    
    def __iter__(self):
        current = self.head
        while current:
            yield current.student
            current = current.next
        
    def __str__(self):
        return " -> ".join(str(student) for student in self)
    
    def is_empty(self):
        if self.head == None:
            return True
        else:
            return False
        
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

print(students_list)
print(odd_admission_list)
