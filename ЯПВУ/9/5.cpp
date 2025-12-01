#include<iostream>
using namespace std;

void fucktorial(int num){
	int result = 1;

	for (int i = 1; i <= num; i++){
		result *= i;
		printf("\t%i!\t|\t%i\n", i, result);
	}
}

int main(){
	int num;

	printf("Введите число факториала: ");
	cin >> num;

	printf("\tТаблица факториалов\n");
	fucktorial(num);
}
