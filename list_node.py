class ListNode:
    def __init__(self, vaule=None, next=None):
        if next is not None and not isinstance(next, ListNode):
            raise(TypeError)
        self.value = vaule
        self.next

    def __str__(self):
        vaules = []
        while self is not None:
            vaules.append(self.vaule)
            self = self.next
        return "("+") -> (".join(map(str, vaules))+") -> None"
    
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