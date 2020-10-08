def balance(string):
    char_val = lambda char: 1 if char == '(' else -1 if char == ')' else 0
    number_open = reduce(lambda nopen, char: nopen + char_val(char), string, 0)
    return string + ')' * number_open if number_open > 0 else '(' * (-number_open) + string

print balance('(')
print balance('((')
print balance('(((')
print balance('())')
print balance('()))')
print balance('()()()))))')
