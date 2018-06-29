zone = [
        "1 1 1 1 1 1 1 1",
        "1 0 0 0 1 0 0 1",
        "1 0 0 1 0 0 0 1",
        "1 0 1 1 0 0 0 1",
        "1 1 1 0 0 0 0 1"]

gzone = [s.split() for s in zone]
lenx=len(gzone[0])
leny = len(gzone)

def legit(point):
	(x,y)=point
	if (x<0 or y<0):
		return(0)
	if (x>=lenx or y>=leny):
		return(0)
	if(gzone[y][x] != '0'):
		return(0)
	return(1)

def paint(point):
	global gzone
	(x,y) = point
	gzone[y][x] = 'F'

def left(point):
	(x,y)=point
	res = legit ((x-1,y))
	return (res)
def right(point):
	(x,y)=point
	res = legit ((x+1,y))
	return (res)
def up(point):
	(x,y)=point
	res = legit ((x,y+1))
	return (res)
def down(point):
	(x,y)=point
	res = legit ((x,y-1))
	return (res)
def printer():
	for a in gzone:
		print a

def fill(point):
	global gzone
	(x,y)=point
	if (not legit(point)):
		return
	paint(point)
	if (left(point)):
		fill((x-1,y))
	if (right(point)):
		fill((x+1,y))
	if (up(point)):
		fill((x,y+1))
	if (down(point)):
		fill((x,y-1))
	return

printer()
print "*****************************************"
fill((2,1))
printer()