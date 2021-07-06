if __name__ == '__main__':
    N, A, B = [int(x) for x in input().split()]
    
    total = 0
    for i in range(1, N + 1):
        s = str(i)
        digits = []
        for j in s:
            digits.append(int(j))
        if A <= sum(digits) <= B:
            total += i
    print(total)
