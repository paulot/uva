class LRUCache(object):
    def __init__(self, store, size=10):
        self.store = store
        self.size = size
        self.keys = []
        self.cache = {}

    def access(self, key):
        if key in self.cache:
            to_remove = self.keys.index(key)
            del self.keys[to_remove]
            self.keys.append(key)
        else:
            if len(self.keys) >= self.size:
                evicted = self.keys.pop(0)  # Evict least recently used
                del self.cache[evicted]


            self.keys.append(key)
            self.cache[key] = self.store.get(key)

        return self.cache[key]

store = dict((i, i) for i in xrange(0, 1000))
cache = LRUCache(store)

for i in xrange(0, 100):
    print cache.access(i), cache.keys, len(cache.keys), len(cache.cache)
