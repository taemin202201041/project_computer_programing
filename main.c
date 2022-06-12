/*	
	학번 : 202201041 
	학과 : 컴퓨터 공학부
	이름 : 김태민


	과제 주제 : 일자별(2020/1/20  ~  2022/6/10)국내/해외 코로나 확진자 수, 사망자 확인 및 총합 확인 가능 프로그램      #코로나바이러스 감염증-19
	사용자로 부터 yes 를 입력받으면 실행시키고 , no를 입력받으면 실행 시키지않음.


*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>    
#include "covid19.h"  // 헤더파일 내부에 구조체를 이용하여 총합,국내,해외,사망자를 모두 선언함.      [평가항목 5,8] : 구조체 사용,다중 소스 파일 사용

void array(FILE* fp);//																		[평가항목 6] : 험수 사용

int main() {
	char answer[10];// 질문을 받기위한 배열 answer 선언									  [평가항목 3] : 배열 사용
	char* p_a = answer;// 사용자로 부터 받은 답변을 포인터 p_a로 받음.					  [평가항목 4] : 포인터사용
	FILE* fp;
	ACCULATE total = { 18209650,18176437,33213,24341 };
	const char* list[3] = { //																 [평가항목 6] : 포인터 활용 
	  "실행 하시겠습니까?",
	  "실행을 원하시면 yes를 입력",
	  "종료를 원하시면 no 를 입력"
	};

	printf("==========================\n");
	printf("%s\n", list[0]);
	printf("%s\n", list[1]);
	printf("%s\n", list[2]);
	printf("==========================\n");

	scanf(" %s", p_a);
	system("cls");      
	if (strcmp(p_a ,"yes")==0) {

		if ((fp = fopen("코로나바이러스감염증-19_확진환자_발생현황_220610.txt", "r")) == NULL)//           [평가항목 7] : 파일 입출력 사용
		{
			fprintf(stderr, "파일: 코로나바이러스감염증-19_확진환자_발생현황_220610 을 열 수 없습니다. \n");
			exit(1);
		}
		printf("       총합: %d|국내:%d |해외:%d |사망:%d\n\n", total.total, total.in_nation, total.out_nation, total.gone);
		array(fp); // 코로나 관련 총합 데이터를 출력.                                                         



		fclose(fp);
	}
	else {
		exit(1);
	}
	


}