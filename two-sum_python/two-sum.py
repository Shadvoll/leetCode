class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        self.nums_ind = sorted([(nums[i],i) for i in range(len(nums))])
        for value, index in self.nums_ind:
            result = self.binSearch(target-value)
            if result is not False and result != index:
                return [index,result]
        return -1


    def binSearch(self,value):
        left = 0
        right = len(self.nums_ind)
        mid = (right+left)//2
        while right-left>1:
            if self.nums_ind[mid][0] == value:
                return self.nums_ind[mid][1]
            elif value > self.nums_ind[mid][0]:
                left = mid
            else:
                right = mid
            mid = (right + left) // 2
        return self.nums_ind[mid][1] if self.nums_ind[mid][0] == value else False
        
a = Solution()
print(a.twoSum([3,2,3],6))