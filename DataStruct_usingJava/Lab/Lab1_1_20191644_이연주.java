/*
 * Lab1_1 : Basic Exercise1
 * Name : 이 연 주
 * ID : 20191644
 * Program Description : Exercising File IO & WordCount
 * Algorithm : 파일을 읽고 split 기준으로 할 string을 지정함.(단어만 배열에 남게됨)
 *             split한 배열의 단어가 공백이 아닐경우 cnt함.
 * Variable :
 * 			File : 파일을 불러옴
 * 			BufferedReader : 불러온 파일을 읽음 - readLine : 한줄 씩 읽음
 *          split : 지정된 string을 기준으로 분리함
 */
package 자료구조.Lab;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Lab1_1_20191644_이연주 {
	private static int cnt; //분리된 단어들의 수를 세기 위한 변수

	public static void main(String[] args) {
		int total = 0; //cnt들을 합쳐 총합을 세기 위한 변수
		File inFile = new File("C:\\Users\\duswn\\eclipse-workspace\\자료구조\\src\\자료구조", "lab1-1.dat"); //파일을 읽음
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(inFile));
			String line;
			while ((line = br.readLine()) != null) {
				cnt = 0;
				String s = " .,*"; //split의 기준이 될 문자들
				String[] words = line.split("[" + s + "]"); //공백을 기준으로 단어를 나누어 배열에 담음
				getType(words);
				System.out.println(line + "\n    The number of words : " + (cnt));
				total += (cnt); //전체 문장의 길이에서 단어들의 수를 뺏
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
	
	public static String getType(String[] words) { //단어의 수를 세기 위한 함수
		cnt = 0;
		for(String word : words) {
			if(!word.isEmpty()) { //단어가 공백이 아닐경우
				cnt += 1; //cnt에 1씩 더함
			}
		}
		return "";
	}
}
