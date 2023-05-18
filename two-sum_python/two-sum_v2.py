class Solution(object):
    def twoSum(self, nums, target):
        prevMap={}
        for index,value in enumerate(nums):
            diff = target - value
            if diff in prevMap:
                return (prevMap[diff],index)
            prevMap[value]=index
        return
    
a = Solution()
print(a.twoSum([3,2,3],6))