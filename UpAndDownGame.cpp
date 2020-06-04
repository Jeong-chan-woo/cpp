#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>  //random�� ���� �߰�
#include <cstdlib> //random�� ���� �߰�
using std::cin;
using std::cout;
using std::endl;
using std::string;

class UpAndDownGame //UpAndDownGame class
{
private:
	static int answer; //random�� ������ ����� �� ��
	static int start; //��Ʈ �ٶ� "a�� b ���̿� �ֽ��ϴ�."������ a
	static int end; //��Ʈ �ٶ� "a�� b ���̿� �ֽ��ϴ�"������ b

public:
	static void make_answer(); //random ������ answer�� �����ϱ�
	static void answer_hint(); //"a�� b ���̿� �ֽ��ϴ�."�� ���
	static bool check_answer(int person_answer); //player�� ���� ���� �³� Ȯ��
};

class Person //Person class
{
private:
	string name; //player �̸�

public:
	Person(string name); //������
	void print_name(); //���� ���� ������� ���
	void print_win(); //"~(��)�� �̰���ϴ�!!" ���
};

int UpAndDownGame::answer; //random ������ ���� ���� ���⿡ ���� ��ų ����(make_answer�Լ� �̿��ؼ�)
int UpAndDownGame::start = 0; //�ʱⰪ 0���� ����
int UpAndDownGame::end = 99; //�ʱⰪ 99�� ����

int main()
{
	UpAndDownGame game; //game ��ü
	Person person1("���μ�"); //person1 ��ü
	Person person2("������"); //person2 ��ü

	game.make_answer(); //random ������ ���� ���� answer�� �����ϴ� �Լ�

	cout << "Up & Dwon ������ �����մϴ�." << endl; //���� ������ �˸��� ����

	int count = 1; //count�� Ȧ���̸� ù��° player�� ���߰�, ¦���̸� �ι�° player�� ���ߴ� ������ �� ����
	int person_answer; //player�� �Է��� ���� ���⿡ ����

	while (1) //���� ���� ������ ���ѷ���
	{
		game.answer_hint(); //"a�� b���̿� �ֽ��ϴ�."���

		if (count % 2 != 0) //Ȧ����
		{
			person1.print_name(); //player1�� ���� ���߰�
		}

		else //¦����
		{
			person2.print_name();  //player2�� ���� ���߰�
		}

		cin >> person_answer; //player�� ���� ���� ���⿡ �Է�

		if (game.check_answer(person_answer)) //���� ������
		{
			if (count % 2 != 0) //Ȧ����
			{
				person1.print_win(); //player1�� �̱����
			}

			else //¦����
			{
				person2.print_win(); //player2�� �̱����
			}

			break; //���� �­����Ϲ��ѷ��� ����������
		}

		count++; //count�� �÷��� ¦������ Ȧ�������� ���� player1�� ������� player2�� ������� ����
	}
}

void UpAndDownGame::make_answer() //random ������ answer�� �����ϱ�
{
	srand((unsigned)time(0)); //������ ���� �̴� ����
	int n = rand(); //������ ���� �̴� ����
	n = n % 100; //������ ���� �̴� ����

	answer = n; //������ ���� answer�� ����
}

void UpAndDownGame::answer_hint() //"a�� b ���̿� �ֽ��ϴ�."�� ���
{
	cout << "���� " << start << "�� " << end << "���̿� �ֽ��ϴ�." << endl;
}

bool UpAndDownGame::check_answer(int person_answer) //player�� ���� ���� �³� Ȯ��
{
	if (answer == person_answer) //���� ������
	{
		return true; //true ��ȯ
	}

	else if (answer > person_answer) //player�� ������ ���� answer���� ������
	{
		start = person_answer; //"a�� b ���̿� �ֽ��ϴ�."���� a�� player�� ������ ���� ����

		return false; //false ��ȯ
	}

	else //player�� ������ ���� answer���� ũ��
	{
		end = person_answer; //"a�� b ���̿� �ֽ��ϴ�."���� b�� player�� ������ ���� ����

		return false; //false ��ȯ
	}
}

Person::Person(string name) //������
{
	this->name = name; //�̸� ����
}

void Person::print_name() //���� ���� ������� ���
{
	cout << name << ">>"; //���� ���� ������� ���
}

void Person::print_win() //"~(��)�� �̰���ϴ�!!" ���
{
	cout << name << "��(��) �̰���ϴ�!!" << endl; //"~(��)�� �̰���ϴ�!!" ���
}