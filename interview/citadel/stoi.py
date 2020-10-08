def stoi(s, base=10):
    val, negative = 0, s[0] == '-'

    if negative:
        s = s[1:]

    numbers = '0123456789abcdef'

    for c in s:
        if c in numbers[:base]:
            val *= base
            val += numbers.index(c)
        else:
            break

    return val if not negative else -val

print stoi('asdfasdf')
print stoi('1234')
print stoi('-1232asdf')
print stoi('3232')
print stoi('a', 11)
