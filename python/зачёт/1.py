import random

#1 Шейкер-сортировка с встроенным листом
def shaker_sort_1(lst):
	if lst == []:
		return []
	#compare = 0; perm = 0; 
	left = 0; right = len(lst) - 1
	while left <= right:
		for i in range(left, right, 1):
			#compare+=1
			if lst[i] > lst[i+1]:
				#perm+=1
				lst[i], lst[i+1] = lst[i+1], lst[i]
		right-=1
		for i in range(right, left, -1):
			#compare+=1
			if lst[i]<lst[i-1]:
				#perm+=1
				lst[i], lst[i-1] = lst[i-1], lst[i]
		left+=1
	#return [compare, perm]

def gen(n):
    return random.sample(range(2*n), n)

def test_1_1(n):
    lst = gen(n)
    print('before',lst)
    print('result', shaker_sort_1(lst))
    print('after',lst)

#################С реализованным списком##################
class Node:
    __value=None
    __next=None
    __prev=None

    def set_value(self, x):
        self.__value=x

    def set_next(self,y):
        self.__next=y

    def set_prev(self,y):
        self.__prev=y

    def get_value(self):
        return self.__value

    def get_next(self):
        return self.__next
    
    def get_prev(self):
        return self.__prev

class MyList:
	__first=None
	__count=0
	__last=None

	def __init__(self,val):
		a=Node()
		a.set_value(val)
		self.__first=a
		self.__count+=1
		self.__last=a

	def add_last(self,x):
		if (self.__count != 0):
			a=Node()
			a.set_value(x)
			self.__last.set_next(a)
			a.set_prev(self.__last)
			self.__last=a
		else:
			a=Node()
			a.set_value(x)
			self.__first=a
			self.__last=a
		self.__count+=1

	def print_list(self):
		if (self.__first != None):
			x=self.__first
			while x.get_next()!=None:
				print(x.get_value())
				x=x.get_next()
			print(x.get_value())

	def get_value(self, index):
		if index >= self.__count:
			return False
		x = self.__first
		if index == 0:
			return x.get_value()
		elif index == self.__count-1:
			return self.__last.get_value()

		for i in range(index):
			x = x.get_next()
		return x.get_value()

	def get_elem(self, index):
		if index >= self.__count:
			return False
		x = self.__first
		if index == 0:
			return x
		elif index == self.__count-1:
			return self.__last

		for i in range(index):
			x = x.get_next()
		return x

	def get_count(self):
		return self.__count

def genList(n):
	lst = MyList(random.randint(-n, n))
	for i in range(n-1):
		lst.add_last(random.randint(-n, n))
	return lst

#1 Шейкер-сортировка с созданным выше листом
def shaker_sort_2(lst):
	#compare = 0; perm = 0; 
	left = 0; right = lst.get_count() - 1
	while left <= right:
		for i in range(left, right, 1):
			#compare+=1
			if lst.get_value(i) > lst.get_value(i+1):
				#perm+=1
				first = lst.get_elem(i)
				second = lst.get_elem(i+1)
				temp = first.get_value()
				first.set_value(second.get_value())
				second.set_value(temp)
		right-=1
		for i in range(right, left, -1):
			#compare+=1
			if lst.get_value(i) < lst.get_value(i-1):
				#perm+=1
				first = lst.get_elem(i-1)
				second = lst.get_elem(i)
				temp = first.get_value()
				first.set_value(second.get_value())
				second.set_value(temp)
		left+=1
	#return [compare, perm]
	
def test_1_2(n):
	lst = genList(n)
	print('before')
	lst.print_list()
	#print('result', shaker_sort_2(lst))
	print('after')
	lst.print_list()