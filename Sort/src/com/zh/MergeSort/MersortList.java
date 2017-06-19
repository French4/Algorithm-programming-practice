package com.zh.MergeSort;

public class MersortList {
	static int data[] = {1,2,3,4,5,5,6,4,1,3};
	static int temp[] = new int[data.length];
	public static void main(String[] args) {
		merge(data);
	}
	private static void merge(int[] data2) {
		mergeSort(data2,0,data2.length);
	}
	private static void mergeSort(int[] data2, int low, int high) {
		if(low >= high) //此时证明已经是单个数字，不需要在分
			return;
		int mid = low+(high-low)/2;//向下取整
		mergeSort(data2, mid+1, high);
		mergeSort(data2, low ,mid);
		merge(data2,low, mid, high);
	}
	private static void merge(int[] data2, int lo, int mid, int hi) {
		int i = lo, j = mid+1;//讲数组分成两部分
		for(int k = lo; k <= hi; k++)
			temp[k] = data2[k];  //复制数组
		//归并回数组
		for(int k = lo; k <= hi; k++){
			if(i > mid) data2[k] = temp[j++]; //第一个数组没有了
			else if(j > hi) data2[k] = temp[i++]; //第二个数组没有了
			if(less(temp[i], temp[j])) data2[k] = temp[i++];//小的数字放在前面
			else		data2[k] = temp[j++];
		}
	}
	private static boolean less(int i, int j) {
		if(i < j)
			return true;
		else
			return false;
	}
	
}
