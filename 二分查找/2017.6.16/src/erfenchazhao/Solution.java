package erfenchazhao;

public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
      for(int i = 0; i< matrix.length; i++){
    	  if(binSearch(target, matrix[i]))
    		  return true;
      }
      return false;
    }

	private boolean binSearch(int target, int[] is) {
		int low = 0;
		int high = is.length-1;
		int middle;
		while(low <= high){
			middle = low +(high-low)/2;
			if(is[middle] == target){
				return true;
			}
			else if(is[middle] < target)
				low = middle+1;
			else
				high = middle-1;
		}
		return false;
	}
}
/*
 * [[1,3,5,7],[10,11,16,20],[23,30,34,50]]
3
 * */
