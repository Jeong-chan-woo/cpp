#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>  //random을 위해 추가
#include <cstdlib> //random을 위해 추가
using std::cin;
using std::cout;
using std::endl;
using std::string;

class UpAndDownGame //UpAndDownGame class
{
private:
	static int answer; //random을 돌려서 만들어 낸 답
	static int start; //힌트 줄때 "a와 b 사이에 있습니다."에서의 a
	static int end; //힌트 줄때 "a와 b 사이에 있습니다"에서의 b

public:
	static void make_answer(); //random 돌려서 answer에 대입하기
	static void answer_hint(); //"a와 b 사이에 있습니다."를 출력
	static bool check_answer(int person_answer); //player가 말한 답이 맞나 확인
};

class Person //Person class
{
private:
	string name; //player 이름

public:
	Person(string name); //생성자
	void print_name(); //누가 답을 맞출건지 출력
	void print_win(); //"~(이)가 이겼습니다!!" 출력
};

int UpAndDownGame::answer; //random 돌려서 나온 값을 여기에 대입 시킬 예정(make_answer함수 이용해서)
int UpAndDownGame::start = 0; //초기값 0으로 설정
int UpAndDownGame::end = 99; //초기값 99로 설정

int main()
{
	UpAndDownGame game; //game 객체
	Person person1("김인수"); //person1 객체
	Person person2("오은경"); //person2 객체

	game.make_answer(); //random 돌려서 나온 값을 answer에 대입하는 함수

	cout << "Up & Dwon 게임을 시작합니다." << endl; //게임 시작을 알리는 문장

	int count = 1; //count가 홀수이면 첫번째 player가 맞추고, 짝수이면 두번째 player가 맞추는 식으로 할 예정
	int person_answer; //player가 입력한 답을 여기에 저장

	while (1) //답을 맞출 때까지 무한루프
	{
		game.answer_hint(); //"a와 b사이에 있습니다."출력

		if (count % 2 != 0) //홀수면
		{
			person1.print_name(); //player1이 답을 맞추고
		}

		else //짝수면
		{
			person2.print_name();  //player2가 답을 맞추고
		}

		cin >> person_answer; //player가 말한 답을 여기에 입력

		if (game.check_answer(person_answer)) //답이 맞으면
		{
			if (count % 2 != 0) //홀수면
			{
				person1.print_win(); //player1이 이긴것임
			}

			else //짝수면
			{
				person2.print_win(); //player2가 이긴것임
			}

			break; //답을 맞췃으니무한루프 빠져나오기
		}

		count++; //count를 늘려서 짝수인지 홀수인지를 통해 player1이 맞출건지 player2가 맞출건지 결정
	}
}

void UpAndDownGame::make_answer() //random 돌려서 answer에 대입하기
{
	srand((unsigned)time(0)); //랜덤한 값을 뽑는 과정
	int n = rand(); //랜덤한 값을 뽑는 과정
	n = n % 100; //랜덤한 값을 뽑는 과정

	answer = n; //랜덤한 값을 answer에 대입
}

void UpAndDownGame::answer_hint() //"a와 b 사이에 있습니다."를 출력
{
	cout << "답은 " << start << "과 " << end << "사이에 있습니다." << endl;
}

bool UpAndDownGame::check_answer(int person_answer) //player가 말한 답이 맞나 확인
{
	if (answer == person_answer) //답이 맞으면
	{
		return true; //true 반환
	}

	else if (answer > person_answer) //player가 제시한 답이 answer보다 작으면
	{
		start = person_answer; //"a와 b 사이에 있습니다."에서 a에 player가 제시한 답을 대입

		return false; //false 반환
	}

	else //player가 제시한 답이 answer보다 크면
	{
		end = person_answer; //"a와 b 사이에 있습니다."에서 b에 player가 제시한 답을 대입

		return false; //false 반환
	}
}

Person::Person(string name) //생성자
{
	this->name = name; //이름 대입
}

void Person::print_name() //누가 답을 맞출건지 출력
{
	cout << name << ">>"; //누가 답을 맞출건지 출력
}

void Person::print_win() //"~(이)가 이겼습니다!!" 출력
{
	cout << name << "이(가) 이겼습니다!!" << endl; //"~(이)가 이겼습니다!!" 출력
}