package first;
/*
 * һ�����������������������֮�⣬���������ֶ����������Σ���д�����ҳ�������ֻ����һ�ε����֡�
 * Ҫ��ʱ�临�Ӷ��� O(n)���ռ临�Ӷ��� O(1)��
 * ��ͷ��β����һ�����飬ʣ�µ����־�������ֻ����һ�ε����Ľ����
 * ����aXORbΪ0000 1001, ֵΪ1��λ�ñ�ʾ��λ����a��b��ֵ��ͬ����������ص㣬�����ҵ�
 * ��һ��������1��λ����
 * Ȼ������ֳ������ٴν������һ������λ����1�ģ���һ���Ǹ�λ�÷�1�ġ�
 * */
public class Main {
	public static void main(String[] args) {
		 int[] data1 = {2, 4, 3, 6, 3, 2, 5, 5};
	     int[] result1 = findNumbersAppearanceOnce(data1);
	     System.out.println(result1[0] + " " + result1[1]);
	     int[] data2 = {4, 6};
	     int[] result2 = findNumbersAppearanceOnce(data2);
	     System.out.println(result2[0] + " " + result2[1]);
	     int[] data3 = {4, 6, 1, 1, 1, 1};
	     int[] result3 = findNumbersAppearanceOnce(data3);
	     System.out.println(result3[0] + " " + result3[1]);
	}

	private static int[] findNumbersAppearanceOnce(int[] data) {
		int[] result = {0, 0};
		if(data == null || data.length < 2) {
			return result;
		}
		int xor = 0;
		for(int i : data) {
			xor ^= i;
		}
		int indexOf1 = findFirstBit1(xor);
		for(int i : data) {
			if(isBit1(i, indexOf1)) {
				result[0] ^= i;
			}else {
				result[1] ^= i;
			}
		}
		return result;
	}

	private static boolean isBit1(int num, int indexBit) {
		num >>>= indexBit;
		return (num & 1) == 1;
	}

	private static int findFirstBit1(int num) {
		int index = 0;
		while((num & 1) == 0 && index < 32) {
			num >>>= 1;  //��λ��0����
			index++;
		}
		return index;
	}
}
