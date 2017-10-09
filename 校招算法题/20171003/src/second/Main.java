package second;
/*
 * 顺时针打印数组
 * */
public class Main {
	public static void main(String[] args) {
		int[][] array = {{1,2,3},
						{4,5,6},
						{7,8,9}};
		printMatrix(array);
	}

	private static void printMatrix(int[][] array) {
		if(array == null)
			return;
		int startX = 0;
		int startY = 0;
		int endX = array.length-1;
		int endY = array[0].length-1;
		
		while(startX <= endX && startY <= endY) {
			print(array, startX, startY, endX, endY);
			startX++;
			startY++;
			endX--;
			endY--;
		}
	}

	private static void print(int[][] array, int startX, int startY, int endX, int endY) {
		//只有一行时候
		if(startX == endX) {
			for(int i = startY; i <= startY; i++) {
				System.out.println(array[startX][i]);
			}
			return;
		}
		
		//只有一列的时候
		if(startY == endY) {
			for(int i = startX; i <= endX; i++) {
				System.out.println(array[i][endY]);
			}
			return;
		}
		
		//输出startx在的那一列
		for(int i = startY; i < endY; i++) {
			System.out.println(array[startX][i]);
		}
		
		//输出endY所在的那一列
		for(int i = startX; i < endX; i++) {
			System.out.println(array[i][endY]);
		}
		
		for (int i = endY; i > startY; i-- ) {
			System.out.println(array[endX][i]);
		}
		
		for (int i = endX; i > startX; i-- ) {
			System.out.println(array[i][startY]);
		}
	}
}
