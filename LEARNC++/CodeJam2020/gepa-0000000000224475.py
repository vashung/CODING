import sys


def compute(S):
    last = 0
    x = ""
    for n in map(int, S):
        if n > last:
            x += '(' * (n - last)
        elif n < last:
            x += ')' * (last - n)
        x += str(n)
        last = n
    x += ')' * last
    return x


def parse():
    return sys.stdin.readline().strip(),


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
