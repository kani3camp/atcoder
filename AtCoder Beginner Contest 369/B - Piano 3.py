n = int(input())
a_list = []
s_list = []

for _ in range(n):
    a, s = input().split(' ')
    a_list.append(int(a))
    s_list.append(s)

l_list = []
r_list = []

for i in range(n):
    if s_list[i] == 'L':
        l_list.append(a_list[i])
    elif s_list[i] == 'R':
        r_list.append(a_list[i])

l_sum = 0
r_sum = 0

for j in range(len(l_list)):
    if j > 0:
        l_sum += abs(l_list[j] - l_list[j-1])
    
for k in range(len(r_list)):
    if k > 0:
        r_sum += abs(r_list[k] - r_list[k-1])

print(l_sum + r_sum)
