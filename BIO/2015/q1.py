from itertools import combinations 

def solved(word): 
    if len(word) == 1: 
        return 1

    count = 0
    # BBACBB
    splitting = ""
    for i in range(1,len(word)): 
        splitting += f"{i}"
    
    for i in range(1, len(word)): 
        lst = [i for i in combinations(splitting, i)]
        for j in range(len(lst)): 
            temp = split(word, lst[j])
            if temp == temp[::-1]: 
                count += 1 

    return count

def split(word, condition): 
    temp = []
    built_up = 0

    # 12345 
    # remove 3 
    # 12345[3:]
    # 45 
    for i in range(len(condition)): 
        add = word[:int(condition[i])]
        temp.append(add[built_up:])
        built_up = len(add)
    
    if condition[-1] == len(word): 
        pass 
    else: 
        temp.append(word[int(condition[-1]):])
    
    return temp 
            
# BONBON 
# B O N 

def a(): 
    word = input()
    print(solved(word))

if __name__ == '__main__': 
    a()
