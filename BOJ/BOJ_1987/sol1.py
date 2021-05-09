import sys
sys.stdin = open('input.txt')

def dfs(row, col):
    if row < 0 or row >= R or col < 0 or col >= R:
        return
    if matrix[row][col] in queue:
        return
    else:
        queue.append(matrix[row][col])
        dfs(row-1, col)
        dfs(row+1, col)
        dfs(row, col-1)
        dfs(row, col+1)
        return len(queue)

R, C = map(int, input().split())
matrix = [0]*R
max1 = 0
for idx in range(R):
    matrix[idx] = input()
for row in range(len(matrix)):
    for col in range(len(matrix[0])):
        queue = []
        cnt = 0
        result = dfs(row, col)
        if result != None:
            if result >= max1:
                max1 = result
print(max1)



# print(matrix)