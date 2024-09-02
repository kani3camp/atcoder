# 効率よく、隣同士の差分の配列を作る（長さn-1）
n = int(input())
if n == 1:
    a = int(input())
    print(1)
    exit()
else:
    a = [int(s) for s in input().split(' ')]

cnt = n + (n - 1)

# 3つ以上連続の場合のみ求める
d_list = []
for i in range(1, n):
    d_list.append(a[i] - a[i - 1])

i_anchor = 0
current_d = d_list[0]
for i in range(1, len(d_list)):
    if d_list[i] == current_d:
        if i == len(d_list) - 1:    # 最後
            x = i + 1 - i_anchor
            cnt += int(x * (x - 1) / 2)
            i_anchor = i
            current_d = d_list[i]
        else:
            continue
    else:
        x = i - i_anchor  # 同じdの連続数
        cnt += int(x * (x - 1) / 2)
        i_anchor = i
        current_d = d_list[i]

print(cnt)
