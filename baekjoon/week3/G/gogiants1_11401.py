'''
28776KB	1060ms
조합 정의 이용.
지수함수 분할정복을 이용한 시간 단축.
페르마의 소정리 사용.
'''

def pow(a: int, b: int, mod : int):
    if(b == 0):
        return 1
    elif(b & 1):
        return (pow(a, b // 2, mod) ** 2 * a) % mod
    else:
        return (pow(a, b // 2, mod) ** 2) % mod

def sol(n: int, k: int):
    left = n
    right = k if n - k > k else n - k
    mod = 1000000007
    mul = 1
    div = 1
    res = 1
    for i in range(1, left + 1):
        mul *= i
        mul %= mod
    for j in range(1, k + 1):
        div *= j
        div %= mod
    for j in range(1, n - k + 1):
        div *= j
        div %= mod

    divMod = pow(div, mod - 2, mod)

    res = (mul * divMod) % mod

    return res

n,k = map(int, input().split())
print(sol(n,k))