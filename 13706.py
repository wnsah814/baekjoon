def bs(s, e):
    while True:
        mid = (s + e) // 2
        if mid ** 2 == n:
            return mid
        elif mid ** 2 > n:
            e = mid
        else:
            s = mid
n = int(input())
print(bs(1, n))