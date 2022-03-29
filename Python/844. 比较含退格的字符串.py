class Solution(object):
    def backspace_compare(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        stack_s = []
        for char in iter(s):
            if char == '#' and len(stack_s) != 0:
                stack_s.pop()
            if char != '#':
                stack_s.append(char)
        stack_t = []
        for char in iter(t):
            if char == '#' and len(stack_t) != 0 :
                stack_t.pop()
            if char != '#':
                stack_t.append(char)
        if stack_s == stack_t:
            return True
        return False
