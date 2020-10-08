dictionary = set(['bla', 'blu', 'bau'])

def printPath(start, end):
    print ''.join(start)
    if start == end:
        return

    for i in xrange(len(start)):
        if start[i] != end[i]:
            tmp, start[i] = start[i], end[i]
            if ''.join(start) in dictionary:
                return printPath(start, end)
            start[i] = tmp

printPath(list('bla'), list('bau'))
