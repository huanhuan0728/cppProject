class Solution:
    def isVaild(self, s:str) ->bool:
        stack = []
        for c in s:
            if c in "([{":
                stack.append(c)
            else:
                if not stack:
                    return False
                if stack[-1] == "(" and c == ")":
                    stack.pop()
                elif stack[-1] == "[" and c == "]":
                    stack.pop()
                elif stack[-1] == "{" and c == "}":
                    stack.pop()
                else:
                    return False
            
        return not stack