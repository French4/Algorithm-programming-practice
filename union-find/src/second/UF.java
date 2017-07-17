package second;

public class UF {
	private int[] id;//分量id(以触点作为索引)
	private int count; //分量数量
	
	public UF(int N){
		count = N;
		id = new int[N];
		for(int i = 0; i < N; i++){
			id[i] = i;
		}
	}
	
	public int count(){
		return count;
	}
	public boolean connnected(int p, int q){
		return find(p) == find(q); //数组的内容相等就是连通的
	}
	private int find(int p) {
		while(p != id[p]) p = id[p];
		return p;
	}

	public void union(int p, int q){
		int pRoot = find(p);
		int qRoot = find(q);
		
		if(pRoot == qRoot) return;
		
		//否则将一个链接在一个树下面
		id[pRoot] = qRoot;
		count--;
	}
}

