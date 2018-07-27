
def find_perms(n):
	res = 1
	for i in range(1, n+1):
		res = res*i
	return (res)

counter = 0

f = find_perms(3)
l_l=[[] for _ in range(f)]

def rec(n,i,l):
	global counter
	global l_l
	if(n==i):
		print l
		l_l[counter]=l
		counter = counter + 1
		return
	for x in range (n):
		if (not (x in l)):
			l_=l + [x]
			rec(n,i+1,l_)


l = []


rec(3,0,l)

print "******************************"

print l_l
	

