#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() //19011712 ������
{//���� �ڵ�� ���� ���� �� ���� ����� �ڵ��Դϴ�.
	string romeo, juliet;

	cout << "���� �ٺ� �� ������ �մϴ�. ����, ����, �� �߿��� �Է��ϼ���." << endl;

	cout << "�ι̿�>>";
	cin >> romeo;

	cout << "�ٸ���>>";
	cin >> juliet;

	if (romeo == juliet) //�� ���� ���ڿ��� ���ٴ� ���� ���ٴ� ���� �ǹ���
	{
		cout << "�����ϴ�" << endl;
	}

	else if ((romeo == "����" && juliet == "��") || (romeo == "����" && juliet == "����") || (romeo == "��" && juliet == "�ָ�"))
	{//���ǹ� �ȿ� �ִ� ������ �ι̿��� �ٸ����� �̱�� ������
		cout << "�ι̿��� �̰���ϴ�" << endl;
	}

	else if ((romeo == "����" && juliet == "����") || (romeo == "����" && juliet == "��") || (romeo == "��" && juliet == "����"))
	{//���ǹ� �ȿ� �ִ� ������ �ٸ����� �ι̿��� �̱�� ������
		cout << "�ٸ����� �̰���ϴ�" << endl;
	}

	else //����, ����, �� �̿��� ���ڿ��� �Էµǰų� ��Ÿ�� �߻����� �� �߸��� �Է��̶�� ����ϰ� ����
	{
		cout << "�߸��� �Է��Դϴ�" << endl;
	}

	return 0;
}