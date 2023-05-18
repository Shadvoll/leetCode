# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def showLinkedList(self):
        while self is not None:
            print(self.val,end=' ')
            self = self.next
class Solution:
    def pairSum(self, head: ListNode) -> int:
        ...


if __name__ == "__main__":
    linked_list = ListNode(10,ListNode(3,ListNode(1,ListNode(4))))
    linked_list.showLinkedList()