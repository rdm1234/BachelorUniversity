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
            self.__table[b]=tree(a)
        else:
            self.__table[b].add_node(a,self.__table[b].get_top())

    def find(self, a):
        b=self.hashf(a)
        if self.__table[b]==None:
            return self.__size
        return self.hashf(self.__table[b].find(a,self.__table[b].get_top()))

    def add_list(self,s):
        for i in s:
            self.addvalue(i)
            
class node():
    __left = None
    __right = None
    __data = None

    def __init__(self, value):
        self.__data = value
        self.__left = None
        self.__right = None

    def get_left(self):
        return self.__left
    
    def get_right(self):
        return self.__right
    
    def get_data(self):
        return self.__data

    def set_left(self, x):
        if x==None:
            self.__left=None
        elif isinstance(x, node):
            self.__left= x

    def set_right(self, x):
        if x==None:
            self.__right=None
        elif isinstance(x, node):
            self.__right= x
            
    def set_data(self, x):
        self.__data = x
        
class tree():
    __top = None

    def __init__(self, value):
        self.__top = node(value)

    def get_top(self):
        return self.__top

    def add_node(self, value, current_node):
        if (value >= current_node.get_data()):
            if (current_node.get_right() != None):
                current_node = current_node.get_right()
                self.add_node(value, current_node)
            else:
                a = node(value)
                current_node.set_right(a)
        else:
            if (current_node.get_left() != None):
                current_node = current_node.get_left()
                self.add_node(value, current_node)
            else:
                a = node(value)
                current_node.set_left(a)

                
    def add_list(self, lst):
        for i in lst:
            self.add_node(i, self.get_top())

    def find(self, value, current_node):
        if current_node==None:
            return False
        elif current_node.get_data()==value:
            return current_node.get_data()
        elif current_node.get_data()>value:
            return self.find(value, current_node.get_left())
        else:
            return self.find(value, current_node.get_right())
        
    def show_tree(self, current_node):
        if(current_node.get_left() == None) & (current_node.get_right()==None):
            return [current_node.get_data(),[],[]]
        elif(current_node.get_left() != None) & (current_node.get_right() == None):
            return [current_node.get_data(),self.show_tree(current_node.get_left()),[]]
        elif(current_node.get_left() == None) & (current_node.get_right() != None):
            return [current_node.get_data(),[],self.show_tree(current_node.get_right())]
        else:
            return [current_node.get_data(),self.show_tree(current_node.get_left()),self.show_tree(current_node.get_right())]
def test_12():
	a = hashtable(10)
	a.addvalue(4)
	a.addvalue(44)
	a.addvalue(444)
	print('Список, 5-м элементом которого является дерево (возникает коллизия): \n', a.get_table())
	print('5-й элемент списка - бинарное дерево поиска: \n', a.get_table()[4].show_tree(a.get_table()[4].get_top()))

test_12()

