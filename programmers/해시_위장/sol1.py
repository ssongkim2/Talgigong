from collections import Counter
from itertools import combinations
from itertools import permutations

# def solution(clothes):
#     cloth = []
#     ans = 1
#     for idx in range(len(clothes)):
#
#         cloth.append(clothes[idx][1])
#
#     cloth_Counter = Counter(cloth)
#
#     for k in cloth_Counter.values():
#
#         ans *= k+1
#     return ans - 1
#
# print(solution(clothes))

mylist = [1,2,3]
result = combinations(mylist, r=2)
print(list(result))
result2 = permutations(mylist, 2)
print(list(result2))
mylist2 = [1,1,1,2]
C_list = Counter(mylist2)
print(C_list.values())