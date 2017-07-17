package first;

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
		return id[p]; //返回的是对应的数组内容
	}

	public void union(int p, int q){
		int pID = find(p);
		int qID = find(q);
		
		/*如果p和q已经在相同的分量之中就不需要采取任何行动*/
		if(pID == qID) return;
		
		//将p分量重名为q分量的名字
		for(int i = 0; i < id.length; i++)
			if(id[i] == pID) id[i] = qID;
		count--;//连通分量减去1
	}
	public static void main(String[] args) {
		int N = StdIn.readInt();//得到触点的数量
		UF uf = new UF(N);
		while(!StdIn.isEmpty()){
			int p = StdIn.readInt();
			int q = StdIn.readInt();
			if(uf.connnected(p, q))
				continue;
			uf.union(p, q);//归并分量
			StdOut.println(p + " " + q);
		}
	}
}
