class Stack(object):
	def __init__(self):
		self.l=[]
	def len_(self):
		return len(self.l)

	def push(self,data):
		self.l.append(data)
	def pop(self):
		if (len(self.l) == 0):
			return
		res=self.l[-1]
		del self.l[-1]
		return res
	
	def peek(self):
		if (len(self.l) == 0):
			return
		res=self.l[-1]
		return res

	def is_in(self,el):
		return (el in self.l)


def f(name,nodes):
	ind=0
	while (ind < len(nodes)):
		if (nodes[ind] == name):
			return ind
		ind = ind+1

#s = "17-5 5-8 8-2 2-8 2-8 17-21 21-2 5-2 2-6 6-14 6-12 12-19 19-14 14-42".split(' ')
s = "1-2 2-3 2-4 3-4".split(' ')

t = [x.split('-') for x in s]
nodes=[]

for i in t:
	for j in i:
		tmp=int(j)
		if not(tmp in nodes):
			nodes.append(tmp)

adj=[]
[adj.append([0 for _ in range(0, len(nodes))]) for _ in range(0, len(nodes))]


for i in t:
	tmp1=int(i[0])
	tmp2=int(i[1])
	tmp1 = f(tmp1, nodes)
	tmp2 = f(tmp2, nodes)
	adj[tmp1][tmp2]=1
	adj[tmp2][tmp1]=1

print nodes
for x in adj:
	print (x)


mx=0

jumps=Stack()
l=len(nodes)

def rec_(jumps,adj,k):
	mx_=jumps.len_()

	last_node=jumps.peek()
	for i in range(l):
		if (adj[last_node][i]):
			if not(jumps.is_in(i)):
				jumps.push(i)
				
				
				tmp = rec_(jumps,adj,k+1)
				
				
				if (tmp>mx_):
					mx_=tmp
				
				jumps.pop()
	return mx_

def rec(adj):
	mx_ = 0
	jumps= Stack() 
	for i in range(l):
		jumps.push(i)
		tmp = rec_(jumps,adj,1)
		if (mx_<tmp):
			mx_ = tmp
		jumps.pop()
	return mx_

'''
for i in range(l):
	jumps.push(i)

	for j in range(l):
		if (adj[i][j]):
			if not (jumps.is_in(j)):
				jumps.push(j)
	
				for k in range(l):
					if (adj[j][k]):
						if not (jumps.is_in(k)):
							jumps.push(k)

							for m in range(l):
								if (adj[k][m]):
									if not (jumps.is_in(m)):
										jumps.push(m)
										if (jumps.len_()>mx):
											mx=jumps.len_()
										jumps.pop()

							if (jumps.len_()>mx):
								mx=jumps.len_()
							jumps.pop()

				if (jumps.len_()>mx):
					mx=jumps.len_()
				jumps.pop()
	
	if (jumps.len_()>mx):
		mx=jumps.len_()
	jumps.pop()
'''


mx=rec(adj)
print mx

