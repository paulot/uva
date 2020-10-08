
def depthsum(num, depth=0):
    return depth * num if isinstance(num, int) else sum(depthsum(n, depth + 1) for n in num)

assert depthsum([[1,1],2,[1,1]]) == 10
assert depthsum([1,[4,[6]]]) == 27
