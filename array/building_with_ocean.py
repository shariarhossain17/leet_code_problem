from typing import List


class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        length = len(heights)
        val = heights[length - 1]
        res = [length - 1]

        for i in range(length - 2, -1, -1):
            if heights[i] > val:
                val = heights[i]
                res.append(i)

        res.reverse()
        return res

sol = Solution()

t = int(input()) 
1
while t:
    n = int(input())  
    arr = []
    arr = list(map(int, input().split()))

    print(sol.findBuildings(arr)) 
    t -= 1  
