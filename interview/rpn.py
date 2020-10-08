def eval_line(line):
    """ Evaluates a reverse polish notation expression. """

    stack = []
    unary_operators = {
        '--': lambda val: val - 1,
        '++': lambda val: val + 1
    }

    binary_operators = {
        '*': lambda lhs, rhs: lhs * rhs,
        '/': lambda lhs, rhs: int(lhs / float(rhs)),
        '+': lambda lhs, rhs: lhs + rhs,
        '-': lambda lhs, rhs: lhs - rhs,
        '^': lambda lhs, rhs: lhs ^ rhs,
        '&': lambda lhs, rhs: lhs & rhs,
        '|': lambda lhs, rhs: lhs | rhs
    }

    for token in line.split():
        if token in binary_operators:
            if len(stack) < 2:
                raise Exception('Malformed expression, too few arguments for binary operation')

            # Pop 2 and do the operation
            rhs = stack.pop()
            lhs = stack.pop()
            stack.append(binary_operators[token](lhs, rhs))
        elif token in unary_operators:
            if len(stack) < 1:
                raise Exception('Malformed expression, too few arguments for unary operation')

            # Pop 1 and do the operation
            stack.append(unary_operators[token](stack.pop()))
        else:
            # Treat the token as a number and push it on the stack
            stack.append(int(token))

    if len(stack) != 1:
        raise Exception('Malformed expression, expected one number to remain, got {0} numbers'.format(len(stack)))

    return stack.pop()


def test_addition():
    assert eval_line('5 5 +') == 5 + 5
    assert eval_line('5 8 + 9 +') == 5 + 8 + 9

def test_subtraction():
    assert eval_line('5 5 -') == 5 - 5
    assert eval_line('5 8 - 9 -') == 5 - 8 - 9

def test_multiplication():
    assert eval_line('5 5 *') == 5 * 5
    assert eval_line('5 8 * 9 *') == 5 * 8 * 9

def test_division():
    assert eval_line('5 5 /') == 5 / 5
    assert eval_line('5 8 / 9 /') == 5 / 8 / 9


'''
test_addition()
test_subtraction()
test_multiplication()
test_division()
'''

print eval_line(' '.join(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]))
