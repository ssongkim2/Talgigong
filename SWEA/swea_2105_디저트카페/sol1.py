import sys
sys.stdin = open('sample_input.txt')

dr = [-1, 1, 1, -1]
dc = [1, 1, -1, -1]
#2시 ,5시, 7시, 11시

def dfs(row, col, endrow, endcol, direct, cnt, numbers):
    if row < 0 or row >= N or col < 0 or col >= N:
        return                                     #인덱스 조건
    if row == endrow and col == endcol:
        cnt += 1
        if cnt == 2:
            return                                 # 정답조건
    if visited[row][col] == True:
        return                                     #왔는데 왔던곳이면 리턴

    visited[row][col] = True
    nr = row +

    dfs()
    if direct < 4:





T = int(input())
for tc in range(1, 1+T):
    result = []

    N = int(input())
    matrix = [0] * N
    for i in range(N):
        matrix[i] = list(map(int, input().split()))
    # print(matrix)
    visited = [[False for _ in range(N)] for _ in range(N)]
    for row in range(N):
        for col in range(N):

    print(result)

