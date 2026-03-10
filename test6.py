memo = [0] * 91

def fibo(x):
    if x == 0:
        return 0
    if x == 1:
        return 1
    
    if memo[x] != 0:
        return memo[x]
    
    memo[x] = fibo(x - 1) + fibo(x - 2)
    return memo[x]


n = int(input())
print(fibo(n))