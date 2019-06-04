def task_7():
    mxLength=1
    while True:
        for k in range(mxLength):
            for l in range(mxLength):
                for i in range(mxLength):
                    for j in range(mxLength):
                        if (k**3 + l**3 == i**3 + j**3):
                            if(k!=i & k!=j & k!=l & l!=i & l!=j & i!=j):
                                return (k**3+l**3)
        mxLength+=1
