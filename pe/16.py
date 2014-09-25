t = input()
for i in range(0, t):
    n = input()
    ans = str(2 ** n)
    sol = 0
    for j in range(len(ans)):
        sol += int(ans[j])
    print sol
    i += 1
