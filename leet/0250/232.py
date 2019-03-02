class MyQueue(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.buff = []
        self.out = []

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: None
        """
        self.buff.append(x)

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if len(self.out) == 0: self._move()
        return self.out.pop()

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if len(self.out) == 0: self._move()
        return self.out[-1]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return len(self.buff) == 0 and len(self.out) == 0

    def _move(self):
        while len(self.buff) != 0:
            self.out.append(self.buff.pop())
        
# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
