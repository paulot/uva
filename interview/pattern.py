class Solution(object):
    def tokenize(self, p):
        tokens, i = [], 0

        while i < len(p):
            if i + 1 < len(p) and p[i + 1] == '*':
                tokens.append(p[i:i+2])
                i += 2
            else:
                tokens.append(p[i])
                i += 1

        return tokens

    def isMatch(self, s, p):
        print self.tokenize(p)
        return self.isMatchHelp(s, 0, self.tokenize(p), 0)

    def isMatchHelp(self, s, si, p, pi):
        if si == len(s) and pi == len(p):
            return True

        if si == len(s) and pi < len(p):
            return all(map(lambda a: len(a) == 2, p[pi::]))

        if pi >= len(p) or si >= len(s):
            return False

        if len(p[pi]) == 2:
            if s[si] == p[pi][0] or p[pi][0] == '.':
                return self.isMatchHelp(s, si + 1, p, pi) or self.isMatchHelp(s, si, p, pi + 1)
            else:
                return self.isMatchHelp(s, si, p, pi + 1)
        elif p[pi] == '.' or p[pi] == s[si]:
            return self.isMatchHelp(s, si + 1, p, pi + 1)
        else:
            return False

a = Solution()
print a.isMatch('aa', '.*')
# print a.isMatch('
