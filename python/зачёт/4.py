# emps имеет след. структуру:
# [[id, year, month], ....]
def test_4():
    task_4([emp(1,1995,1), emp(2,1990,1), emp(3,1999,8), emp(4, 1999, 5)])

def task_4(emps):
    h = heap()
    h.add_list(emps)
    print("До сортировки")
    for i in emps:
        i.print_emp()
    h.sort()
    # отсортированные сотрудники (по году)
    emps = h.look()[3]
    match = []
    ch = False
    temp = []
    # поиск совпадений по year
    if len(emps) <= 2:
        if emps[0].get_year() == emps[1].get_year():
            match = [[0, 1]]
    else:
        for i in range(len(emps)-1):
            if emps[i].get_year() == emps[i+1].get_year():
                if ch == False:
                    temp = [i, i+1]
                    ch = True
                else:
                    temp[1] = i+1
                    ch = False
                    match.append(temp)

    # сортировка по month
    for i in range(len(match)):
        temp_emps = emps[(match[i][0]-1) : match[i][1]]
        Shell(temp_emps)
        emps[(match[i][0]-1) : match[i][1]] = temp_emps
        
    print("После сортировки")
    # окончательно отсортированные
    for i in emps:
        i.print_emp()


def Shell(month, emps):
    t = int(len(month)/2)
    while t > 0:
        for i in range(len(month)-t):
            j = i
            while j >= 0 and month[j] > month[j+t]:
                month[j], month[j+t] = month[j+t], month[j]
                emps[j], emps[j+t] = emps[j+t], emps[j]
                j -= 1
        t = int(t/2)

class emp():
    __year = None
    __month = None
    __id = None

    def __init__(self, id_emp, year, month):
        self.__year = year
        self.__id = id_emp
        self.__month = month

    def print_emp(self):
        print ('id:', self.__id, '; year:', self.__year, '; month:', self.__month, ';')

    def get_id(self):
        return self.__id

    def get_year(self):
        return self.__year

    def get_month(self):
        return self.__month

class heap():
    __body = []
    __emps = []
 
    def __init__(self):
        self.__body = []
        self.__emps = []
 
    def add(self, emp):
        self.__body.append(emp.get_year())
        self.__emps.append(emp)
        self.bubble_up(len(self.__body)-1)
 
    def get_left_child(self, number):
        try:
            return [self.__body[2*number + 1], self.__emps[2*number + 1]]
        except:
            return None
 
    def get_right_child(self, number):
        try:
            return [self.__body[2*number + 2], self.__emps[2*number + 2]]
        except:
            return None

    def get_parent(self, number):
        if number-1>=0:
            return [self.__body[(number-1)//2], self.__emps[(number-1)//2]]
        else:
            return [self.__body[0], self.__emps[0]]

 
    def look(self):
        return ['body: ', self.__body, 'emps: ', self.__emps]
 
    def add_list(self, emps):
        for i in emps:
            self.add(i)
 
    def bubble_up(self, number):
        if number == 0:
            return True
        if (self.__body[number] <= self.get_parent(number)[0]):
            return True
        else:
            a = self.__body[number]
            e = self.__emps[number]
            self.__body[number] = self.get_parent(number)[0]
            self.__emps[number] = self.get_parent(number)[1]
            self.__body[(number-1)//2] = a
            self.__emps[(number-1)//2] = e
            self.bubble_up((number-1)//2)
 
    def sort(self):
        n=len(self.__body)-1
        while n>=0:
            self.__body[0], self.__body[n] = self.__body[n], self.__body[0]
            self.__emps[0], self.__emps[n] = self.__emps[n], self.__emps[0]
            self.bubble_down(0, n)
            n-=1
 
    def bubble_down(self, number, length):
        if number == length:
            return True
        if 2*number +1>= length:
            return True
        else:
            left = self.get_left_child(number)
        if 2*number +2>= length:
            right = None
        else:
            right = self.get_right_child(number)
        if(right == None):
            tempLeft = left[0]
            tempRight = tempLeft -1
        else:
            tempLeft = left[0]
            tempRight = right[0]
        if tempLeft > tempRight:
            if self.__body[number]<left[0]:
                self.__body[2*number +1] = self.__body[number]
                self.__emps[2*number+1] = self.__emps[number]
                self.__body[number] = left[0]
                self.__emps[number] = left[1]
                self.bubble_down(2*number+1, length)
        else:
            if self.__body[number]<right[0]:
                self.__body[2*number +2] = self.__body[number]
                self.__emps[2*number +2] = self.__emps[number]
                self.__body[number] = right[0]
                self.__emps[number] = right[1]
                self.bubble_down(2*number+2, length)
