/*
 * Lab1_3 : String Exercise
 * Name : �� �� ��
 * ID : 20191644
 * Program Description : (2) compare String size
 * Algorithm : string 2���� �Է¹޴´�.
 *             �� string�� ������ �Ѿ��, ���ʺ��� �ٸ� �ܾ ã�� ���Ѵ�.
 * Variable :
 * 			Scanner : �Է��� �޴´�.
 * 			charAt(index) : index�� �ش��ϴ� �κ��� char��.
 *          equal() : �ΰ��� string�� ��
 */
package �ڷᱸ��.Lab;
import java.util.Scanner;

public class Lab1_3_compare_20191644_�̿��� {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String string1 = sc.next();
		String string2 = sc.next(); //�ΰ��� string�� �Է¹޴´�.
		System.out.println("Result is \'" + compare(string1, string2) + "\'");
	}
	public static int compare(String string1, String string2) {
		int result;
		int i = 0;
		while (string1.charAt(i) == string2.charAt(i) && !string1.equals(string2)) {
			i += 1;
		} //�ΰ��� string�� ���Ͽ����� �� �ڸ����� �ش��ϴ� �ܾ ���ų� �δܾ ���� �ܾ��� ��� index ���� ���������ش�.
		if (string1.charAt(i) > string2.charAt(i)) {
			result = 1;
		} //string1�� �ܾ�ũ�Ⱑ Ŭ ��� 1 ��ȯ.
		else if (string1.charAt(i) < string2.charAt(i)) {
			result = -1;
		} //string2�� �ܾ�ũ�Ⱑ Ŭ ��� -1 ��ȯ.
		else {
			result = 0;
		} //index�� ������ �����Ͽ��� �� �ܾ ���� ��� 0 ��ȯ.
		return result;
	}
}
