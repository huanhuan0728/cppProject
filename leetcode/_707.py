class Node:
    def __init__(self, val = 0, next=None):
        self.val = val
        self.next = next

class MyLinkedList(object):

    def __init__(self):
        self.dummy = Node(0)
        self.tail = self.dummy
        self.size = 0

    def get(self, index):
        """
        :type index: int
        :rtype: int
        """
        # 判断索引节点是否越界
        if index<0 or index >= self.size:
            return -1
        # 初始化当前指针指向虚拟头节点
        cur = self.dummy
        # 找到index节点
        for _ in range(index+1):
            cur = cur.next
        return cur.val
        

    def addAtHead(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.addAtIndex(0,val)


    def addAtTail(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.addAtIndex(self.size, val)


    def addAtIndex(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        if index < 0 or index > self.size:
            return

        prev = self.dummy

        for _ in range(index):
            prev = prev.next
        
        node = Node(val)
        node.next = prev.next
        prev.next = node

        if prev is self.tail:
            self.tail = prev
        self.size += 1
        
        

    def deleteAtIndex(self, index):
        """
        :type index: int
        :rtype: None
        """
        # index合法性
        if index < 0 or index >= self.size or self.size == 0:
            return
        # 找到删除节点的前驱节点
        prev = self.dummy

        for _ in range(index):
            prev = prev.next
        
        temp = prev.next
        prev.next = temp.next
        
        # 如果删除的是尾节点，更新尾节点
        if temp is self.tail:
            self.tail = prev
        
        self.size -= 1
        


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)