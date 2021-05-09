import sys
sys.stdin = open('input.txt')

N = int(input())
numbers = list(map(int, input().split()))
dp1 = [0] * N
dp2 = [0] * N

for i in range(N):
    temp = 0
    for j in range(i):
        if numbers[j] < numbers[i]:
            temp = max(temp, dp1[j])