package three;

public class WeightedQuickUnionUF {
	private int[] id; //��������
	private int[] sz;//�������ڵ��Ӧ�ķ����Ĵ�С
	private int count;
	public WeightedQuickUnionUF(int N) {
		count = N;
		id = new int[N];
		for(int i = 0; i < N; i++)
			id[i] = i;
		sz = new int[N];
		for(int i = 0; i < N; i++)
			sz[i] = 1; //��ʼ�����Ľڵ�
	}
	
	public int count(){
		return count;
	}
	
	public boolean connected(int p, int q){
		return find(p) == find(q); //�жϸ��ڵ�ĵ�ַ�Ƿ����
	}

	public int  find(int q) { //find�൱���ҵ����ڵ�ĵ�ַ
		while(q != id[q]) q = id[q];
		return q;//�ҵ����ڵ�
	}
	
	public void union(int p, int q)
	{
		int i = find(p);
		int j = find(q);
		if(i == j) return;
		if(sz[i] < sz[j]){id[i] = j; sz[j]+=sz[i];}//��С�������ӵ����������
		else			{id[j] = i; sz[i] += sz[j];}
		count--;
	} 
}
