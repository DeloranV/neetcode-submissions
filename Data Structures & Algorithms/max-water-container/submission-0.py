class Solution:
    def maxArea(self, heights: List[int]) -> int:
        areas = []
        l, r = 0, len(heights) - 1

        while l < r:
            min_height = min(heights[l], heights[r])
            area = (r - l) * min_height
            areas.append(area)
            if heights[l] < heights[r]: l += 1
            else: r -= 1

        return max(areas)
