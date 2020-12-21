/*
 * Lab1_2 : Find Min and Max numbers
 * Name : 이 연 주
 * ID : 20191644
 * Program Description : Exercising File IO & Find Min and Max numbers
 * Algorithm : 파일을 읽고 공백을 기준으로 문장을 나누어 배열에 담음.(String으로 담음)
 *             num이라는 변수에 각 수를 int로 변환하여 저장.
 *             num이 min보다 작거나 같으면 min을 num으로 지정.
 *             num이 max보다 크거나 같으면 max를 num으로 지정.
 * Variable :
 * 			File : 파일을 불러옴
 * 			BufferedReader : 불러온 파일을 읽음 - readLine : 한줄 씩 읽음
 *          Integer.parseInt : String을 int형으로 변환
 */
package 자료구조.Lab;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class Lab1_2_20191644_이연주 {
	private static int min;
	private static int minPosition;
	private static int max;
	private static int maxPosition; //min, max값과 각 자리수를 저장하는 변수
	
	public static void main(String[] args) {
		File inFile = new File("C:\\Users\\duswn\\eclipse-workspace\\자료구조\\src\\자료구조", "lab1-2.dat"); //파일을 받아옴
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(inFile));
			String line = br.readLine(); //한줄을 읽어옴
			String[] numbers = line.split(" ");
			min = Integer.parseInt(numbers[0]); 
			max = Integer.parseInt(numbers[0]); //min과 max를 배열의 첫번째 값으로 지정
			findMinMax(numbers); 
			System.out.println("Minimum number is " + min + " at position " + minPosition
					+ ",\nMaximum number is " + max + " at position " + maxPosition);
		}catch (FileNotFoundException e) {
			e.printStackTrace();
		}catch (IOException e) {
			e.printStackTrace();
		}finally {
			if(br != null) try {br.close();} catch (IOException e) {}
		} //에러처리
	}
	
	public static String findMinMax(String[] numbers){
		for (int i = 0; i < numbers.length; i++) {
			int num = Integer.parseInt(numbers[i]); //String을 int로 변환
			
			if (num >= max) {
				max = num;
				maxPosition = i + 1;
			} //num이 max보다 크면 max값으로 지정, 위치값 지정
			if (num <= min) {
				min = num;
				minPosition = i + 1;
			} //num이 min보다 작으면 min값으로 지정, 위치값 지정
		}
		return "";
	}
}
