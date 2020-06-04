#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() //19011712 정찬우
{//다음 코드는 가위 바위 보 게임 만들기 코드입니다.
	string romeo, juliet;

	cout << "가위 바뷔 보 게임을 합니다. 가위, 바위, 보 중에서 입력하세요." << endl;

	cout << "로미오>>";
	cin >> romeo;

	cout << "줄리엣>>";
	cin >> juliet;

	if (romeo == juliet) //두 개의 문자열이 같다는 것은 비겼다는 것을 의미함
	{
		cout << "비겼습니다" << endl;
	}

	else if ((romeo == "가위" && juliet == "보") || (romeo == "바위" && juliet == "가위") || (romeo == "보" && juliet == "주먹"))
	{//조건문 안에 있는 조건은 로미오가 줄리엣을 이기는 조건임
		cout << "로미오가 이겼습니다" << endl;
	}

	else if ((romeo == "가위" && juliet == "바위") || (romeo == "바위" && juliet == "보") || (romeo == "보" && juliet == "가위"))
	{//조건문 안에 있는 조건은 줄리엣이 로미엣을 이기는 조건임
		cout << "줄리엣이 이겼습니다" << endl;
	}

	else //가위, 바위, 보 이외의 문자열이 입력되거나 오타가 발생했을 때 잘못된 입력이라고 출력하게 해줌
	{
		cout << "잘못된 입력입니다" << endl;
	}

	return 0;
}