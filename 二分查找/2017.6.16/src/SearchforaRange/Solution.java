package SearchforaRange;

public class Solution {
    public int[] searchRange(int[] nums, int target) {
       int start = binSearch(nums, target);
       if (start == nums.length || nums[start] != target) {//只有一个元素且没找到时候，start返回1
			return new int[]{-1, -1};
		}
       int end = binSearch(nums, target+1)-1;
       return new int[]{start, end};
    }

	private int binSearch(int[] nums, int target) {
		int low = 0;
		int high = nums.length;
		while(low < high){
			int middle =low+(high-low)/2;
			if(nums[middle] < target)  //low指针永远不会后退，只有目标值小于中位数的时候才会前进。
				low = middle + 1;
			else
				high = middle;
		}
		return low;
	}
}