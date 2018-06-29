import sys
def substr(s, a,l):
	return(s[a:a+l])

def starts_with(s,sub):
	if (len(sub) > len(s)):
		return (0)
	for i in range(len(sub)):
		if (s[i] != sub[i]):
			return(0)
	return(1)
def is_in(s, sub):
	for x in range(len(s)):
		if(starts_with(s[x:],sub)):
			return(1)
	return(0)
def is_in_multiple(s_v,sub):
	for s in s_v:
		if(is_in(s,sub)==0):
			return (0)
	return(1)
def find_sub(s , s_v):
	for l in reversed(range(1,len(s)+1)):
		print "l= "+str(l)
		for b in range(len(s)-l+1):
			print b, l
			temp= substr(s,b,l)
			if(is_in_multiple(s_v,temp)):
				print "Found "+temp
				return(temp)
	return("")
print sys.argv
find_sub(sys.argv[1],sys.argv[2:])