package three;

public class WeightedQuickUnionUF {
	private int[] id; //触点索引
	private int[] sz;//各个根节点对应的分量的大小
	private int count;
	public WeightedQuickUnionUF(int N) {
		count = N;
		id = new int[N];
		for(int i = 0; i < N; i++)
			id[i] = i;
		sz = new int[N];
		for(int i = 0; i < N; i++)
			sz[i] = 1; //初始化树的节点
	}
	
	public int count(){
		return count;
	}
	
	public boolean connected(int p, int q){
		return find(p) == find(q); //判断根节点的地址是否相等
	}

	public int  find(int q) { //find相当于找到根节点的地址
		while(q != id[q]) q = id[q];
		return q;//找到根节点
	}
	
	public void union(int p, int q)
	{
		int i = find(p);
		int j = find(q);
		if(i == j) return;
		if(sz[i] < sz[j]){id[i] = j; sz[j]+=sz[i];}//将小的树链接到大的树上面
		else			{id[j] = i; sz[i] += sz[j];}
		count--;
	} 
}
