import sys

INF = 987654321

def floyd(w, n, m):
    for k in range(1, n+1):
        for i in range (1, n+1):
            for j in range(1, n+1):
                if w[i][j] > w[i][k] + w[k][j] :
                    w[i][j] = w[i][k] + w[k][j]
    
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i == j:
                w[i][j] = 0
            elif w[i][j] == INF:
                w[i][j] = 0


def main():
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    w = []
    for i in range(n+1) :
        w.append([INF] * (n+1))

    for _ in range(0, m) :
        a, b, c = map(int, sys.stdin.readline().split())
        if w[a][b] > c:
            w[a][b] = c

    floyd(w, n, m)

    for i in range(1, n+1):
        for j in range(1, n+1):
            print("{} ".format(w[i][j]), end='')
        print()
    return

if __name__ == "__main__":
    main()