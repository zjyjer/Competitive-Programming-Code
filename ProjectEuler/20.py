from math import factorial

n = input()
for i in range(0,n):
    m = input()
    f = factorial(m)
    s = str(f)
    ans = 0
    for i in range(0,len(s)):
        ans += int(s[i])
    print ans
