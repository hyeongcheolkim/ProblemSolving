import sys

readline, write = (sys.stdin.readline, sys.stdout.write)
INF = float("inf")
res = []

n, m = [int(i) for i in readline().split()]


class SegTree:
    def __init__(self, data):
        self.data = data
        self.tree = [0] * (len(self.data) * 4)

    def merge(self, left, right):
        return min(left, right)

    def build(self, node=1, nodeLeft=1, nodeRight=n):
        if nodeLeft == nodeRight:
            self.tree[node] = self.data[nodeLeft]
            return self.tree[node]
        mid = (nodeLeft + nodeRight) // 2
        leftVal = self.build(node * 2, nodeLeft, mid)
        rightVal = self.build(node * 2 + 1, mid + 1, nodeRight)
        self.tree[node] = self.merge(leftVal, rightVal)
        return self.tree[node]

    def query(self, left, right, node=1, nodeLeft=1, nodeRight=n):
        if right < nodeLeft or nodeRight < left:
            return INF
        if left <= nodeLeft and nodeRight <= right:
            return self.tree[node]
        mid = (nodeLeft + nodeRight) // 2
        leftVal = self.query(left, right, node * 2, nodeLeft, mid)
        rightVal = self.query(left, right, node * 2 + 1, mid + 1, nodeRight)
        return self.merge(leftVal, rightVal)


data = [0] + [[int(i) for i in readline().split()][0] for _ in range(n)]
st = SegTree(data)
st.build()
for _ in range(m):
    a, b = [int(i) for i in readline().split()]
    res.append(str(st.query(a, b)))
write("\n".join(res))