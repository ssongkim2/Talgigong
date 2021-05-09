import sys
sys.stdin = open('input.txt')

#dp
T = int(input())
dp = [[0] * T for i in range(T)]
s = list(map(int, input().split()))
# b는 선택하는 배열의 처음과 끝 간격
for tc in range(T):

    # 시작 위치를 0부터 끝까지 설정
    for start in range(T):
        end = start + b

        if end >= T:
            break

        # 길이 1짜리
        if start == end:
            # 펠린드롬이 항상 맞다.
            dp[start][end] = 1
            continue

        # 길이 2짜리
        if start + 1 == end:
            # 두원소가 같으면 펠린드롬이다.
            if s[start] == s[end]:
                dp[start][end] = 1
                continue

        # 길이 3이상짜리 커버
        if s[start] == s[end] and dp[start + 1][end - 1]:
            dp[start][end] = 1

m = int(input())
for i in range(m):
    a, b = map(int, input().split())
    print(dp[a - 1][b - 1])
