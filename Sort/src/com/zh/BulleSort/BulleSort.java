package com.zh.BulleSort;

import Utils.out.print;

public class BulleSort {
	static int[] data = {9,2,7,19,100, 97, 63};
	
	/*
	 * ð��������ǽ���һ�αȽϺ󣬽�������ַ������
	 * */
	public static void main(String[] args) {
		bulleSort(data);
		print.println(data);
	}

	private static void bulleSort(int[] data2) {
		for(int i = 0; i < data2.length; i++){
			for(int j = 0; j < data2.length-1-i;j++){
				if(data2[j] > data2[j+1]){
					int temp = data2[j];
					data2[j] = data2[j+1];
					data2[j+1] = temp;
				}
			}
		}
	}
}
