
def is_in(l, el):
	for i in range(len(l)):
		if (l[i] == el):
			return(1)
	return(0)


def for_(n,tab, c):
	if(c==n):
		print(tab)
	else:
		for k in range(n):
			if(not is_in(tab,k)):
				tab[c] = k
				for_(n,tab,c+1)
			tab[c]=-1

n = 4
tab = [-1,-1,-1,-1,-1]
for i in range(n):
	tab[0] = i
	for_(n,tab,1)
	tab[1]=-1
				


def for_m(n,tab,c_num):

	for m in range(n):
		if(not is_in(tab,m)):
			tab[c_num] = m
			print(tab)
		tab[c_num]=-1
def for_l(n,tab,c):
	for l in range(n):
		if(not is_in(tab,l)):
			tab[c] = l
			for_m(n,tab,c+1)
		tab[c]=-1	
def for_k(n,tab,c):
	for k in range(n):
		if(not is_in(tab,k)):
			tab[c] = k
			for_l(n,tab,c+1)
		tab[c]=-1
def for_j(n,tab,c):
	for j in range(n):
		if(not is_in(tab,j)):
			tab[c] = j
			for_l(n,tab,c+1)
		tab[c]=-1