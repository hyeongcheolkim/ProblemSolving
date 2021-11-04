import sys

readline, write = (sys.stdin.readline, sys.stdout.write)
res = []
MOD = 1000000007


class SegTree:
    def __init__(self, data):
        self.data = data
        self.tree = [0] * (len(data) * 4)

    def merge(self, left, right):
        return (left * right) % MOD

    def build(self, node, nodeLeft, nodeRight):
        if nodeLeft == nodeRight:
            self.tree[node] = self.data[nodeLeft]
            return self.tree[node]
        mid = (nodeLeft + nodeRight) // 2
        leftVal = self.build(node * 2, nodeLeft, mid)
        rightVal = self.build(node * 2 + 1, mid + 1, nodeRight)
        self.tree[node] = self.merge(leftVal, rightVal)
        return self.tree[node]

    def query(self, left, right, node, nodeLeft, nodeRight):
        if right < nodeLeft or nodeRight < left:
            return 1
        if left <= nodeLeft and nodeRight <= right:
            return self.tree[node]
        mid = (nodeLeft + nodeRight) // 2
        leftVal = self.query(left, right, node * 2, nodeLeft, mid)
        rightVal = self.query(left, right, node * 2 + 1, mid + 1, nodeRight)
        return self.merge(leftVal, rightVal)

    def update(self, index, newVal, node, nodeLeft, nodeRight):
        if index < nodeLeft or nodeRight < index:
            return self.tree[node]
        if nodeLeft == nodeRight:
            self.tree[node] = newVal
            return self.tree[node]
        mid = (nodeLeft + nodeRight) // 2
        leftVal = self.update(index, newVal, node * 2, nodeLeft, mid)
        rightVal = self.update(index, newVal, node * 2 + 1, mid + 1, nodeRight)
        self.tree[node] = self.merge(leftVal, rightVal)
        return self.tree[node]


n, m, k = [int(i) for i in readline().split()]
data = [0] + [[int(i) for i in readline().split()][0] for _ in range(n)]
st = SegTree(data)
st.build(1, 1, n)
for _ in range(m + k):
    a, b, c = [int(i) for i in readline().split()]
    if a == 1:
        st.update(b, c, 1, 1, n)
    if a == 2:
        res.append(str(st.query(b, c, 1, 1, n)))
write("\n".join(res))