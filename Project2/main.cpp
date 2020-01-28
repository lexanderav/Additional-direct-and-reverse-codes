#include <iostream>
#include <string>

using namespace std;

string NumSystemTwo(int num);
void transfer(string bin_num, int unar);
string revers_code(string bin_num);
string add_code(string bin_num);

int main() {
	string bin_num = "";
	int num = 0;
	int unar = 0;
	cout << "Enter a number 10 system : ";
	cin >> num; 
	if (num < 0) num = abs(num);
	else unar = 1;
	cout << unar << endl;
	bin_num = NumSystemTwo(num);
	cout << "In the 2 system - " << bin_num<< endl;
	transfer(bin_num,unar);
}

string NumSystemTwo(int num)
{
	string ch = "";
	int znach = 2;
	while (num > 0) {
		ch = ch + to_string(num % 2);
		num = num / 2;
	}
	reverse(ch.begin(), ch.end());
	while (ch.length() % 8 != 0) {
		ch = "0" + ch;
	}
	return ch;
}

void transfer(string bin_num, int unar)
{
	if (unar == 1) {
		cout << "Direct code : " << bin_num << endl;
		cout << "Reverse code : " << bin_num << endl;
		cout << "Additional code : " << bin_num << endl;
	} 
	else {
		int i = 0;
		string revers_num = "";
		cout << "Direct code : " << bin_num << endl;
		revers_num = revers_code(bin_num);
		cout << "Reverse code : " << revers_num << endl;
		cout << "Additional code : " << add_code(revers_num) << endl;
	}
}

string revers_code(string bin_num) {
	for (int i = 0; i <= bin_num.length(); i++) {
		if (bin_num[i] == '0') {
			bin_num[i] = '1';
		}
		else
			bin_num[i] = '0';
	}
	return bin_num;
}

string add_code(string bin_num) {
	string add = "1";
	for (int i = bin_num.length()-1; i >= 0; i--) {
		if (i == 0) {
			bin_num[i] = '1';
		}
		else if ((bin_num[i] == '1') && (add == "1")) {
			add = "1";
			bin_num[i] = '0';
		}
		else if ((bin_num[i] == '0') && (add == "1")) {
			add = "0";
			bin_num[i] = '1';
		}
		else if ((bin_num[i] == '0') && (add == "0")) {
			add = "0";
			bin_num[i] = '0';
		}
		else if ((bin_num[i] == '1') && (add == "0")) {
			add = "0";
			bin_num[i] = '1';
		}
	}
	return bin_num;
}