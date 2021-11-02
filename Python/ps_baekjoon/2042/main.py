import sys

readline, write = (sys.stdin.readline, sys.stdout.write)

n, m, k = [int(i) for i in readline().split()]
res = []


class SegTree:
    def __init__(self, data: list, size: int):
        self.size = size
        self.arr = data
        self.tree = [0] * (len(data) * 4)
        self.build(1, 1, self.size)

    def merge(self, left, right) -> int:
        return left + right

    def build(self, node, nodeLeft, nodeRight) -> int:
        if nodeLeft == nodeRight:
            self.tree[node] = self.arr[nodeLeft]
            return self.tree[node]
        mid = (nodeLeft + nodeRight) // 2
        leftVal = self.build(node * 2, nodeLeft, mid)
        rightVal = self.build(node * 2 + 1, mid + 1, nodeRight)
        self.tree[node] = self.merge(leftVal, rightVal)
        return self.tree[node]

    def query(self, left, right, node, nodeLeft, nodeRight) -> int:
        if right < nodeLeft or nodeRight < left:
            return 0
        if left <= nodeLeft and nodeRight <= right:
            return self.tree[node]
        mid = (nodeLeft + nodeRight) // 2
        return self.merge(
            self.query(left, right, node * 2, nodeLeft, mid), self.query(left, right, node * 2 + 1, mid + 1, nodeRight)
        )

    def update(self, index, newValue, node, nodeLeft, nodeRight):
        if index < nodeLeft or nodeRight < index:
            return self.tree[node]
        if nodeLeft == nodeRight:
            self.tree[node] = newValue
            return self.tree[node]
        mid = (nodeLeft + nodeRight) // 2
        leftVal = self.update(index, newValue, node * 2, nodeLeft, mid)
        rightVal = self.update(index, newValue, node * 2 + 1, mid + 1, nodeRight)
        self.tree[node] = self.merge(leftVal, rightVal)
        return self.tree[node]


data = [0]
for _ in range(n):
    data.append([int(i) for i in readline().split()][0])
segTree = SegTree(data, n)
for _ in range(m + k):
    a, b, c = [int(i) for i in readline().split()]
    if a == 1:
        segTree.update(b, c, 1, 1, n)
    if a == 2:
        res.append(str(segTree.query(b, c, 1, 1, n)))
write("\n".join(res))