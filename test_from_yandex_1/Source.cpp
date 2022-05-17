#include <iostream>

/*��������� - ����� ��������� ���������� �� ��������� ����, ����� ������� ����� ��������� ��� "����� ������". 
��� ������ ������������ ����, � ���������� �������� ���������� ����� ����� ��� ��������� ����. 
������ ����������� �������� ������ ������������� ���� ������������ �������� �����*/


int isAnagram(std::string *string_1, std::string *string_2)
{
	//�������� ������ ���������� ��������
	const char * c_string_1 = new char [string_1->size()];
	const char * c_string_2 = new char [string_2->size()];
	int size_1 = string_1->size();
	int size_2 = string_2->size();

	//�������������� ���������� ������� ��������� ������ ��������� �����
	c_string_1 = string_1->c_str();
	c_string_2 = string_2->c_str();

	unsigned int counter_1 = 0;
	unsigned int counter_2 = 0;
	char saved_char = '0';

	bool is_anogramm = false;

	if (size_1 == size_2) // ������ �����, �������� ��������� "����" ��� "����"
	{
		for (int i = 0; i < size_1; i++)
		{
			for (int j = 0; j < size_2; j++)
			{
				if (c_string_1[i] == c_string_2[j]) // ���� ������ ������ ������ ����� ������� �� ������ �� ������� ���-�� ���������� �� ������
				{
					++counter_1;
					saved_char = c_string_1[i];
				}
				else//���� ������ ������ ������ �� ����� ������� �� ������ �� ������� ��� - �� ���������� � ������
					saved_char = c_string_1[i];
					if (c_string_1[j] == saved_char)
						++counter_2;
			}
			if (counter_1 == counter_2)
				is_anogramm = true;
			else
				is_anogramm = false;
			counter_1 = 0;
			counter_2 = 0;
		}
	}
	/*
	delete[] c_string_1;
	delete[] c_string_2;
	*/
    
	return is_anogramm;
}

int main()
{
	setlocale(LC_ALL, "ru");
	std::string string_1, string_2;
	std::cout << "������� ��� ������� ����� ������ > " << '\n';
	//std::string str = "12";
	//std::cout << (int)(str[0]) * 10 + (int)(str[1]);
	std::cin >> string_1 >> string_2;
	std::cout << "��� ���������: " << isAnagram(&string_1, &string_2) << '\n';

	system("PAUSE");
	return 0;
}