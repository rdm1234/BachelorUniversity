import random
import math

def task_3(N, towns):
	if towns == []:
		return [None, None]
	xSum=0; ySum=0
	for i in range(N):
		xSum+=towns[i][0]
		ySum+=towns[i][1]
	middle = [int(round(xSum/N)), int(round(ySum/N))]
	if isBusy(N, towns, middle) == False:
		return middle
	else:
		i = 1
		result = False
		while result == False:
			result = findAdditional(N, towns, middle, i)
			i+=1
		return result

def findAdditional(N, towns, middle, radius):
	left = [middle[0], middle[1] - radius]
	right = [middle[0], middle[1] + radius]
	tempCoords = left
	result = tempCoords
	minAvgDis = findAvgDis(N, towns, result)
	for i in range(1, radius+1):
		tempCoords = [left[0] + i, left[1] + i]
		tempValue = findAvgDis(N, towns, tempCoords)
		if tempValue < minAvgDis:
			if isBusy(N, towns, tempCoords) == False:
				minAvgDis = tempValue
				result = tempCoords
		tempCoords = [left[0] - i, left[1] + i]
		tempValue = findAvgDis(N, towns, tempCoords)
		if tempValue < minAvgDis:
			if isBusy(N, tempCoords) == False:
				minAvgDis = tempValue
				result = tempCoords

	for i in range (1, radius):
		tempCoords = [right[0] + i, right[1] - i]
		tempValue = findAvgDis(N, towns, tempCoords)
		if tempValue < minAvgDis:
			if isBusy(N, tempCoords) == False:
				minAvgDis = tempValue
				result = tempCoords
		tempCoords = [right[0] - i, right[1] - i]
		tempValue = findAvgDis(N, towns, tempCoords)
		if tempValue < minAvgDis:
			if isBusy(N, tempCoords) == False:
				minAvgDis = tempValue
				result = tempCoords

	if (result == left) & (isBusy(N, towns, left) == True):
		return False
	else:
		return result

# ср. арифм. расст. от точки до остальных
def findAvgDis(N, towns, coords):
	distSum = 0
	for i in range(N):
		distSum+=math.fabs(towns[i][0]-coords[0]) + math.fabs(towns[i][1]-coords[1])
	return distSum/(N)

def isBusy(N, towns, coords):
	for i in range(N):
		if ((towns[i][0] == coords[0]) & (towns[i][1] == coords[1])):
			return True
	return False

def gen_towns(n):
	towns = [[None, None]] * n
	for i in range(n):
		towns[i] = [random.randint(-n*2, n*2), random.randint(-n*2, n*2)]
	print(towns)
	return towns

def test_3(n):
	towns = gen_towns(n)
	print(task_3(n, towns))
