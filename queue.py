class Node(object):
	def __init__(self, data):
		self.data = data
		self.next = None

	def add_el(self,data):
		
		cur_node=self
		while (cur_node.next):
			cur_node=cur_node.next
		cur_node.next=Node(data)

		return cur_node.next
	def printer(self):
		print (self.data)
		if(self.next):
			self.next.printer()




class Queue_(object):

	def __init__(self, data):
		self.first = Node(data)
		self.last = self.first
		

	def enqueue(self, item):
		if (self.first is None):
			self.first = Node(item)
			self.last = self.first
		else:
			tmp=self.last.add_el(item)
			self.last = tmp
		

	def isEmpty(self):
		return(self.first is None) 

	def dequeue(self):
		f = self.first
		if (self.first is None):
			return None
		if (self.first == self.last):
			self.first = None
			self.last = None
			self.length = 0
			return(f.data)
		else:
			self.first = self.first.next
			
			return(f.data)

	def peek(self):
		return(self.first.data)


q = Queue_(1)
q.enqueue(2)
q.enqueue(3)
q.first.printer()
q.dequeue()
q.dequeue()
q.dequeue()
q.first.printer()


n1=Node(1)
n1_=Node(1)

print (n1==n1_)











