n = int(input()) #nxn
dir = input().split() #방향 입력

x, y = 1, 1 #초기화

for a in dir:
    nx, ny = x, y

    if a == 'R':
        ny = y + 1
    elif a == 'L':
        ny = y - 1
    elif a == 'U':
        nx = x - 1
    elif a == 'D':
        nx = x + 1
    
    if nx < 1 or ny < 1 or nx > n or ny > n:
        continue 

    x, y = nx, ny

print(x, y)