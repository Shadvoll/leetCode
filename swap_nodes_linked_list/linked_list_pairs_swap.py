# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        currentNode = head.next
        nextNode = currentNode.next
        currentNode.next = head
        head.next = self.swapPairs(nextNode)
        return currentNode
        

    @staticmethod
    def showList(head: ListNode):
        iterator = head
        while iterator is not None:
            print(iterator.val, end=' ')
            iterator = iterator.next
        print()
        
            


if __name__ == '__main__':

    my_lst = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))

    Solution.showList(my_lst)
    my_lst = Solution().swapPairs(my_lst)
    Solution.showList(my_lst)
