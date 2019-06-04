import random
def f(n):
    forward=0
    back=0
    cases=(0, 1)
    count=0
    while abs(forward-back)<n:
        if random.choice(cases) == 0:
          forward+=1
        else: 
          back+=1
        count+=1
    return count

# n - кол-во вершин m - кол-во испытаний
# avrg
def task_16(n,a):
    l=[]
    for i in range(a):
        l.append(f(n-1))
    print("В среднем",sum(l)/a,"шагов","для обхода",n,"вершинного правильного треугольника")
