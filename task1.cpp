#include <iostream>
#include <iomanip>
using namespace std;
void interface() {
	cout << "Лабораторная работа №1;" << endl;
	cout << "Шалиманова Ангелина"<<endl;
}
int bitwiseСonjunction(int a,int b) {//функция для поразрядной конъюнкции
	return a & b;
}
int bitwiseDisjunction(int a, int b) {//функция для поразрядной дизъюнкции
	return a | b;
}
int multiplication(int a, int b) {//функция для побитового сдвига влево
	return a << b;
}
int division(int a, int b) {//функция для побитового сдвига вправо
	return a >> b;
}
void coutp(unsigned int x)////функция для вывода в двоичном виде числа
{
	int n = sizeof(int) * 8;
	unsigned  maska = (1 << (n - 1));

	for (int i = 1; i <= n; i++)
	{
		cout << ((x & maska) >> (n - i));
		maska = maska >> 1;
	}
	cout << setw(3) << " ";
}

int main()
{
	
	cout << setiosflags(ios::left);
	setlocale(LC_ALL, "Russian");
	interface();
	long long int mask1 = 0xf0000000;//0x412;//1.1
	long long int c1 = 0x90001008;//
	long long int c2 = 0x1f;
	//установить в 1 старшие 4 разряда

	cout << "Task 1: установить заданные в задании биты исходного значения переменной в значение 1(1 старшие 4 разряда);" <<endl<< endl;
	cout << setw(10) <<"Hex: " << setw(35) <<hex<<c1 << c2 << endl;
	cout << setw(10) << "Result: " << setw(35) << bitwiseDisjunction(c1, mask1) << bitwiseDisjunction(c2, mask1) << endl;
	cout << setw(10) << "Bin: "; coutp(c1); coutp(c2); cout << endl;
	cout << setw(10) << "Result: "; coutp(bitwiseDisjunction(c1, mask1)); coutp(bitwiseDisjunction(c2, mask1));cout<< endl;
	cout << setw(10) << "Mask1: "; coutp(mask1); coutp(mask1); cout<< endl << endl;
	
	//установить в 0 9,11,3 разряды FFFF F5F7
	long long int mask2 = 0xfffff5f7;

	cout << "Task 2: установить заданные в задании биты исходного значения переменной в значение 0(9,11,3 разряды)" << endl << endl;
	cout << setw(10) << "Hex: " << setw(35) << hex << c1 << c2 << endl;
	cout << setw(10) << "Result: " << setw(35) << bitwiseСonjunction(c1,mask2) << bitwiseСonjunction(c2, mask2) << endl;
	cout << setw(10) << "Bin: "; coutp(c1); coutp(c2); cout << endl;
	cout << setw(10) << "Result: "; coutp(bitwiseСonjunction(c1, mask2)); coutp(bitwiseСonjunction(c2, mask2)); cout << endl;
	cout << setw(10) << "Mask1: "; coutp(mask2); coutp(mask2); cout << endl << endl;
	
	//512 умножить и поделить
	long long int c3 = 0x400;


	cout << "Task 3 and 4: умножить и поделить на 512" << endl<<endl;
	cout << setw(10) << "Hex: " << setw(35) <<hex<<c3<<c3 << endl;
	cout << setw(10) << "Result: " << setw(35)<<hex << multiplication(c3,9) << division(c3,9) << endl;
	cout << setw(10) << "Bin: "; coutp(c3); coutp(c3);cout << endl;
	cout << setw(10) << "Result: "; coutp(multiplication(c3, 9)); coutp(division(c3, 9)); cout << endl << endl;


	
	//установить n бит в 0
	cout << "Task 5: установить n бит в 0" << endl << endl;
	long long int mask3 = 0x01;
	long long int c6 = 0x0;
	c6 = ~c6;
	cout << "Введите какой бит надо обнулить:";
	unsigned int x;
	cin>>x;
	mask3 = mask3 << x;
	mask3 = ~mask3;
	cout << setw(10) << "Hex: " << setw(10) <<hex<< c6 << endl;
	cout << setw(10) << "Result: " << setw(10) << bitwiseСonjunction(c6, mask3) << endl;
	cout << setw(10) << "Maska: "; coutp(mask3); cout<< endl;
	cout << setw(10) << "Result: "; coutp(bitwiseСonjunction(c6,mask3)); cout<< endl;

}
