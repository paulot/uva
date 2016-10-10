t = int(input())
sals = [sorted(map(int, input().split())) for _ in range(0, t)]
print('\n'.join(map(lambda a: 'Case {0}: {1}'.format(a[0]+1, a[1][1]), enumerate(sals))))
