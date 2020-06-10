def minWindow(s, t):
    if len(t) > len(s):
        return ''

    _dict = {}
    for tt in t:
        _dict[tt] = _dict.get(tt, 0) + 1

    counter = len(_dict)
    begin = end = head = 0
    result = 9999999999
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
            if end - begin < result:
                result = end - begin
                head = begin

            begin += 1
    if result == 9999999999:
        return ""
    return s[head:head+result]


print(minWindow("ADOBECODEBANC", "ABC"))
