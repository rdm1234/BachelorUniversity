import random
def task_6(myList):
	min = 0
	for i in range(len(myList)):
		if myList[min] > myList[i] :
			min = i
	return min

def test_6():
	myList = [random.randint(0,20) for i in  range(10)]
	print(myList)
	newList = []

	for i in range(len(myList)):
		if i == 0:
			min = task_6(myList)
			newList.insert(0,myList[min])
			myList.pop(min)
		elif i == 1:
			min = task_6(myList)
			newList.insert(-i/2,myList[min])
			myList.pop(min)
		elif i % 2 == 0:
			min = task_6(myList)
			newList.insert(i/2,myList[min])
			myList.pop(min)
		else:
			min = task_6(myList)
			newList.insert(-i/2,myList[min])
			myList.pop(min)

	newList.reverse()
	print(newList)

# n - длина случайногенерированного списка
def test_6_v2(n):
  lst = [random.randint(1, 100) for i in range(n)]
  print("Исходный список:",lst)
  s=sorted(lst)
  print("Отсортированный список:",s)
  print("Полученный список:",s[::2]+s[1::2][::-1])