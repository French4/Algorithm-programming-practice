package com.zh.MergeSort;

import Utils.out.print;

/*
 * 有序数组的
 * */
public class MergeSort {
 static int[] data1 = {2, 7, 9, 19, 63, 97, 100, };
 static int[] data2 = {3, 6 ,8, 55,232,464,1011};
 static int[] data3 = new int[data1.length+data2.length];
 	public static void main(String[] args) {
		merge(data1, data2);
		print.println(data3);
	}
	private static void merge(int[] data12, int[] data22) {
		int i = 0, j = 0;
		int count = 0;
		while(i < data1.length && j < data2.length){
			if(data1[i] < data2[j])
				data3[count++] = data1[i++]; //将这个数组中较小的一个放在其中
			else
				data3[count++] = data2[j++];
		}
		while(i < data1.length){
			data3[count++] = data1[i++];
		}
		
		while(j < data2.length){
			data3[count++] = data2[j++];
		}
	}
}
