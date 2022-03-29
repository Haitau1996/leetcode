class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        low = 0
        high = len(height)-1
        result = 0
        while  low < high:
            if (high- low)* min([height[low],height[high]]) > result:
                result = (high- low)* min([height[low],height[high]])
            if height[low] < height[high]:
                low = low + 1
            else:
                high = high -1
        return result
