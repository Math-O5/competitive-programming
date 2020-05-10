n = int(input())
dp = [0]*2020
resp = 0

for i in range(n):
    s = input()
    cmd, _x = s.split()
    x = int(_x)
    if(cmd[0] == "w"):
        dp[x] = resp + 2**x
    else:
        resp = max(dp[x], resp)

print(resp)