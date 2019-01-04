
class Node(object):
	def __init__(self,val):
		self.value = val
		self.next = None
		self.other = None

	def add(self,val):
		curr = self
		while(curr.next):
			curr = curr.next
		curr.next = Node(val)
		return curr.next

	def printer(self):
		while (self):
			print ("next: "+str(self.value))
			if (self.other):
				print("other:"+ str(self.other.value))
			else:
				print("other: NULL");
			self=self.next


	def clone(self):
		cloned = Node(self.value)
		headB = cloned
		headA= self.next
		while(headA):
			cloned.add(headA.value)
			headA = headA.next
		return(headB)

	def idx(self,elem):
		i = 0
		if (elem == None):
			return 0
		while (self):
			if (self == elem):
				return i
			i = i+1
			self = self.next
		return -1

	def ref(self, i):
		if (i == -1):
			return (None)
		while(self and i > 0):
			self = self.next
			i = i-1
		return(self)

	def direct(self, elem, i):
		 
		x = self.ref(i)
		elem.other = x

	def clone_list(self):
		l1 = self
		res = self.clone()
		l1root = l1
		resroot = res
		while (l1 and res):
			tmp = l1.other
			if not (tmp == None):
				i = l1root.idx(tmp)
				l1root.direct(res,i)

			l1 = l1.next
			res = res.next
		return(resroot)



lst = Node(1)
n1 = lst.add(2)
n2 = lst.add(3)
n3 = lst.add(4)
lst.direct(n1, 3)
lst.direct(n2, 0)

lst.printer()
print "++++++++++++"
lst2 = lst.clone_list()
lst2.printer()


