from collections import deque 

def solve(serial_num): 
    if len(serial_num) == 1:
        return 0 
    queue = deque()
    queue.append(serial_num)
    counter = 0 
    visited = {}

    visited[serial_num] = 0

    def decide(string): 
        if string not in visited: 
            visited[string] = counter 
            queue.append(string)

    while queue:  
        converted = queue.popleft()
    
        counter = visited[converted]+1

        for i in range(1, len(converted) - 2): 
            if (max([int(converted[i]), int(converted[i+1])]) > int(converted[i-1])) and (min([int(converted[i]), int(converted[i+1])]) < int(converted[i-1])): 
                # 12345 -> 12435 
                new = converted[:i] + converted[i+1] + converted[i] + converted[i+2:]
                decide(new)
            elif (max([int(converted[i]), int(converted[i+1])]) > int(converted[i+2])) and (min([int(converted[i]), int(converted[i+1])]) < int(converted[i+2])): 
                new = converted[:i] + converted[i+1] + converted[i] + converted[i+2:]
                decide(new)

        # 12345 -> 21345 

        if (int(converted[2]) > min([int(converted[0]), int(converted[1])])) and (int(converted[2]) < max([int(converted[0]), int(converted[1])])): 
            new = converted[1] + converted[0] + converted[2:]
            decide(new)

        # 12345 -> 12354 
        if (int(converted[-3]) > min([int(converted[-1]), int(converted[-2])])) and (int(converted[-3]) < max([int(converted[-1]), int(converted[-2])])):
            new = converted[:-2] + converted[-1] + converted[-2]
            decide(new)

    maximum = 0 
    for k, v in visited.items(): 
        if maximum < v: 
            maximum = v 
    return maximum 



def modified_solve(serial_num): 
    if len(serial_num) == 1:
        return 0 
    queue = deque()
    queue.append(serial_num)
    counter = 0 
    visited = {}

    visited[serial_num] = 0

    def decide(string): 
        if string not in visited: 
            visited[string] = counter 
            queue.append(string)

    while queue:  
        converted = queue.popleft()
    
        counter = visited[converted]+1

        for i in range(1, len(converted) - 2): 
            if (max([int(converted[i]), int(converted[i+1])]) > int(converted[i-1])) and (min([int(converted[i]), int(converted[i+1])]) < int(converted[i-1])): 
                # 12345 -> 12435 
                new = converted[:i] + converted[i+1] + converted[i] + converted[i+2:]
                decide(new)
            elif (max([int(converted[i]), int(converted[i+1])]) > int(converted[i+2])) and (min([int(converted[i]), int(converted[i+1])]) < int(converted[i+2])): 
                new = converted[:i] + converted[i+1] + converted[i] + converted[i+2:]
                decide(new)

        # 12345 -> 21345 

        if (int(converted[2]) > min([int(converted[0]), int(converted[1])])) and (int(converted[2]) < max([int(converted[0]), int(converted[1])])): 
            new = converted[1] + converted[0] + converted[2:]
            decide(new)

        # 12345 -> 12354 
        if (int(converted[-3]) > min([int(converted[-1]), int(converted[-2])])) and (int(converted[-3]) < max([int(converted[-1]), int(converted[-2])])):
            new = converted[:-2] + converted[-1] + converted[-2]
            decide(new)

    return visited

def a(): 
    while True: 

        number = int(input())
        serial_num = input()

        print(solve(serial_num))
        print()

def b(): 
    dic = {}
    dic = modified_solve('324165')
    maximum = 0 
    for k, v in dic.items(): 
        if maximum < solve(k):
            maximum = solve(k)
    print(maximum)

    

    dic = modified_solve('183654792')
    maximum = 0 
    for k, v in dic.items(): 
        if maximum < solve(k):
            maximum = solve(k)
    print(maximum)

def c(): 
    # 1 1 
    # 12 -> 1 
    # 123 -> 132 -> 213 -> 231 -> 312 -> 321 
    pass 

if __name__ == '__main__': 
    a()