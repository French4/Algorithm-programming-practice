package com.sd.MP;
/*
 * 堆有序的定义：当一颗二叉树的每个根节点大于等于其两个子节点时候，称为堆有序
 * 对于一个基于堆实现的优先队列，插入一个元素需要不超过lgN+1次比较
 * 删除一个元素不超过2lgN次比较
 * */
public class MaxPQ {
	private int[] pq;//基于堆的完全二叉树
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
	
	//插入一个元素，让其上浮到合适位置
	public void insert(int v){
		pq[++N] = v;
		swim(N);
	}

	/*
	 * 上浮操作：当某个节点变的比他的父节点更大而被打破，通过将这个节点和父节点交换到合适的位置修复
	 * */
	private void swim(int k) {
		while(k > 1 && less(k/2, k)){ //当子节点的值大于父节点的时候进行交换，知道子节点的值不大于父节点或者交换到了根节点
			exch(k/2, k); //
			k = k/2;
		}
	}
	
	public int delMax(){
		int max = pq[1]; //从根节点中得到最大的元素
		exch(1, N--);//和最后一个元素交换
		pq[N+1] = (Integer) null;//防止对象游离
		sink(1); //将根节点下放到某个位置
		return max;
	}
	
	private void sink(int k) {
		while(2*k <= N){  //有孩子节点
			int j = 2*k; //找到左孩子
			if(j < N && less(j, j+1)) j++;//有右孩子，则在左右孩子中找到比较大的那个
			if(!less(k,j)) break; //如果顶点大于子节点，则停止循环
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
