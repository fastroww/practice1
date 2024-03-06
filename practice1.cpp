#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};
struct Record
{
	char transportType[12];
	char route[5];
	double lengthRoute;
	char timeMin[5];
	struct Date date;
};
void myCentr(string s, int wLine) {
	int w = s.length();
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	//if ((w % 2) == 1){
		//cout.width(delta+1); cout << " ";
	//}
	//else
	//{
		//cout.width(delta); cout << " ";
	//}
}
void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}
void printWhithZero(int num, int width) {
	if (num > 999 and num < 10000) {
		cout.width(width + 1);
		cout << right << "00" << num;
	}
	if (num > 9999 and num < 100000) {
		cout.width(width);
		cout << right << "0" << num;
	}
}
void Draw(struct Record* records) {
	int width = 78 + 16;
	cout << endl; cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width); cout << left << "Сельскохозяйственные культуры"; cout << " | " << endl;
		cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "| Наименование ";
	cout << left << "| Тип  ";
	cout << left << "| Посевная площадь (га)";
	cout << left << "| Урожайность (ц/га)";
	cout << left << " |    Дата начала посевной    |" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|"; cout.width(14); cout << left << records[i].transportType;
		cout << left << "|"; cout.width(6); cout << left << records[i].route;
		cout.precision(3);
		cout << left << "| "; cout << left << fixed <<records[i].lengthRoute;
		cout.fill(' '); cout.width(16); cout << left << " ";
		cout << left << "|"; cout.width(20); cout << left << records[i].timeMin;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 30);
		cout << "|" << endl;
	}
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width); cout << left << "|Примечание: З - зерновые, Б - бобовые"; cout << " | " << endl;
		cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct Record records[10];
	records[0] = { "Соя", "Б", 0.13000, "45", {03,04,2022} };
	records[1] = { "Чумиза", "З", 0.8000, "17", {03,04,2022}};
	records[2] = { "Рис", "З", 0.25650, "24", {04,03,2022} };
	Draw(records);
}