def prefix_scores(text, prefix):
    scores = [0] * (len(text) + 1)
    cur = len(prefix) - 1

    for i in xrange(len(text) - 1, -1, -1):
        if text[i] == prefix[cur]:
            cur -= 1

            if cur < 0:
                cur = len(prefix) - 1

            scores[i] = scores[i + 1] + 1
        else:
            cur = len(prefix) - 1

    return scores[:len(text)]

def suffix_scores(text, suffix):
    scores = [0] * (len(text) + 1)
    cur = 0

    for i in xrange(len(text)):
        if text[i] == suffix[cur]:
            scores[i + 1] = scores[i] + 1
            cur += 1

            if cur >= len(suffix):
                cur = 0

        else:
            cur = 0

    return scores[1::]

def best_sub(text, prefix, suffix):
    pscores, sscores = prefix_scores(text, prefix), suffix_scores(text, suffix)
    score, ans = -1, None

    print pscores, sscores

    for i in xrange(0, len(text)):
        for j in xrange(i, len(text)):
            assert len(text[i:j + 1]) == j - i + 1
            cur_score = min(j - i + 1, pscores[i]) + min(j - i + 1, sscores[j])

            if cur_score > score or (cur_score == score and text[i:j + 1] < ans):
                score = cur_score
                ans = text[i:j + 1]

    return ans

print best_sub('nothing', 'bruno', 'ingenious')
print best_sub('ab', 'b', 'a')
