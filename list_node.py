class ListNode:
    def __init__(self, value=None, next=None):
        if next is not None and not isinstance(next, ListNode):
            raise(TypeError)
        self.value = value
        self.next = next

    def __str__(self):
        values = []
        while self is not None:
            values.append(self.value)
            self = self.next
        return "("+") -> (".join(map(str, values))+") -> None"
    
    def __eq__(self, other):
        if not isinstance(other, ListNode):
            return False
        if self.value != other.value:
            return False
        if self.next is None and other.next is None:
            return True
        if self.next is None or other.next is None:
            return False
        return self.next == other.next