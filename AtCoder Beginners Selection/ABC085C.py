input_list = input().split()
n, y = int(input_list[0]), int(input_list[1])

cnt_1000 = 0
cnt_5000 = 0
cnt_10000 = 0
remain = y

while True:
    if n == 0:
        print('-1 -1 -1')
        break

    x = remain // n
    if 1000 >= x:
        cnt_1000 += 1
        remain -= 1000
    elif 5000 >= x:
        cnt_5000 += 1
        remain -= 5000
    elif 10000 >= x:
        cnt_10000 += 1
        remain -= 10000
    
    if remain == 0:
        print(f'{cnt_10000} {cnt_5000} {cnt_1000}')
        break
    elif remain < 0:
        print('-1 -1 -1')
        break
    
    n -= 1
