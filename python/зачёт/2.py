
def find_disorder(lst):
	counter = [0]*len(lst)
	for i in range(len(lst)-1):
		for j in range(i, len(lst)):
			if lst[i] > lst[j]:
				counter[i]+=1
	print('Счётчик: ', counter)

	disorder = 0; min_dis_elem = 0; max_dis_elem = 0; minElem = counter[0]; maxElem = counter[0]
	maxValue = lst[0]; minValue = lst[0]

	for i in range(len(counter)):
		disorder+=counter[i]
		if counter[i] < minElem:
			minElem = counter[i]
			min_dis_elem = i
			minValue = lst[i]
		if counter[i] > maxElem:
			maxElem = counter[i]
			max_dis_elem = i
			maxValue = lst[i]
	# disorder - беспорядок
	# max_dis_elem, maxValue, maxElem - id элемента; сам элемент; беспорядок, который вносит
	return [disorder,  (max_dis_elem, maxValue, maxElem), (min_dis_elem, maxValue, minElem)]

# оба элемента пары вносят беспорядок
def find_disorder_v2(lst):
	counter = [0]*len(lst)
	disorder = 0
	for i in range(len(lst)-1):
		for j in range(i, len(lst)):
			if lst[i] > lst[j]:
				counter[i]+=1
				counter[j]+=1
				disorder+=1
	print('Счётчик: ', counter)

	min_dis_elem = 0; max_dis_elem = 0; minElem = counter[0]; maxElem = counter[0]

	for i in range(len(counter)):
		if counter[i] < minElem:
			minElem = counter[i]
			min_dis_elem = i
		if counter[i] > maxElem:
			maxElem = counter[i]
			max_dis_elem = i
	return [disorder,  (max_dis_elem, maxElem), (min_dis_elem, minElem)]

import random

def gen(n):
	return random.sample(range(2*n), n)

def test_disorder(n):
	a = gen(n)
	print('Первая версия :\n')
	print('Список: ', a)
	print(find_disorder(a))
	print('\nВторая версия :\n')
	print('Список: ', a)
	print(find_disorder_v2(a))
