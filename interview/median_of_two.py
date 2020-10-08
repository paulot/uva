def median_dumb(arr1, arr2):
    i, j, m1, m2 = 0, 0, 0, 0

    for count in xrange(1, (len(arr1) + len(arr2)) / 2 + 2):
        m1 = m2
        if i == len(arr1) or arr1[i] > arr2[j]:
            m2 = arr2[j]
            j += 1
        elif j == len(arr2) or arr1[i] <= arr2[j]:
            m2 = arr1[i]
            i += 1

    return m1 if (len(arr1) + len(arr2)) % 2 == 1 else (m1 + m2) / 2

def test_merge_odd_len():
    added = sorted(range(0, 9) + range(0, 10))
    print median_dumb(range(0, 9), range(0, 10)), added[len(added)/2]
    assert median_dumb(range(0, 9), range(0, 10)) == added[len(added)/2]


def test_merge_even_len():
    a1, a2 = range(4, 101, 2), range(8, 100, 3)

    added = sorted(a1 + a2)
    print median_dumb(a1, a2), (added[len(added)/2] + added[len(added)/2 - 1]) / 2
    assert len(added) % 2 == 0
    assert median_dumb(a1, a2) == (added[len(added)/2] + added[len(added)/2 - 1]) / 2

test_merge_odd_len()
test_merge_even_len()
