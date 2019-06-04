def task_5(n,m):
    x_incr=1
    y_incr=0
    x=0
    y=0
    arr = [[None] * m for _ in range(n)]
    for i in range(1, n*m+1):
        arr[x][y] = i
        x_new=x+x_incr
        y_new=y+y_incr
        if 0 <= x_new < n and 0 <= y_new < m and not arr[x_new][y_new]:
            x=x_new
            y=y_new
        else:
            x_incr, y_incr = -y_incr, x_incr
            x=x+x_incr
            y=y+y_incr
    for x in list(zip(*arr)):
        print(x)