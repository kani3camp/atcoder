import sys

if __name__ == '__main__':
    a = int(input())
    b, c = [int(x) for x in input().split()]
    s = input()
    
    print(f'{a+b+c} {s}')
    pass
