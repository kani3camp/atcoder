a, b = [int(i) for i in input().split()]

if a == b:
    print(1)
else:
    if abs(a- b) % 2 == 0:
        print(3)
    else:
        print(2)

