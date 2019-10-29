class node:
    def __init__(self,data,next=None):
        self.data=data
        self.next=next
class linked_list:
    def __init__(self,head=None):
        self.head=head
    def add_first(self,data):
        new_node=node(data)
        new_node.next=self.head
        self.head=new_node
    def add_last(self,data):
        new-node=node(data)
        last=self.head
        while last.next:
            last=last.next
        last.next=new_node
    def add_inside(self,previous,data):
        new_node=node(data)
        new_node.next=previous.next
        previous.next=new_node.next
    def search(self,data):
        temp=self.head
        while temp != None and temp.data != data:
            temp=temp.next
        if temp == None:
            return false
        
        else:
            return temp
    
    def delete(self,data):
        prevoiu=None
        temp=self.head
        while temp != None and temp.data != data:
            prevoius=temp
            temp=temp.next
        if temp == None:
            return false
        
        else:
            prevoius.next=temp.next
            temp=None
