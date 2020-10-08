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


def serialize(root):
    if root == None:
        return None
    return [root.val, serialize(root.left), serialize(root.right)]

def deserialize(arr):
    if arr == None:
        return None
    return Node(arr[0], deserialize(arr[1]), deserialize(arr[2]))

def print_bst(root):
    if root == None:
        return

    print_bst(root.left)
    print root.val
    print_bst(root.right)

import random
arr = [random.randint(1, 50) for _ in xrange(5)]
print arr
root = Node(arr[0])
for num in arr[1:]:
    root.insert(num)

print serialize(root)
print_bst(root)
print_bst(deserialize(serialize(root)))

