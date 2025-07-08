from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        """
        Find all unique triplets in the array which gives the sum of zero.
        Time Complexity: O(n^2)
        Space Complexity: O(n) for sorting (if not in-place), O(1) for output (not counting result)
        """
        # Initialize result list to store all valid triplets
        res = []
        # Sort the array to handle duplicates and use two-pointer technique
        # Sorting helps us:
        # 1. Skip duplicates easily
        # 2. Use two-pointer technique effectively
        # 3. Avoid duplicate triplets in the result
        nums.sort()

        # Iterate through each number as potential first element of triplet
        for i,a in enumerate(nums):
            # Skip if current number is same as previous number
            # This ensures we don't process duplicate triplets
            # Example: [-1,-1,0,1] -> skip second -1 to avoid duplicate [-1,0,1]
            if i > 0 and a == nums[i - 1]:
                continue

            # Initialize two pointers for the remaining elements
            # l starts from next element after i
            # r starts from the end of array
            l, r = i + 1, len(nums) - 1
            
            # Continue until pointers meet
            while l < r:
                # Calculate sum of three numbers
                sum3 = a + nums[l] + nums[r]
                
                # If sum is greater than 0, we need a smaller sum
                # Since array is sorted, moving right pointer left will give us a smaller number
                if sum3 > 0:
                    r = r - 1
                # If sum is less than 0, we need a larger sum
                # Moving left pointer right will give us a larger number
                elif sum3 < 0:
                    l = l + 1
                # If sum is 0, we found a valid triplet
                else:
                    # Add the triplet to result
                    res.append([a, nums[l], nums[r]])
                    # Move left pointer to find next potential triplet
                    l += 1
                    # Skip duplicates for the second number
                    # This ensures we don't add duplicate triplets
                    # Example: [-1,0,0,0,1] -> after finding [-1,0,1], skip other 0s
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
        
        return res

# -------------------
# Test Cases
# -------------------
def test_three_sum():
    s = Solution()
    # Test case 1: Example
    nums = [-1,0,1,2,-1,-4]
    result = s.threeSum(nums)
    assert sorted([sorted(triplet) for triplet in result]) == sorted([[-1,-1,2],[-1,0,1]])
    # Test case 2: No solution
    nums = [1,2,3,4,5]
    result = s.threeSum(nums)
    assert result == []
    # Test case 3: All zeros
    nums = [0,0,0,0]
    result = s.threeSum(nums)
    assert result == [[0,0,0]]
    # Test case 4: Duplicates
    nums = [-2,0,0,2,2]
    result = s.threeSum(nums)
    assert sorted([sorted(triplet) for triplet in result]) == sorted([[-2,0,2]])
    # Test case 5: Large negative and positive
    nums = [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
    result = s.threeSum(nums)
    expected = [[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]
    assert sorted([sorted(triplet) for triplet in result]) == sorted(expected)
    print("All test cases passed!")

if __name__ == "__main__":
    test_three_sum()
