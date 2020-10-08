
def permute(arr, ind=0):
    if ind == len(arr):
        yield arr
        return

    for i in range(ind, len(arr)):
        arr[ind], arr[i] = arr[i], arr[ind]
        yield from permute(arr, ind + 1)
        arr[ind], arr[i] = arr[i], arr[ind]

for permutation in permute([1,2,3,4,5,6]):
    print(permutation)

