package com.zh.SelectSort;

public class SelectSort {
	static int[] data = {9,2,7,19,100, 97, 63};
	public static void selectSort(){
		//ѡ�����򣬾��ǵ�һ��ѡ����С�ģ����ڵ�һ��λ�ã��ڶ���ѡ����С�ķ��ڵڶ���λ��
		int min = 0;
		int j = 0;
		for(int i = 0; i < data.length-1; i++){
			min = i;
			for(j = i+1;j<data.length; j++ ){
				System.out.println("j:"+j);
				if(data[j] < data[min])
					min = j;
			}
			if(min != i){
				swap(i,min,data);
			}
		}
	}
	private static void swap(int i, int min, int[] data2) {
		int temp = data2[min];
		data2[min] = data2[i];
		data2[i] = temp;
	}
	public static void main(String[] args) {
		print(data);
		selectSort();
		print(data);
	}
	private static void print(int[] data) {
		for(int i = 0; i < data.length; i++){
			System.out.print(data[i]+", ");
		}
	}
}
