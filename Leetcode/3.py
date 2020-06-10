def sol(s):
    result = 0
    _dict = {}
    begin = end = 0
    counter = 0
    _len = 0
    while end < len(s):
        c = s[end]
        _dict[c] = _dict.get(c, 0) + 1
        if _dict[c] > 1:
            counter += 1
        end += 1

        while counter > 0:
            tempc = s[begin]
            if tempc in _dict:
                _dict[tempc] -= 1
                if _dict[tempc] == 1:
                    counter -= 1
            begin += 1
        result = max(result, end-begin)
    return result


print(sol('abcabcbb'))
print(sol('bbbbb'))
print(sol('pwwkew'))
