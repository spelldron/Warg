import random



def FastSort(Array):
	if len(Array)>1:
		i = 0
		value = 0
		small = []
		Big = []
		Eq = []
		while i!=len(Array):
			value +=Array[i]
			i+=1
		value = value / len(Array)
		i = 0
		while i != len(Array):
			if Array[i] > value:
				Big.append(Array[i])
			elif Array[i] < value:
				small.append(Array[i])
			else:
				Eq.append(Array[i])
			i+=1
		small = FastSort(small)
		Big = FastSort(Big)
		return FastSort(small) + Eq + FastSort(Big)
	else:
		return Array







array=[]
i = 0
while i !=100000:
	array.append(random.randrange(-1000, 1000, 1))
	i+=1

print(array)
x = FastSort(array)
print(x)	