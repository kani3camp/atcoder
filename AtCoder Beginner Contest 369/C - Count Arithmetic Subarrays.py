n = int(input())
a = [int(s) for s in input().split(' ')]

cnt = n + (n - 1)

# 3つ以上連続の場合のみ求める
for i in range(0, n - 2):  # 起点
    # print(f'{i=}')
    d = a[i + 1] - a[i]
    for j in range(i + 2, n):
        # print(f'{j=}')
        dd = a[j] - a[j - 1]
        if d == dd:
            cnt += 1
        else:
            break

print(cnt)
