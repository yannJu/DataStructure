/*
 * Lab1_1 : Basic Exercise1
 * Name : �� �� ��
 * ID : 20191644
 * Program Description : Exercising File IO & WordCount
 * Algorithm : ������ �а� split �������� �� string�� ������.(�ܾ �迭�� ���Ե�)
 *             split�� �迭�� �ܾ ������ �ƴҰ�� cnt��.
 * Variable :
 * 			File : ������ �ҷ���
 * 			BufferedReader : �ҷ��� ������ ���� - readLine : ���� �� ����
 *          split : ������ string�� �������� �и���
 */
package �ڷᱸ��.Lab;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Lab1_1_20191644_�̿��� {
	private static int cnt; //�и��� �ܾ���� ���� ���� ���� ����

	public static void main(String[] args) {
		int total = 0; //cnt���� ���� ������ ���� ���� ����
		File inFile = new File("C:\\Users\\duswn\\eclipse-workspace\\�ڷᱸ��\\src\\�ڷᱸ��", "lab1-1.dat"); //������ ����
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(inFile));
			String line;
			while ((line = br.readLine()) != null) {
				cnt = 0;
				String s = " .,*"; //split�� ������ �� ���ڵ�
				String[] words = line.split("[" + s + "]"); //������ �������� �ܾ ������ �迭�� ����
				getType(words);
				System.out.println(line + "\n    The number of words : " + (cnt));
				total += (cnt); //��ü ������ ���̿��� �ܾ���� ���� ��
			}
			System.out.println("Total Number of Words : " + total);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}finally {
			if(br != null) try {br.close();} catch (IOException e) {}
		}
	}
	
	public static String getType(String[] words) { //�ܾ��� ���� ���� ���� �Լ�
		cnt = 0;
		for(String word : words) {
			if(!word.isEmpty()) { //�ܾ ������ �ƴҰ��
				cnt += 1; //cnt�� 1�� ����
			}
		}
		return "";
	}
}
