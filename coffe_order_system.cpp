#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() //19011712 정찬우
{//다음 코드는 커피 주문 코드입니다.
	int n, total = 0; //n은 몇 개 주문할건지, total은 총 판매한 금액
	string coffee; //고객에게 입력 받을 문자열

	cout << "에소프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl;

	while (total < 20000) //total이 20000을 넘기면 바로 while문 탈출
	{
		cout << "주문>> ";
		cin >> coffee;
		cin >> n;

		if (coffee == "에소프레소") //에소프레소이면
		{
			cout << 2000 * n << "원입니다. 맛있게 드세요." << endl;

			total += (2000 * n); //총 가격에 더해주기
		}

		else if (coffee == "아메리카노") //아메리카노이면
		{
			cout << 2300 * n << "원입니다. 맛있게 드세요." << endl;

			total += (2300 * n); //총 가격에 더해주기
		}

		else if (coffee == "카푸치노")//카푸치노이면
		{
			cout << 2500 * n << "원입니다. 맛있게 드세요." << endl;

			total += (2500 * n); //총 가격에 더해주기
		}

		else //에소프레소, 아메리카노, 카푸치노 외에 다른 것을 입력할 때 혹은 오타를 내었을 때
		{
			cout << "입력하신 커피는 없는 커피입니다." << endl;
		}
	}

	cout << "오늘 " << total << "원을 판매하여 카페를 닫습니다. 내일 봐요~" << endl;

	return 0;
}