

if __name__ == '__main__':
    a, b = [int(x) for x in input().split()]
    product = a * b
    
    if product % 2 == 0:
        print('Even')
    else:
        print('Odd')
