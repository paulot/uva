t = int(input())
nums = [int(input()) for _ in range(0, t)]
ans = lambda n: str(int(((((n*567)/9+7492)*235)/47)-498))[-2]
print('\n'.join(map(ans, nums)))
