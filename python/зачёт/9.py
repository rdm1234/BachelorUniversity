################################################################################
class listNode:
    __value=None
    __next=None
    __prev=None

    def set_value(self, x):
        self.__value=x

    def set_next(self,x):
        self.__next=x

    def set_prev(self,x):
        self.__prev=x

    def get_value(self):
        return self.__value

    def get_next(self):
        return self.__next

    def get_prev(self):
        return self.__prev
################################################################################
class stackNode:
    __value=None
    __prev=None

    def set_value(self, x):
        self.__value=x

    def set_prev(self,x):
        self.__prev=x

    def get_value(self):
        return self.__value

    def get_prev(self):
        return self.__prev
################################################################################
class myStack:
    __top = None

    def get_top(self):
        return self.__top

    def __init__(self, value):
        a=stackNode()
        a.set_value(value)
        self.__top=a

    def push(self, value):
        a=stackNode()
        a.set_value(value)
        a.set_prev(self.__top)
        self.__top=a
    def pop_all(self):
        a = []
        while self.__top != None:
            a.append(self.pop())
        print(a)
    def pop(self):
        a = self.__top
        self.delTop()
        self.__top = a.get_prev()
        return a.get_value()
    def delTop(self):
        self.__top = self.__top.get_prev()


################################################################################
class myList:
    __first=None
    __count=0
    __last=None

    def get_count(self):
        return self.__count

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

    def get_stack(self, index):
        return (self.get_elem(index).get_value())

    def get_stack_top_value(self, index):
        return (self.get_stack(index).get_top().get_value())

    def get_last(self):
        return self.__last
    def __init__(self,x):
        a=listNode()
        stc = myStack(x)
        a.set_value(stc)
        self.__first=a
        self.__count+=1
        self.__last=a

    def add_first_stack(self,x):
        if (self.__count != 0):
            a=listNode()
            stc = myStack(x)
            a.set_value(stc)
            self.__first.set_prev(a)
            a.set_next(self.__first)
            self.__first=a
            self.__count+=1
        else:
          a=listNode()
          stc = myStack(x)
          a.set_value(stc)
          self.__first=a
          self.__count+=1
          self.__last=a

    def add_last_stack(self,x):
        if (self.__count != 0):
            a=listNode()
            stc = myStack(x)
            a.set_value(stc)
            self.__last.set_next(a)
            a.set_prev(self.__last)
            self.__last=a
            self.__count+=1
        else:
            a=listNode()
            stc = myStack(x)
            a.set_value(stc)
            self.__first=a
            self.__count+=1
            self.__last=a

    def print_list(self):
        if (self.__first != None):
            x=self.__first
            while x != None:
                while x.get_value().get_top() != None:
                    x.get_value().pop_all()
                x=x.get_next()
            #print(x.get_value().pop())

    def print_all_top(self):
        if self.__first!=None:
            for i in range(self.__count):
                print(self.get_stack_top_value(i))

    def del_first(self):
        if(self.__last!=self.__first):
            a=self.__first
            self.__first.get_next().set_prev(None)
            self.__first=self.__first.get_next()
            a.set_next(None)
            self.__count-=1
        else:
          self.__last=self.__first=None
          self.__count-=1

    def del_last(self):
        if(self.__last!=self.__first):
            a=self.__last
            self.__last.get_prev().set_next(None)
            self.__last=self.__last.get_prev()
            a.set_prev(None)
            self.__count-=1
        else:
          self.__last=self.__first=None
          self.__count-=1
    def input_stack_number(self,stc_number, value):
        a = self.__last
        for i in range(stc_number):
            a.get_next()
        a.get_value().push(value)
    def print_from_stack(self,stack):
        a =self.__last
        for i in range(stack):
            a.get_prev()
        a.get_value().pop_all()
    def pop_from_stack(self,stack):
        a =self.__last
        for i in range(stack):
            a = a.get_prev()
        a.get_value().pop()
    

    def shaker_sort(lst):
        left = 0; right = lst.get_count() - 1
        while left <= right:
            for i in range(left, right, 1):
                if lst.get_stack_top_value(i) > lst.get_stack_top_value(i+1):
                    first = lst.get_elem(i)
                    second = lst.get_elem(i+1)

                    temp = first.get_value()
                    first.set_value(second.get_value())
                    second.set_value(temp)
            right-=1
            for i in range(right, left, -1):
                if lst.get_stack_top_value(i) < lst.get_stack_top_value(i-1):
                    first = lst.get_elem(i-1)
                    second = lst.get_elem(i)
                    temp = first.get_value()
                    first.set_value(second.get_value())
                    second.set_value(temp)
            left+=1
        



################################################################################

def test():
    a = myList(1)
    a.add_last_stack(2)
    a.add_last_stack(3)
    a.add_last_stack(5)
    a.add_last_stack(867)
    a.add_last_stack(-13)
    a.add_last_stack(867)
    a.add_last_stack(4)
    print('list of stacks: ')
    a.print_all_top()
    print('sorted list: ')
    a.shaker_sort()
    a.print_all_top()
    a.get_stack(0).push(44)
    print('list after a.get_stack(0).push(44): ')
    a.print_all_top()
    print('sorted list: ')
    a.shaker_sort()
    a.print_all_top()

    a.get_stack(5).pop()
    print('list after a.get_stack(5).pop(): ')
    a.print_all_top()
    print('sorted list: ')
    a.shaker_sort()
    a.print_all_top()


test()
