package first;
/*
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次，请写程序找出这两个只出现一次的数字。
 * 要求时间复杂度是 O(n)，空间复杂度是 O(1)。
 * 从头到尾遍历一遍数组，剩下的数字就是两个只出现一次的异或的结果。
 * 假设aXORb为0000 1001, 值为1的位置表示此位置上a和b的值不同，根据这个特点，我们找到
 * 第一个数字是1的位数。
 * 然后将数组分成两类再次进行异或，一类数该位置是1的，另一类是该位置非1的。
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
			num >>>= 1;  //高位用0补上
			index++;
		}
		return index;
	}
}
