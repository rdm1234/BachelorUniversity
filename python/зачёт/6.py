import random

# n - длина случайногенерированного списка
def task_6(n):
  lst = [random.randint(1, 100) for i in range(n)]
  print("Исходный список:",lst)
  s=sorted(lst)
  print("Отсортированный список:",s)
  print("Полученный список:",s[::2]+s[1::2][::-1])