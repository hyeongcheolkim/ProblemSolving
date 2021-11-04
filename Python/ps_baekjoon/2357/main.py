import sys
from collections import namedtuple

readline, write = (sys.stdin.readline, sys.stdout.write)
MinMax = namedtuple("MinMax", "min max")
INF = float("inf")
res = []


class SegTree:
    def __init__(self, data):
        self.data = data
        self.tree = [0] * (len(self.data) * 4)

    def merge(self, left, right) -> MinMax:
        return MinMax(min(left.min, right.min), max(left.max, right.max))

    def build(self, node, nodeLeft, nodeRight) -> MinMax:
        if nodeLeft == nodeRight:
            self.tree[node] = MinMax(self.data[nodeLeft], self.data[nodeLeft])
            return self.tree[node]
        mid = (nodeLeft + nodeRight) // 2
        leftVal: MinMax = self.build(node * 2, nodeLeft, mid)
        rightVal: MinMax = self.build(node * 2 + 1, mid + 1, nodeRight)
        self.tree[node] = self.merge(leftVal, rightVal)
        return self.tree[node]

    def query(self, left, right, node, nodeLeft, nodeRight) -> MinMax:
        if right < nodeLeft or nodeRight < left:
            return MinMax(INF, -INF)
        if left <= nodeLeft and nodeRight <= right:
            return self.tree[node]
        mid = (nodeLeft + nodeRight) // 2
        leftVal: MinMax = self.query(left, right, node * 2, nodeLeft, mid)
        rightVal: MinMax = self.query(left, right, node * 2 + 1, mid + 1, nodeRight)
        return self.merge(leftVal, rightVal)


n, m = [int(i) for i in readline().split()]
data = [0] + [[int(i) for i in readline().split()][0] for _ in range(n)]
st: SegTree = SegTree(data)
st.build(1, 1, n)
for _ in range(m):
    a, b = [int(i) for i in readline().split()]
    ret = st.query(a, b, 1, 1, n)
    res.append(f"{ret.min} {ret.max}")
write("\n".join(res))