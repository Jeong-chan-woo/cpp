#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
//19011712 ������ <���� #2> 2. (�ѱ� �����ձ� ���� �ڵ��Դϴ�)

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

	cout << "���� �ձ� ������ �����մϴ�." << endl;
	cout << "���ӿ� �����ϴ� �ο��� �� ���Դϱ�?" << endl;
	cin >> n;

	new_function(n);

	for (int i = 0; i < n; i++)
	{
		cout << "�������� �̸��� �Է��ϼ���. ��ĭ ���� >>";
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