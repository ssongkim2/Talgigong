import sys
sys.stdin = open('input.txt')

N = int(input())
numbers = []
for _ in range(N):
    i = int(input())
    numbers.append(i)
sum = 0
for i in range(len(numbers)):
    for j in range(1, len(numbers)):
        for k in range(2, len(numbers)):
            sum = i + j + k

while front <= rear:
    mid = (front + rear) // 2
    if front >
