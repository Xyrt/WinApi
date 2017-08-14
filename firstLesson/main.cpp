#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <tchar.h>


//int readLetters(int userValue)
//{
//	std::ifstream lopatin("lopatin.txt");
//	std::ofstream result("result.txt");
//	if (!lopatin.is_open())
//	{
//		return 1;
//	}
//	std::string word;
//	std::string vowels("еыуаоэяиюё");
//	while (std::getline(lopatin, word))
//	{
//		if (word.size() != userValue){
//			continue;
//		}
//		else
//		{
//			result << word << std::endl;
//		}
//	}
//}

int main()
{
	setlocale(LC_ALL, "rus");
	/*int userValue;
	std::cout << "How many letters you want?" << std::endl;
	std::cin >> userValue;
	
	readLetters(userValue);

	return 0;*/

	//wchar_t a;
	//std::wstring str = L"abacaba";
	//std::wcout << str;
	//TCHAR* str =_TEXT("dillan");

	char str1[] = "ПрямоКакПрограммист";
	size_t len = mbstowcs(NULL, str1, 0) + 1;
	wchar_t* str2 = new wchar_t[len];
	int count = mbstowcs(str2, str1, len);
	std::wcout << str2 << std::endl;

	len = wcstombs(NULL, str2, 0) + 1;
	char* str3 = new char[len];
	count = wcstombs(str3, str2, len);
	std::cout << str3 << std::endl;

	return 0;
}
