from list_node import ListNode

class MyList:
    def __init__(self, value=None):
        if value is not None:
            self.head = ListNode(value)
        else:
            self.head = None
    
    def append(self, value=None):
        end = ListNode(value)
        if self.head == None:
            self.head = end
        else:
            pointer = self.head
            while pointer.next is not None:
                pointer = pointer.next
            pointer.next = end
        
    def __len__(self):
        count = 0
        if self.head is not None:
            pointer = self.head
            count += 1
            while pointer.next is not None:
                count += 1
                pointer = pointer.next
        return count
    
    def __repr__(self):
        if self.head is None:
            return 'None'
        else:
            return str(self.head)

    def __eq__(self, other):
        if not isinstance(other, MyList):
            return False
        if self.head is None and other.head is None:
            return True
        if self.head is None and other.head is None:
            return False
        if self.head != other.head:
            return False
        else:
            pointer1, pointer2 = self.head.next, other.head.next
            while pointer1 is not None and pointer2 is not None:
                if pointer1 != pointer2:
                    return False
                pointer1, pointer2 = pointer1.next, pointer2.next
            return pointer1 is None and pointer2 is None
        
    def __contains__(self, item):
        pointer = self.head
        while pointer is not None:
            if pointer.value == item:
                return True
            pointer = pointer.next
        return False
        
    def remove(self, item):
        if item is None:
            raise(ValueError)
        if item not in self:
            raise(ValueError)
        pointer = self.head
        if pointer.value == item and pointer is not None:
            self.head = pointer.next
            pointer = None
            return
        while pointer is not None:
            if pointer.value == item:
                break
            previous = pointer
            pointer = pointer.next
        if pointer is None:
            return
        previous.next = pointer.next
        pointer = None

    def pop(self):
        if self.head is None:
            raise(IndexError)
        pointer = self.head
        while pointer is not None:
            value = pointer.value
            pointer = pointer.next
        self.remove(value)
        return(value)

        
    def clear(self):
        if self.head is not None:
            while self.head is not None:
                self.pop()

    def extend(self, other):
        if not isinstance(other, MyList):
            raise(TypeError)
        pointer = other.head
        while pointer is not None:
            self.append(pointer.value)
            pointer = pointer.next

    def copy(self):
        result = MyList()
        if self.head is None:
            return result
        else:
            pointer = self.head
            while pointer is not None:
                result.append(pointer.value)
                pointer = pointer.next
            return result
        
    def insert(self, index, value):
        if not type(index) is int or index < 0:
            raise(IndexError)
        new_node = ListNode(value)
        if self.head is None or index == 0:
            new_node.next = self.head
            self.head = new_node
        elif index > len(self):
            self.append(value=value)
        else:
            pointer = self.head
            for _ in range(index - 1):
                pointer = pointer.next
            if pointer.next is None:
                raise(IndexError)
            new_node.next = pointer.next
            pointer.next = new_node
            

    def reverse(self):
        if self.head is None:
            return self
        else:
            previous = None
            pointer = self.head
            while pointer is not None:
                next = pointer.next
                pointer.next = previous
                previous = pointer
                pointer = next
            self.head = previous

    def count(self, item):
        count = 0
        if self.head is None:
            return count
        else:
            count = 0
            pointer = self.head
            while pointer is not None:
                if pointer.value == item:
                    count += 1
                pointer = pointer.next
            return count
    
    def index(self, item):
        if item not in self:
            raise(ValueError)
        index = 0
        if self.head.value == item:
            return index
        else:
            pointer = self.head
            while pointer is not None:
                if pointer.value == item:
                    return index
                index += 1
                pointer = pointer.next