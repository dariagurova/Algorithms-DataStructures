arr = "1357913579024680213579"


def pr_l(l):
	for i in l:
		print (i)

def find_max_pair(bal_list):
	maX=0
	(x1,x2) = (0,0)
	for l in bal_list:
		if (l):
			dist = l[-1] - l[0]
			if (dist > maX):
				maX = dist;
				(x1,x2) = (l[0], l[-1])
	return(maX,x1,x2)






bal = 0
neg_bal=[[] for i in range(len(arr)+1)]
pos_bal=[[] for i in range(len(arr)+1)]
print (neg_bal)
print (pos_bal)

for i in range(len(arr)):
	
	if  (int(arr[i])%2==1):
		bal = bal + 1
		print "bal++"
	else:
		bal = bal - 1
		print "bal--"
	print (arr[i],bal,i)
	if (bal>0):
		pos_bal[bal].append(i)
	else:
		neg_bal[-bal].append(i)
print("-----------")
pr_l (neg_bal)
print("+++++++++++")
pr_l (pos_bal)

n = find_max_pair(neg_bal)
p = find_max_pair(pos_bal)
print(n)
print(p)
if (p > n):
	print arr[p[1]+1:p[2]+1]
else:
	print arr[n[1]+1:n[2]+1]


