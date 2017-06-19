package com.zh.QuickSort;

import Utils.out.print;

public class quickSort {
	static int data[] = {1,2,3,4,5,5,6,4,1,3};//Ҫ��������
	public static void main(String[] args) {
		quickSort(data, 0, data.length-1);
		print.println(data);
	}
	private static void quickSort(int[] data2, int low, int hi) {
		if(low >= hi)
			return; //������ɵı�־������һ�����ֲ���Ҫ����
		int j = portion(data2, low, hi);//�ָ�����
		quickSort(data2, low, j-1);//�����߱�
		quickSort(data2, j+1, hi);//�����ұ�
	}
	private static int portion(int[] data2, int low, int hi) {
		int temp = data2[low]; //������з�Ԫ��
		int i = low;
		int j = hi+1;//(low, hi+1)���Ǵ������Ԫ��
		while(true){
			while(data2[++i]<temp){
				if(i >= hi)
					break;
			}//������ҵ���һ����temp���Ԫ��
			while(data2[--j]>temp){
				if(j <= low)
					break;
			}
			if(i >= j)
				break;
			each(data2, i, j); //����
		}
		each(data2, low, j); //����
		return j;
	}
	public static void each(int[] data2, int i, int j) {
		int temp = data2[i];
		data2[i] = data2[j];
		data2[j] = temp;
	}
}
