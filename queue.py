class Queue:
    def __init__(self,capacity):
        self.size=0
        self.capacity=capacity
        self.front=0
        self.rear=-1
        self.Q=[None]*capacity
    def is_empty(self):
        return self.size==0
    def is_full(self):
        return self.size==self.capacity
    def dequeue(self):
        if self.is_empty():
            print("empty queue")
            return
        self.front=(self.front+1)%self.capacity
        self.size=self.size-1
    def enqueue(self,data):
        if self.is_full():
            print("full queue")
            return
        self.rear=(self.rear+1)% self.capacity
        self.Q[self.rear]=data
        self.size=self.size+1
    def get_front(self):
        return self.Q[self.front]
    def get_rear(self):
        return self.Q[self.rear]
    def display(self):
        print("from front goes down to the end:")
        for i in range(self.size):
            print(self.Q[(self.front+i)%self.size])

queue1=Queue(4)
print(queue1.is_empty())
queue1.enqueue(1)
queue1.enqueue(2)
queue1.enqueue(3)
queue1.enqueue(4)
queue1.display()
print(queue1.is_full())
print("front is %d" %queue1.get_front())
print("rear is %d" %queue1.get_rear())
queue1.enqueue(5)
queue1.dequeue()
print("front is %d" %queue1.get_front())
print("rear is %d" %queue1.get_rear())
queue1.display()
queue1.enqueue(5)
queue1.display()
print("front is %d" %queue1.get_front())
print("rear is %d" %queue1.get_rear())
queue1.display()






        
