import time
from functools import lru_cache

alpha = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
l, p = input().split()
l = int(l)

start = time.time()

@lru_cache(maxsize=None)
def chains(length, smaller, middle, larger):
    if length >= 3: return 0
    if sum([smaller, middle, larger]) == 0: return 1
    ans = [0]
    if length == 1:
        for i in range(smaller):
            ans.append(chains(length, i, middle, larger + smaller - i - 1))
    else:
        for i in range(smaller):
            ans.append(chains(length, i, middle+smaller-i-1, larger))
    for i in range(middle):
        ans.append(chains(length, smaller, i, larger+middle-i-1))
    for i in range(larger):
        ans.append(chains(length + 1, smaller, middle+i, larger-i-1))
    return sum(ans)

def generateStart(l, p):
    r = list(alpha[:l])
    for item in p:
        r.remove(item)
    return r

def getSeconds(word):
    s = []
    for a in range(1,len(word)):
        if word[a] > min(word[:a]):
            s.append(word[a])
    return s

remaining = generateStart(l,p)
print("remaining: ", remaining)
seconds = getSeconds(p)
print("seconds", seconds)
length = 1 if len(seconds) == 0 else 2
smaller = 0
middle = 0
larger = 0
for item in remaining:
    if item < min(p):
        smaller += 1
    elif seconds and item < min(seconds):
        middle += 1
    else:
        larger += 1

print(chains(length, smaller, middle, larger))

print("Time:", time.time() - start)

