class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reversePrint(self, head:ListNode):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        stack = []
        while head:
            stack.append(head.val)
            head = head.next
        return stack[::-1]

a = ListNode(1)
b = ListNode(2)
c = ListNode(3)
a.next = b
b.next = c

s = Solution()
l = s.reversePrint(a)
print(l)