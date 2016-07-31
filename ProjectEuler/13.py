###python 2.7
n = input()
ans = 0
for i in range(1, n+1):
    s = input()
    ans += s
ans = str(ans)
print ans[0:10]
