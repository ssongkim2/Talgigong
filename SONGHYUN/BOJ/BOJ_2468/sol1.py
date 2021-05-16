import sys
sys.stdin = open('input.txt')

move = [[-1, 0], [0, 1], [1, 0], [0, -1]] #상우하좌
def BFS(row, col, i):
    queue = [[row, col]]
    while queue:
        cur = queue.pop(0)
        numbers[cur[0]][cur[1]] = 0
        for i in range(4):
            nr = cur[0] + move[i][0]
            nc = cur[1] + move[i][1]
            if nr < 0 or nr >= N or nc < 0 or nc >= N:
                continue
            else:
                if numbers[nr][nc] > i:
                    queue += [[nr, nc]]

    return

N = int(input())
max_num = 0
numbers = [0] * N
num_list = []

max_cnt = 0
for idx in range(N):
    numbers[idx] = list(map(int, input().split()))
# for row in range(N):
#     for col in range(N):
#         if numbers[row][col] not in num_list:
#             num_list.append(numbers[row][col])
# num_list.sort()
# for i in num_list:
#     cnt = 0
#     for row in range(N):
#         for col in range(N):
#             if numbers[row][col] > i:
#                 BFS(row, col, i)
#                 cnt += 1
#     if max_cnt < cnt:
#         max_cnt = cnt
#
# print(max_cnt)
num = set(numbers)
print(num)

