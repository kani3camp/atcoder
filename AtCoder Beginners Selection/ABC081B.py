

if __name__ == '__main__':
    N = int(input())
    A_list = [int(x) for x in input().split()]
    
    count = 0
    while sum([1 if (x % 2 == 1) else 0 for x in A_list]) == 0:
        A_list = [x / 2 for x in A_list]
        count += 1
    print(count)
