# temp.py


def counters():
    m = []
    x = (input(""))
    a = list(map(int, x.split()))
    for i in a:
        s = a.count(i)
        m.append(s)
    print(x-max(m))


t = int(input(""))
for tc in range(t):
    counters()
