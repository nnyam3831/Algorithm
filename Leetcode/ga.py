# Leetcode no.49 Group Anagrams

class Solution:
    def groupAnagrams(self, strs: [str]) -> [[str]]:
        store = {}

        for string in strs:
            target = ''.join(sorted(string))
            store[target] = store.get(target, []) + [string]

        return list(store.values())


sol = Solution()
print(sol.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
print(sol.groupAnagrams([""]))
print(sol.groupAnagrams(["a"]))
