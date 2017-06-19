package Utils.out;

public class print {
	public static void println(int[] data) {
		for(int i = 0; i < data.length; i++){
			System.out.print(data[i]+", ");
		}
	}
}
