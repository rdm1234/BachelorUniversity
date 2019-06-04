class hashtable():
    __table=None
    __size=None

    def __init__(self, n):
        self.__table=[]
        for i in range(n):
            self.__table.append(None)
        self.__size=n

    def get_table(self):
        return self.__table

    def get_size(self):
        return self.__size

    def hashf(self,s):
        if type(s)==str:
            H=0
            for i in s:
                H=(H<<4)+ord(i)
                G=H&0xF0000000
                if G!= 0:
                    H=(H^(G>>24))^G
            return H%self.__size
        else:
            H=0
            H=(H<<4)+s
            G=H&0xF0000000
            if G!= 0:
                H=(H^(G>>24))^G
            return H%self.__size
        
    def addvalue(self, a):
        b=self.hashf(a)
        if self.__table[b]==None:
            self.__table[b]=MyList(a)
        else:
            self.__table[b].add_last(a)

    def find(self, a):
        b=self.hashf(a)
        if self.__table[b]==None:
            return self.__size
        self.__table[b].change_first(self.__table[b].find_elem(a))

    def add_list(self,s):
        for i in s:
            self.addvalue(i)

##############################################################################
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

	def add_first(self,x):
		if (self.__count != 0):
			a=Node()
			a.set_value(x)
			self.__first.set_prev(a)
			a.set_next(self.__first)
			self.__first=a
		else:
			a=Node()
			a.set_value(x)
			self.__first=a
			self.__last=a  
		self.__count+=1

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

	def del_first(self):
		if(self.__last!=self.__first):
			a=self.__first
			self.__first.get_next().set_prev(None)
			self.__first=self.__first.get_next()
			a.set_next(None)
		else:
			self.__last=self.__first=None
		self.__count-=1

	def del_last(self):
		if(self.__last!=self.__first):
			a=self.__last
			self.__last.get_prev().set_next(None)
			self.__last=self.__last.get_prev()
			a.set_prev(None)
		else:
			self.__last=self.__first=None
		self.__count-=1

	def del_elem(self, index):
		if self.__count != 0:
			el = self.get_elem(index)
			if el==False:
				return False

			self.__count-=1
			if (el.get_next()==None) & (el.get_prev()==None):
				self.__first = None
				self.__last = None
			elif el.get_next()==None:
				el.get_prev().set_next(None)
				self.__last = el.get_prev()
			elif el.get_prev()==None:
				el.get_next().set_prev(None)
				self.__first = el.get_next()
			else:
				el.get_prev().set_next(el.get_next())
				el.get_next().set_prev(el.get_prev())
			return True
		else:
			return False


	def find_elem(self, value):
		x = self.__first
		for i in range(self.__count):
			if x.get_value() == value:
				return i
			x = x.get_next()

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
		if (index >= self.__count) | (index < 0):
			return False
		x = self.__first
		if index == 0:
			return x
		elif index == self.__count-1:
			return self.__last

		for i in range(index):
			x = x.get_next()
		return x

	def change_first(self, index):
		if self.__count > 1:
			a = self.get_elem(index)
			if a != False:
				self.del_elem(index)
				self.add_first(a.get_value())		

	def get_count(self):
		return self.__count

def test_11():
	a = hashtable(10)
	a.addvalue(4)
	a.addvalue(44)
	a.addvalue(444)
	print('list: ')
	a.get_table()[4].print_list()
	a.find(444)
	print('find(444): ')
	a.get_table()[4].print_list()
	print('find(44): ')
	a.find(44)
	a.get_table()[4].print_list()