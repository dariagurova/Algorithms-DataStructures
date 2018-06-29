def is_start(s, start):
	i=0
	if (len(s)< len(start)):
		return (0)
	while (i < len(start)):
		if (s[i] != start[i]):
			return(0)
		i= i+1
	return (1)


s="horse"
sub = "hor123"
a=is_start(s, sub)
print a

def is_sub(s, sub):
	
	if (len(s)<len(sub)):
		return(0)
	for i in range(len(s)):
		if(is_start(s[i:],sub)):
			return (1)
	return (0)


	


s = "horse1234"
i = len(s)
while (i >= 0):
	j = 0
	
	while (j<len(s)-i):
		print s[j:(i+j+1)]
		j = j+1

	i= i-1