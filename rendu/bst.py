
class Node(object):
	def __init__(self,data):
		self.value = data
		self.less = None
		self.more = None
	

	def addL(self, data):
		n = Node(data)
		self.less=n
		return(n)

	def addR(self, data):
		n = Node(data)
		self.more=n
		return(n)

	def printer(self,lev):
		print (self.value)
		if (self.less):
			print "left:"
			self.less.printer(lev+1)
		if (self.more):
			print "right:"
			self.more.printer(lev+1)
		print "level->", lev

	def isLeaf(self):
		if (not(self.less) and not(self.more)):
			return(1)
#returns node previous to the smallest in the subtree
	def prev(self):
		if (not self):
			return(None)
		if(not self.less):
			return(None)
		if(not self.less.less):
			return(self)
		return(self.less.prev())


root = Node(10)
n1 = root.addR(12)
n2 = root.addL(8)
n3 = n1.addL(11)
n4 = n2.addL(5)
n5 = n4.addR(6)

res = None
while(not root.isLeaf()):
	p = root.prev()
	
	if (p):
		sm = p.less
		p.less = sm.more
	else:
		sm = root
		root = root.more
	sm.less = None
	sm.more = None
	sm.less = res
	res = sm
root.l = res
print "***********"
res.printer(0)


























