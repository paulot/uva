import collections

def max_occur(string):
    count = collections.Counter(string)
    max_count = max(count.values())
    return filter(lambda key: count[key] == max_count, count.keys())

print max_occur('asdfasdfasdasas')
