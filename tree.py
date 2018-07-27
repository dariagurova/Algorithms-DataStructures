class Node(object):
	def __init__(self, data, ch=None):
		self.data = data
		if (ch is None):
			self.left = None
			self.right = None
		else:
			self.left = Node(ch[0])
			self.right = Node(ch[1])


	def add_left(self, obj):
		self.left = Node(obj)
		return self.left
	def add_right(self, obj):
		self.right = Node(obj)
		return self.right


	def printer_r_back(self,flag):
		if ((self.right is None) and (self.left is None)):
			return
		if (not self.right is None):
			self.right.printer_r_back(1)
		if (flag):
			print (self.data)
		
		
		def printer_r_b(self,flag):
		if ((self.right is None) and (self.left is None)):
			return
		if (flag):
			print (self.data)
		flag=1
		if (not self.right is None):
			
			self.right.printer_r_b(flag)
		
			return

	def printer_l_b(self):
		if ((self.right is None) and (self.left is None)):
			return
		print (self.data)

		if (not self.left is None):
			
			self.left.printer_l_b()
			return

	def printer_leaves(self):
		if ((self.right is None) and (self.left is None)):
			
			print (self.data)
		
		if (not self.left is None):
			
			self.left.printer_leaves()
		
		if (not self.right is None):
			
			self.right.printer_leaves()
		  		

	def printer(self):
		if ((self.right is None) and (self.left is None)):
			print "i am leaf",
		print (self.data)
		if (not self.right is None):
			print "right"
			self.right.printer()
		
		if (not self.left is None):
			print "left"
			self.left.printer()
		print "level up",  


n92 = Node(92)
n92.add_left(85).add_left(79).add_right(10).add_left(39).add_left(35).add_left(96)
n64 = n92.add_right(26).add_right(64)
n40 = n64.add_left(40)
n88 = n40.add_left(88)
n88.add_left(12).add_left(58)
n55 = n88.add_right(55)
n55.add_right(41)
n55.add_left(58)
n10 = n40.add_right(10)
n10.add_right(87).add_right(31)

n10.left=Node(52,[22,35])
n78 = n64.add_right(78)
n78.add_right(85).add_right(51)
n2 = n78.add_left(2)
n2.add_left(33).add_right(55)
n2.add_right(11).add_left(99)

n92.printer_l_b()
n92.printer_leaves()
n92.printer_r_back(0)