
mine = [
[ 1, 3, 1, 5 ],
[ 2, 2, 4, 1 ],
[ 5, 0, 2, 3 ],
[ 0, 6, 1, 2 ]
]

def get_max(line,row,n):

	if row==0:
		return(max(line[row],line[row+1]))
	if row==n-1:
		return(max(line[row],line[row-1]))
	return (max(line[row],line[row-1],line[row+1]))


def gold_gain(mine, n):
	l = [0 for _ in range(n)]
	for i in range(n):
		l[i] = mine[i][-1]
	for j in range(n-2, -1, -1):
		
		new_l=[0 for _ in range(n)]
		for k in range(n):
			g_m=get_max(l,k,n)
			new_l[k]=mine[k][j]+g_m
			
		l=new_l
	
	return max(l)

print gold_gain(mine, len(mine))