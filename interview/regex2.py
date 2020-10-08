
def tokenize(regex):
    tokens, i = [], 0

    while i < len(regex):
        if i + 1 < len(regex) and regex[i + 1] == '*':
            tokens.append(regex[i:i+2])
            i += 2
        else:
            tokens.append(regex[i])
            i += 1

    return tokens


def match(string, regex, si=0, ri=0):
    if si >= len(string) and ri >= len(regex):
        return True
    elif si >= len(string) and ri < len(regex):
        return all(map(lambda token: len(token) == 2 and token[1] == '*', regex[ri:]))
    elif si < len(string) and ri >= len(regex):
        return False

    if len(regex[ri]) == 2:
        if regex[ri][0] == string[si] or regex[ri][0] == '.':
            return match(string, regex, si + 1, ri) or match(string, regex, si + 1, ri + 1)
        else:
            return match(string, regex, si + 1, ri + 1)
    elif regex[ri] == '?' or regex[ri] == string[si]:
        return match(string, regex, si + 1, ri + 1)
    else:
        return False

def isMatch(string, regex):
    return match(string, tokenize(regex))


print isMatch('asdfasdfasdf', 'asdfasdfasdf')
print isMatch('asdfasdfasdf', 'asdfa*sdf.*')
print isMatch('asdfasdfasdf', '.*.*.*')
print isMatch('asdfasdfasdf', '????asdf????')
print isMatch('asdfasdfasdf', 'asdfa*sdf.*??')
print
print isMatch('asdfasdfasdf', 'asdfasdfasdf?')
print isMatch('asdfasdfasdf', 'asdfa*sdf.*a')
print isMatch('asdfasdfasdf', '.*.*.*a')
print isMatch('asdfasdfasdf', '????asdf????b')
