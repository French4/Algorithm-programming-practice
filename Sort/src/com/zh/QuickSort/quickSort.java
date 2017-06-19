package com.zh.QuickSort;

import Utils.out.print;

public class quickSort {
	static int data[] = {1,2,3,4,5,5,6,4,1,3};//要排序数组
	public static void main(String[] args) {
		quickSort(data, 0, data.length-1);
		print.println(data);
	}
	private static void quickSort(int[] data2, int low, int hi) {
		if(low >= hi)
			return; //排序完成的标志，这是一个数字不需要排序
		int j = portion(data2, low, hi);//分隔数组
		quickSort(data2, low, j-1);//排序走边
		quickSort(data2, j+1, hi);//排序右边
	}
	private static int portion(int[] data2, int low, int hi) {
		int temp = data2[low]; //这个是切分元素
		int i = low;
		int j = hi+1;//(low, hi+1)中是待排序的元素
		while(true){
			while(data2[++i]<temp){
				if(i >= hi)
					break;
			}//在左边找到第一个比temp大的元素
			while(data2[--j]>temp){
				if(j <= low)
					break;
			}
			if(i >= j)
				break;
			each(data2, i, j); //交换
		}
		each(data2, low, j); //交换
		return j;
	}
	public static void each(int[] data2, int i, int j) {
		int temp = data2[i];
		data2[i] = data2[j];
		data2[j] = temp;
	}
}
