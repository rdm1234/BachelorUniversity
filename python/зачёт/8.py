def task_8(number):
    lst = [int(i) for i in str(number)]
    lenNumber = len(lst)
    sum = 0
    for i in lst:
        sum  += i**lenNumber
    if sum == number:
        return 1
    else:
        return 0

def test_8():
	for i in range(10000):
	    if task_8(i):
	        print(i)