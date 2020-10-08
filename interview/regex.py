# Function to match .* or ? to a string

def tokenize(regex):
    ans, i  = [], 0

    while i < len(regex):
        if i + 1 < len(regex) and regex[i + 1] == '*':
            ans.append(regex[i:i+2])
            i += 2
        else:
            ans.append(regex[i])
            i += 1
    return ans



def match(string, si, regex, ri):
    if si >= len(string) and ri >= len(regex):
        return True
    elif si >= len(string) and ri < len(regex):
        return all(map(lambda token: token == '.*', regex[ri:]))
    elif si < len(string) and ri >= len(regex):
        return False

    if len(regex[ri]) == 2:
        if regex[ri][0] == '.' or string[si] == regex[ri][0]:
            return match(string, si + 1, regex, ri) or match(string, si, regex, ri + 1)
        else:
            return match(string, si, regex, ri + 1)
    elif regex[ri] == '?' or string[si] == regex[ri]:
        return match(string, si + 1, regex, ri + 1)

    return False

def isMatch(string, regex):
    return match(string, 0, tokenize(regex), 0)

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
