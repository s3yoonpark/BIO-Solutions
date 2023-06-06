# 31 / 35

from itertools import product 

def solve(start): 
    if len(start) == 1: 
        return "".join(start) 
    
    result = []

    for i in range(len(start)-1): 
        if start[i] == start[i+1]: 
            result.append(start[i])
        else: 
            temp = ["R","G","B"]
            temp.remove(start[i])
            temp.remove(start[i+1])
            result.append(temp[0])
    
    return solve(result)

def a(): 
    while True:
        start = input()
        print(solve(start))

def b_solve(start):
    result = [] 
    for i in range(len(start)-1): 
        if start[i] == start[i+1]: 
            result.append(start[i])
        else: 
            temp = ["R","G","B"]
            temp.remove(start[i])
            temp.remove(start[i+1])
            result.append(temp[0])
    
    return "".join(result) == "RRGBRGBB"

def b(): 

    lst = ["".join(i) for i in product("RGB", repeat = 9)]
    
    for i in lst: 
        if b_solve(i):
            print(i) 

def c(): 
    pass 

def d(): 
    # RBRG
    # G G B 
    # G R 
    # B 

    # RULE : R = 1, B = 2, G = 3
    # 1331 
    # 2 3 2 
    # 1 1 
    # 1 
    # interesting 

    # a b c d 
    # a-b b-c c-d 
    # a-2b+c, b-2c+d 
    # a-3b+3c-d -> a - d 

    # 3(-b + c) part is nullifed as everything is in mod 3 since there is 3 characters RGB 

    # if len(start_row) == 5: 
    # a b c d e
    # a-b b-c c-d d-e 
    # a-2b+c b-2c+d c-2d+e 
    # a-3b+3c-d b-3c+3d-e
    # a-4b+6c+4d+e

    # pascal's triangle 

    # 1
    # 1 1
    # 1 2 1
    # 1 3 3 1 
    # 1 4 6 4 1 
    # 1 5 10 10 5 1 
    # 1 6 15 20 15 6 1 
    # 1 7 21 35 35 21 7 1
    # 1 8 28 56 70 56 28 8 1 
    # 1 9 36 84 126 126 84 36 9 1 -> BOOM everything is a multiple of 3 except the extreme left and right 

    # answer =  10 squares 
    pass 
if __name__ == '__main__': 
    b()
