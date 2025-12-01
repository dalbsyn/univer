#include<iostream>
using namespace std;

int dohod(int vklad, float proc, int srok){
	proc = proc / 100;
	int result = vklad * proc * srok;
	
	return result;
}

int main(){
	int vklad, srok;
	float proc;

	printf("Вычисление дохода по вкладу\n");

	printf("Введите величину вклада: ");
	cin >> vklad;

	printf("Введите процентную ставку: ");
	cin >> proc;

	printf("Введите срок вклада: (дней): ");
	cin >> srok;

	int result = dohod(vklad, proc, srok);

	printf("Итоговый доход по вкладу: %i", result);
}
