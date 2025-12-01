#include<iostream>
#include<string>
using namespace std;

// костыли в виде wchar_t, wstring нужны для адекватной работы с UTF-8. 

int glasn(wchar_t bukva){
	// будет проверять только на гласные из русского языка
	wstring glasnye = L"УЕЫАОЭЯИЮЁуеыаоэяиюё";
	int result = 0;

	for (int i = 0; i < glasnye.size(); i++){
		if (bukva == glasnye[i]){
			result = 1;
			break;
		}
	}

	return result;
}

int main(){
	setlocale(LC_ALL, "");

	wchar_t bukva;

	printf("Введите букву: ");
	wcin >> bukva;

	int result = glasn(bukva);

	printf("Результат: %i", result);
}