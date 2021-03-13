class Solution(object):
    def replaceSpace(self, s):
        """
        :type s: str
        :rtype: str
        """
        l = []
        for i in s:
            if i == ' ':
                l.append("%20")
            else:
                l.append(i)
        return "".join(l)

a = Solution()
print(a.replaceSpace("We are happy."))