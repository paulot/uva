class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.right = right
        self.left = left

    def insert(self, val):
        if val > self.val:
            if self.right is None:
                self.right = Node(val)
            else:
                self.right.insert(val)
        elif val < self.val:
            if self.left is None:
                self.left = Node(val)
            else:
                self.left.insert(val)


def lca(root, val1, val2):
    if root == None:
        return (None, 0)

    left, countl = lca(root.left, val1, val2)
    right, countr = lca(root.right, val1, val2)
    equal = root.val == val1 or root.val == val2

    if countl == 2:
        return (left, countl)
    elif countr == 2:
        return (right, countr)
    elif countr + countl + equal == 2:
        return (root, 2)
    else:
        return (None, countl + countr + equal)


import random
arr = [random.randint(1, 50) for _ in xrange(5)]
print arr
root = Node(arr[0])
for num in arr[1:]:
    root.insert(num)
node, num = lca(root, arr[3], arr[4])
print node.val, num
