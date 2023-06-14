def solve():
    n, k = map(int, input().split())
    ans = [0] * n
    one = 0

    for i in range(n):
        if ans[i] == 1:
            one += 1
            continue
        else:
            if one < (i + k) // k:
                ans[i] = 1
                one += 1

    one = 0

    for i in range(n - 1, -1, -1):
        if ans[i] == 1:
            one += 1
            continue
        else:
            dum = n - i
            if one < (dum + k - 1) // k:
                ans[i] = 1
                one += 1

    one = 0

    for i in range(n):
        if ans[i] == 1:
            one += 1

    print(one)


t = int(input())
for _ in range(t):
    solve()
