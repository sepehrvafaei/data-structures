class stack:
    def __init__(self,list=[]):
        self.items=list.copy()
    def add(self,data):
        self.items.append(data)
    def remove(self):
        if self.is_empty():
            print("empty stack")
        self.items.pop()
    def is_empty(self):
        return len(self.items)==0
    def peek(self):
        return self.items[-1]

stack1=stack([1,2,3])
print(stack1.is_empty())
stack1.add(4)
print(stack1.peek())
stack1.remove()
print(stack1.peek())
