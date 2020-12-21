/*
 * Lab1_2 : Find Min and Max numbers
 * Name : �� �� ��
 * ID : 20191644
 * Program Description : Exercising File IO & Find Min and Max numbers
 * Algorithm : ������ �а� ������ �������� ������ ������ �迭�� ����.(String���� ����)
 *             num�̶�� ������ �� ���� int�� ��ȯ�Ͽ� ����.
 *             num�� min���� �۰ų� ������ min�� num���� ����.
 *             num�� max���� ũ�ų� ������ max�� num���� ����.
 * Variable :
 * 			File : ������ �ҷ���
 * 			BufferedReader : �ҷ��� ������ ���� - readLine : ���� �� ����
 *          Integer.parseInt : String�� int������ ��ȯ
 */
package �ڷᱸ��.Lab;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class Lab1_2_20191644_�̿��� {
	private static int min;
	private static int minPosition;
	private static int max;
	private static int maxPosition; //min, max���� �� �ڸ����� �����ϴ� ����
	
	public static void main(String[] args) {
		File inFile = new File("C:\\Users\\duswn\\eclipse-workspace\\�ڷᱸ��\\src\\�ڷᱸ��", "lab1-2.dat"); //������ �޾ƿ�
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(inFile));
			String line = br.readLine(); //������ �о��
			String[] numbers = line.split(" ");
			min = Integer.parseInt(numbers[0]); 
			max = Integer.parseInt(numbers[0]); //min�� max�� �迭�� ù��° ������ ����
			findMinMax(numbers); 
			System.out.println("Minimum number is " + min + " at position " + minPosition
					+ ",\nMaximum number is " + max + " at position " + maxPosition);
		}catch (FileNotFoundException e) {
			e.printStackTrace();
		}catch (IOException e) {
			e.printStackTrace();
		}finally {
			if(br != null) try {br.close();} catch (IOException e) {}
		} //����ó��
	}
	
	public static String findMinMax(String[] numbers){
		for (int i = 0; i < numbers.length; i++) {
			int num = Integer.parseInt(numbers[i]); //String�� int�� ��ȯ
			
			if (num >= max) {
				max = num;
				maxPosition = i + 1;
			} //num�� max���� ũ�� max������ ����, ��ġ�� ����
			if (num <= min) {
				min = num;
				minPosition = i + 1;
			} //num�� min���� ������ min������ ����, ��ġ�� ����
		}
		return "";
	}
}
