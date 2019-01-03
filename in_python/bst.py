class Node(object):
	def __init__(self, data):
		self.data = data
		self.l = None
		self.m = None

	def add_l(self, obj):
		self.l = Node(obj)
		return self.l
	def add_m(self, obj):
		self.m = Node(obj)
		return self.m

	def printer_tree(self,lev):
		print (self.data)
		if (self.l):
			print "left:"
			self.l.printer_tree(lev+1)
		if (self.m):
			print "right:"
			self.m.printer_tree(lev+1)
		print "level->", lev
	def smallest(self):
		if not (self.l):
			return (None,self)
		if not (self.l.l):
			return (self,self.l)

		return self.l.smallest()
		
	def is_leaf(self):
		return (not (self.l) and not (self.m))



root = Node(8)
n3 = root.add_l(3)
n3.add_l(1)
n6 = n3.add_m(6)
n6.add_l(4)
n6.add_m(7)
n13 = root.add_m(10).add_m(14).add_l(13)

root.printer_tree(0)


depot=None

while (not root.is_leaf()):
	(p,sm) = root.smallest()
	
	if (p):
		p.l = sm.m
	else:
		root = sm.m
	sm.l = None
	sm.m = None
	sm.l=depot
	depot=sm

root.l = depot
print "***********"
root.printer_tree(0)










