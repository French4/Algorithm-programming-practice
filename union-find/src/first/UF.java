package first;

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
		return id[p]; //���ص��Ƕ�Ӧ����������
	}

	public void union(int p, int q){
		int pID = find(p);
		int qID = find(q);
		
		/*���p��q�Ѿ�����ͬ�ķ���֮�оͲ���Ҫ��ȡ�κ��ж�*/
		if(pID == qID) return;
		
		//��p��������Ϊq����������
		for(int i = 0; i < id.length; i++)
			if(id[i] == pID) id[i] = qID;
		count--;//��ͨ������ȥ1
	}
	public static void main(String[] args) {
		int N = StdIn.readInt();//�õ����������
		UF uf = new UF(N);
		while(!StdIn.isEmpty()){
			int p = StdIn.readInt();
			int q = StdIn.readInt();
			if(uf.connnected(p, q))
				continue;
			uf.union(p, q);//�鲢����
			StdOut.println(p + " " + q);
		}
	}
}
