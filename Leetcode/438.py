def sol(s, p):
    result = []
    _dict = {}
    for pp in p:
        _dict[pp] = _dict.get(pp, 0) + 1
    counter = len(_dict)
    begin = end = head = 0
    _len = len(p)

    while end < len(s):
        c = s[end]
        if c in _dict:
            _dict[c] -= 1
            if _dict[c] == 0:
                counter -= 1
        end += 1

        while counter == 0:
            tempc = s[begin]
            if tempc in _dict:
                _dict[tempc] += 1
                if _dict[tempc] > 0:
                    counter += 1

            if end-begin == _len:
                result.append(begin)
            begin += 1
    return result


print(sol("cbaebabacd", "abc"))
print(sol("abab", "ab"))
