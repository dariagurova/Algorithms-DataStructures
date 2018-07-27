import sys

def string_to_words(s):
	res=[]
	start=0
	end=0
	for i in range(len(s)):
		if (s[i] == ' ' or s[i] == '\t'):
			end = i
			res.append(s[start:end])
			start = i+1
	if (end != (len(s)-1)):
		res.append(s[start:])
	return(res)
def words_to_list(arr):
	
	big=[]
	m=0
	flag=0
	for w in arr:
		if (m < len(w)):
			m = len(w)
	for i in range (1,m+1):
		small=[]
		flag=0
		for w in arr:
			if (len(w) == i):
				small.append(w)
				flag=1
		if (flag):
			big.append(small)
	return(big)

def to_lower(c):
	if (c >= 'A' and c <= 'Z'):
		c = chr(ord(c)-ord('A')+ord('a'))
	return(c)
def cmp_char(c1, c2):
	c1 = to_lower(c1)
	c2 = to_lower(c2)
	if (c1 > c2):
		return(1)
	if (c1<c2):
		return(-1)
	return(0)
def cmp(s1, s2):
	for i in range(len(s1)):
		tmp = cmp_char(s1[i], s2[i])
		if (tmp != 0):
			return(tmp)
	return(0)
def ft_swap(a, b):
	return(b,a)
def ft_sort(arr):
	for i in range(1,len(arr)):
		j = i
		while j>0 and cmp(arr[j],arr[j-1]) == -1:
			(arr[j], arr[j-1])=ft_swap(arr[j], arr[j-1])
			j = j-1
	return(arr)

list_of_lists = words_to_list(string_to_words('Pour l Imperium de l humanite'))
for l in list_of_lists:
	tmp=ft_sort(l)
	print tmp
		



