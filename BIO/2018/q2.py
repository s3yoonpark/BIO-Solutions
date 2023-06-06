alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def solve(n, w): 
    second_dial = []
    alphabet_copy = list(alphabet)[:]
    n = int(n)
    counter = 0

    while len(alphabet_copy) > 0:
        counter += n - 1
        counter %= len(alphabet_copy)

        moved = alphabet_copy[counter]
        alphabet_copy.remove(moved)
        second_dial.append(moved)

    
    
    encrypted = ""
    for i in range(len(w)): 
        encrypted += second_dial[(alphabet.index(f"{w[i]}") + i)%26]

    return ["".join(second_dial[:6]), encrypted]
    

def a(): 
    while True: 
        n, w = input().split()
        for i in solve(n,w): 
            print(i)

if __name__ == '__main__': 
    a()