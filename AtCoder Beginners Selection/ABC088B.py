n = int(input())
a_list = [int(a) for a in input().split()]

pick = [[], []]

for i in range(len(a_list)):
    picked = a_list.pop(a_list.index(max(a_list)))
    pick[i % 2].append(picked)

print(sum(pick[0]) - sum(pick[1]))
