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
		
class deque:
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
            self.__count+=1
        else:
          a=Node()
          a.set_value(x)
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
            self.__count+=1
        else:
            a=Node()
            a.set_value(x)
            self.__first=a
            self.__count+=1
            self.__last=a  
            

    def print_deque(self):
        if (self.__first != None):
            x=self.__first
            while x.get_next()!=None:
                print(x.get_value())
                x=x.get_next()
            print(x.get_value())

    def pop_first(self):
        if self.__first!=None:
            a=b=self.__first
            self.__first=self.__first.get_next()
            a.set_next(None)
            self.__count-=1
            return b.get_value()
        else:
            return None
          
          
    def pop_last(self):
        if self.__last!=None:
            a=b=self.__last
            self.__last=self.__last.get_prev()
            a.get_prev().set_next(None)
            self.__count-=1
            return b.get_value()
        else:
            return None

def test_10():
    a=deque(5)
    print("Созданный дек с первым значением 5: ")
    a.print_deque()
    a.add_first(3)
    print("После добавления 3 в начало дека: ")
    a.print_deque()
    a.add_last(2)
    a.add_last(8)
    a.add_last(10)
    print("После добавления 2, 8, 10 в конец дека: ")
    a.print_deque()
    print("Извлечение первого элемента:", a.pop_first())
    print("После извлечения первого элемента: ")
    a.print_deque()
    print("Извлечение последнего элемента:", a.pop_last())
    print("После извлечения последнего элемента: ")
    a.print_deque()


test_10()
