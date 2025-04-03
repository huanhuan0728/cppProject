from typing import List

class Solution:
    def generateParenthesis(self,n:int)->List[str]:
        result = []
        self.backTrack(result, "", 0, 0, n)
        return result
    
    def backTrack(self,result:List[str], cur:str, open:int, close:int, max:int):
        if (len(cur) == max * 2):
            result.append(cur)
            return
        if (open < max):
             self.backTrack(result, cur + "(", open+1, close, max)
        if (close < open):
            self.backTrack(result, cur + ")", open, close+1, max)
        