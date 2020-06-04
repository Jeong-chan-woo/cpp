#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
//19011712 정찬우 <과제 #2> 2. (한글 끝말잇기 게임 코드입니다)

class WordGame
{
private:
	Player *p;

public:
	new_function(int n);
	~WordGame();
};

class Player
{
private:
	string name;

public:
	Player(string name);
};

int main()
{
	int n;
	string name;

	cout << "끝말 잇기 게임을 시작합니다." << endl;
	cout << "게임에 참가하는 인원은 몇 명입니까?" << endl;
	cin >> n;

	new_function(n);

	for (int i = 0; i < n; i++)
	{
		cout << "참가자의 이름을 입력하세요. 빈칸 없이 >>";
		cin >> name;

		Player(name);
	}

	return 0;
}

WordGame::new_function(int n)
{
	p = new Player[n];
}

WordGame::~WordGame()
{
	delete[]p;
}

Player::Player(string name)
{
	this->name = name;
}