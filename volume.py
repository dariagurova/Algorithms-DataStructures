def highest(l):
	ind=0
	for i in range(1, len(l)):
		if (l[i] > l[ind]):
			ind = i
	return (ind)

l = [3, 1 , 2, 4, 3, 11, 4, 5, 2, 7]

def	pour_water(l,size):
	water_lvl=l[0]
	water_volume=0
	h=highest(l)
	for i in range(1,h):
		if (l[i]<water_lvl):
			water_volume = water_volume + water_lvl - l[i]
		if(l[i] > water_lvl):
			water_lvl = l[i]
	water_lvl=l[-1]
	for i in range(size-1, h, -1):
		if (l[i] < water_lvl):
			water_volume = water_volume + water_lvl - l[i]
		if(l[i] > water_lvl):
			water_lvl = l[i]

	print water_volume

pour_water(l, 10)

