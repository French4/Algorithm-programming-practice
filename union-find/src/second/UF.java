package second;

public class UF {
	private int[] id;//����id(�Դ�����Ϊ����)
	private int count; //��������
	
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
		return find(p) == find(q); //�����������Ⱦ�����ͨ��
	}
	private int find(int p) {
		while(p != id[p]) p = id[p];
		return p;
	}

	public void union(int p, int q){
		int pRoot = find(p);
		int qRoot = find(q);
		
		if(pRoot == qRoot) return;
		
		//����һ��������һ��������
		id[pRoot] = qRoot;
		count--;
	}
}

