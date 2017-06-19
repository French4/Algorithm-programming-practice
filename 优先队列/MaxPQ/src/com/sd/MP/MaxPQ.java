package com.sd.MP;
/*
 * ������Ķ��壺��һ�Ŷ�������ÿ�����ڵ���ڵ����������ӽڵ�ʱ�򣬳�Ϊ������
 * ����һ�����ڶ�ʵ�ֵ����ȶ��У�����һ��Ԫ����Ҫ������lgN+1�αȽ�
 * ɾ��һ��Ԫ�ز�����2lgN�αȽ�
 * */
public class MaxPQ {
	private int[] pq;//���ڶѵ���ȫ������
	private int N=0;
	
	public MaxPQ(int maxN){
		pq = new int[maxN];
	}
	
	public boolean isEmpty(){
		return N==0;
	}
	public int size(){
		return N;
	}
	
	//����һ��Ԫ�أ������ϸ�������λ��
	public void insert(int v){
		pq[++N] = v;
		swim(N);
	}

	/*
	 * �ϸ���������ĳ���ڵ��ı����ĸ��ڵ����������ƣ�ͨ��������ڵ�͸��ڵ㽻�������ʵ�λ���޸�
	 * */
	private void swim(int k) {
		while(k > 1 && less(k/2, k)){ //���ӽڵ��ֵ���ڸ��ڵ��ʱ����н�����֪���ӽڵ��ֵ�����ڸ��ڵ���߽������˸��ڵ�
			exch(k/2, k); //
			k = k/2;
		}
	}
	
	public int delMax(){
		int max = pq[1]; //�Ӹ��ڵ��еõ�����Ԫ��
		exch(1, N--);//�����һ��Ԫ�ؽ���
		pq[N+1] = (Integer) null;//��ֹ��������
		sink(1); //�����ڵ��·ŵ�ĳ��λ��
		return max;
	}
	
	private void sink(int k) {
		while(2*k <= N){  //�к��ӽڵ�
			int j = 2*k; //�ҵ�����
			if(j < N && less(j, j+1)) j++;//���Һ��ӣ��������Һ������ҵ��Ƚϴ���Ǹ�
			if(!less(k,j)) break; //�����������ӽڵ㣬��ֹͣѭ��
			exch(k,j); //
			k = j;
		}
	}

	private boolean less(int i, int k) {
		if(i < k)
			return true;
		return false;
	}

	private void exch(int i, int k) {
		int temp = pq[i];
		pq[i] = pq[k];
		pq[k] = temp;
	}
}
