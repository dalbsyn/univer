#include<iostream>
#include<string>
using namespace std;

int glasn(char bukva){
	string glasnye = "УЕАОЭЯИЮуеаоэяию";
	int result = 0;
	for (int i = 0; i < glasnye.size(); i++){
		if (bukva == glasnye[i]){
			result = 1;
			break;
		}
	}
}
