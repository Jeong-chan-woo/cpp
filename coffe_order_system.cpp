#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() //19011712 ������
{//���� �ڵ�� Ŀ�� �ֹ� �ڵ��Դϴ�.
	int n, total = 0; //n�� �� �� �ֹ��Ұ���, total�� �� �Ǹ��� �ݾ�
	string coffee; //������ �Է� ���� ���ڿ�

	cout << "���������� 2000��, �Ƹ޸�ī�� 2300��, īǪġ�� 2500���Դϴ�." << endl;

	while (total < 20000) //total�� 20000�� �ѱ�� �ٷ� while�� Ż��
	{
		cout << "�ֹ�>> ";
		cin >> coffee;
		cin >> n;

		if (coffee == "����������") //�����������̸�
		{
			cout << 2000 * n << "���Դϴ�. ���ְ� �弼��." << endl;

			total += (2000 * n); //�� ���ݿ� �����ֱ�
		}

		else if (coffee == "�Ƹ޸�ī��") //�Ƹ޸�ī���̸�
		{
			cout << 2300 * n << "���Դϴ�. ���ְ� �弼��." << endl;

			total += (2300 * n); //�� ���ݿ� �����ֱ�
		}

		else if (coffee == "īǪġ��")//īǪġ���̸�
		{
			cout << 2500 * n << "���Դϴ�. ���ְ� �弼��." << endl;

			total += (2500 * n); //�� ���ݿ� �����ֱ�
		}

		else //����������, �Ƹ޸�ī��, īǪġ�� �ܿ� �ٸ� ���� �Է��� �� Ȥ�� ��Ÿ�� ������ ��
		{
			cout << "�Է��Ͻ� Ŀ�Ǵ� ���� Ŀ���Դϴ�." << endl;
		}
	}

	cout << "���� " << total << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�. ���� ����~" << endl;

	return 0;
}