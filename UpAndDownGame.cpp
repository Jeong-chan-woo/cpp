#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>  //randomÀ» À§ÇØ Ãß°¡
#include <cstdlib> //randomÀ» À§ÇØ Ãß°¡
using std::cin;
using std::cout;
using std::endl;
using std::string;

class UpAndDownGame //UpAndDownGame class
{
private:
	static int answer; //randomÀ» µ¹·Á¼­ ¸¸µé¾î ³½ ´ä
	static int start; //ÈùÆ® ÁÙ¶§ "a¿Í b »çÀÌ¿¡ ÀÖ½À´Ï´Ù."¿¡¼­ÀÇ a
	static int end; //ÈùÆ® ÁÙ¶§ "a¿Í b »çÀÌ¿¡ ÀÖ½À´Ï´Ù"¿¡¼­ÀÇ b

public:
	static void make_answer(); //random µ¹·Á¼­ answer¿¡ ´ëÀÔÇÏ±â
	static void answer_hint(); //"a¿Í b »çÀÌ¿¡ ÀÖ½À´Ï´Ù."¸¦ Ãâ·Â
	static bool check_answer(int person_answer); //player°¡ ¸»ÇÑ ´äÀÌ ¸Â³ª È®ÀÎ
};

class Person //Person class
{
private:
	string name; //player ÀÌ¸§

public:
	Person(string name); //»ı¼ºÀÚ
	void print_name(); //´©°¡ ´äÀ» ¸ÂÃâ°ÇÁö Ãâ·Â
	void print_win(); //"~(ÀÌ)°¡ ÀÌ°å½À´Ï´Ù!!" Ãâ·Â
};

int UpAndDownGame::answer; //random µ¹·Á¼­ ³ª¿Â °ªÀ» ¿©±â¿¡ ´ëÀÔ ½ÃÅ³ ¿¹Á¤(make_answerÇÔ¼ö ÀÌ¿ëÇØ¼­)
int UpAndDownGame::start = 0; //ÃÊ±â°ª 0À¸·Î ¼³Á¤
int UpAndDownGame::end = 99; //ÃÊ±â°ª 99·Î ¼³Á¤

int main()
{
	UpAndDownGame game; //game °´Ã¼
	Person person1("±èÀÎ¼ö"); //person1 °´Ã¼
	Person person2("¿ÀÀº°æ"); //person2 °´Ã¼

	game.make_answer(); //random µ¹·Á¼­ ³ª¿Â °ªÀ» answer¿¡ ´ëÀÔÇÏ´Â ÇÔ¼ö

	cout << "Up & Dwon °ÔÀÓÀ» ½ÃÀÛÇÕ´Ï´Ù." << endl; //°ÔÀÓ ½ÃÀÛÀ» ¾Ë¸®´Â ¹®Àå

	int count = 1; //count°¡ È¦¼öÀÌ¸é Ã¹¹øÂ° player°¡ ¸ÂÃß°í, Â¦¼öÀÌ¸é µÎ¹øÂ° player°¡ ¸ÂÃß´Â ½ÄÀ¸·Î ÇÒ ¿¹Á¤
	int person_answer; //player°¡ ÀÔ·ÂÇÑ ´äÀ» ¿©±â¿¡ ÀúÀå

	while (1) //´äÀ» ¸ÂÃâ ¶§±îÁö ¹«ÇÑ·çÇÁ
	{
		game.answer_hint(); //"a¿Í b»çÀÌ¿¡ ÀÖ½À´Ï´Ù."Ãâ·Â

		if (count % 2 != 0) //È¦¼ö¸é
		{
			person1.print_name(); //player1ÀÌ ´äÀ» ¸ÂÃß°í
		}

		else //Â¦¼ö¸é
		{
			person2.print_name();  //player2°¡ ´äÀ» ¸ÂÃß°í
		}

		cin >> person_answer; //player°¡ ¸»ÇÑ ´äÀ» ¿©±â¿¡ ÀÔ·Â

		if (game.check_answer(person_answer)) //´äÀÌ ¸ÂÀ¸¸é
		{
			if (count % 2 != 0) //È¦¼ö¸é
			{
				person1.print_win(); //player1ÀÌ ÀÌ±ä°ÍÀÓ
			}

			else //Â¦¼ö¸é
			{
				person2.print_win(); //player2°¡ ÀÌ±ä°ÍÀÓ
			}

			break; //´äÀ» ¸Â­ŸÀ¸´Ï¹«ÇÑ·çÇÁ ºüÁ®³ª¿À±â
		}

		count++; //count¸¦ ´Ã·Á¼­ Â¦¼öÀÎÁö È¦¼öÀÎÁö¸¦ ÅëÇØ player1ÀÌ ¸ÂÃâ°ÇÁö player2°¡ ¸ÂÃâ°ÇÁö °áÁ¤
	}
}

void UpAndDownGame::make_answer() //random µ¹·Á¼­ answer¿¡ ´ëÀÔÇÏ±â
{
	srand((unsigned)time(0)); //·£´ıÇÑ °ªÀ» »Ì´Â °úÁ¤
	int n = rand(); //·£´ıÇÑ °ªÀ» »Ì´Â °úÁ¤
	n = n % 100; //·£´ıÇÑ °ªÀ» »Ì´Â °úÁ¤

	answer = n; //·£´ıÇÑ °ªÀ» answer¿¡ ´ëÀÔ
}

void UpAndDownGame::answer_hint() //"a¿Í b »çÀÌ¿¡ ÀÖ½À´Ï´Ù."¸¦ Ãâ·Â
{
	cout << "´äÀº " << start << "°ú " << end << "»çÀÌ¿¡ ÀÖ½À´Ï´Ù." << endl;
}

bool UpAndDownGame::check_answer(int person_answer) //player°¡ ¸»ÇÑ ´äÀÌ ¸Â³ª È®ÀÎ
{
	if (answer == person_answer) //´äÀÌ ¸ÂÀ¸¸é
	{
		return true; //true ¹İÈ¯
	}

	else if (answer > person_answer) //player°¡ Á¦½ÃÇÑ ´äÀÌ answerº¸´Ù ÀÛÀ¸¸é
	{
		start = person_answer; //"a¿Í b »çÀÌ¿¡ ÀÖ½À´Ï´Ù."¿¡¼­ a¿¡ player°¡ Á¦½ÃÇÑ ´äÀ» ´ëÀÔ

		return false; //false ¹İÈ¯
	}

	else //player°¡ Á¦½ÃÇÑ ´äÀÌ answerº¸´Ù Å©¸é
	{
		end = person_answer; //"a¿Í b »çÀÌ¿¡ ÀÖ½À´Ï´Ù."¿¡¼­ b¿¡ player°¡ Á¦½ÃÇÑ ´äÀ» ´ëÀÔ

		return false; //false ¹İÈ¯
	}
}

Person::Person(string name) //»ı¼ºÀÚ
{
	this->name = name; //ÀÌ¸§ ´ëÀÔ
}

void Person::print_name() //´©°¡ ´äÀ» ¸ÂÃâ°ÇÁö Ãâ·Â
{
	cout << name << ">>"; //´©°¡ ´äÀ» ¸ÂÃâ°ÇÁö Ãâ·Â
}

void Person::print_win() //"~(ÀÌ)°¡ ÀÌ°å½À´Ï´Ù!!" Ãâ·Â
{
	cout << name << "ÀÌ(°¡) ÀÌ°å½À´Ï´Ù!!" << endl; //"~(ÀÌ)°¡ ÀÌ°å½À´Ï´Ù!!" Ãâ·Â
}