
def tokenize_num(string, pos):
    num = 0
    while pos < len(string) and string[pos] in '1234567890':
        num = num * 10 + int(string[pos])
        pos += 1

    return num, pos

def tokenize(string, pos=0):
    print string
    if pos >= len(string):
        return []

    if string[pos] in '1234567890':
        num, pos = tokenize_num(string, pos)
        return [num] + tokenize(string, pos)
    elif string[pos] in '+-()':
        return [string[pos]] + tokenize(string, pos + 1)
    else:
        raise Exception('Cannot decode token')


def perform_operation(operation, lhs, rhs):
    print lhs, operation, rhs
    if operation == '+':
        return lhs + rhs
    elif operation == '-':
        return lhs - rhs


def validate_token(token, num=True):
    if num and not isinstance(token, int):
        raise Exception('Malformed expression expected number got {0}'.format(token))
    elif not num and isinstance(token, int):
        raise Exception('Malformed expression expected symbol got {0}'.format(token))
    return token


def eval_expr(tokens):
    if len(tokens) == 0:
        return 0
    elif len(tokens) == 2:
        raise Exception('Malformed expression')

    first = tokens.pop(0)

    if isinstance(first, int):
        operator = validate_token(tokens.pop(0), False)
        rhs = tokens.pop(0)

        if rhs == '(':
            rhs = eval_expr(tokens)
            return perform_operation(operator, first, rhs)
        elif isinstance(rhs, int):
            return perform_operation(operator, first, rhs)
    elif first == '(':
        result = eval_expr(tokens)
        rightParen = validate_token(tokens.pop(0), False)
        return result





# print tokenize('23+123+1223+1234-992-2323')
print eval_expr(tokenize('(((23+123)+(1223+1234))-(992-2323))'))

