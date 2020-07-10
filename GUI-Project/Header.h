#pragma once
#ifndef HEADER
#define HEADER
#include <iostream>
#include<string>
#include <fstream>
using namespace std;

//int test;
class vehicle {
public:
	int test;
	string reg_no, license_no, taxes;
	int tax_amount, total, tollTax, fine;
	virtual int calculate_tax(string type) = 0;
	virtual int get_toll_tax() = 0;
	virtual int get_fine() = 0;
	virtual int get_tax() = 0;
	virtual string get_statement() = 0;

	bool registeration(string regNo) {
		ifstream myfile;
		ofstream infile;
		string R_no, L_no, tax;
		bool check = 0;
		int amount;
		infile.open("report.txt", ios::app);
		myfile.open("data.txt");
		while (!myfile.eof()) {
			myfile >> R_no >> L_no >> tax >> amount;
			if (regNo == R_no) {
				reg_no = R_no;
				check = 1;
			}
		}
		if (check) {
			return check;
		}
		else {
			infile << regNo << endl;
			infile.close();
			return 0;
		}

	}
	bool license(string licenseNo) {
		ifstream myfile;
		string R_no, L_no, tax;
		int amount;
		bool check = 0;
		myfile.open("data.txt");
		while (!myfile.eof()) {
			myfile >> R_no >> L_no >> tax >> amount;;
			if (licenseNo == L_no) {
				license_no = L_no;
				check = 1;

			}
		}
		if (check) {
			return check;
		}
		else {

			return 0;
		}

	}
	bool taxes_() {
		ifstream myfile;
		string R_no, L_no, tax;
		int amount;
		myfile.open("data.txt");
		while (!myfile.eof()) {
			myfile >> R_no >> L_no >> tax >> amount;
			if (reg_no == R_no) {
				if (tax == "yes") {
					return 1;
				}
				else if (tax == "no") {
					tax_amount = amount;
					test = amount;
					return 0;
				}
			}

		}

	}

};
class valid :public vehicle {
public:
	int calculate_tax(string type) {
		if (type == "heavy") {
			tollTax = 100;
		}
		else if (type == "light") {
			tollTax = 50;
		}
		total = tollTax;
		return total;
	}
	int get_toll_tax() {
		return  tollTax;
	}
	int get_fine() {
		return 0;
	}
	int get_tax() {
		return 0;
	}
	string get_statement() {
		return "Dear User! You have no extra taxes!";
	}

};
class invalid :public vehicle {
public:
	int fine, taxx;
	invalid() {
		fine = 1000;
	}
	int calculate_tax(string type) {
		if (type == "heavy") {
			tollTax = 100;
		}
		else if (type == "light") {
			tollTax = 50;
		}
		total = fine + tollTax;
		return total;

	}
	int get_toll_tax() {
		return  tollTax;

	}
	int get_fine() {
		return fine;
	}
	int get_tax() {
		return 0;
	}
	string get_statement() {
		return "Dear User! Your lisence is invalid and you have been fined!";
	}

};


/*class paid1 :public valid { //when a car is registered and have paid taxes and is valid license

};
class paid2 :public invalid { //when a car is registered and have paid taxes but invalid license

};*/

class non_paid1 :public valid { //when a car is registered and valid license but taxes are not paid.
public:
	non_paid1() {
	}
	int calculate_tax(string type) {
		if (type == "heavy") {
			tollTax = 100;
		}
		else if (type == "light") {
			tollTax = 50;
		}

		total = tollTax + tax_amount;
		return total;
	}
	int get_tax() {
		return test;
	}
	string get_taxes() {
		return "Dear user! your taxes are not paid!";
	}
};
class non_paid2 :public invalid {	//when a car is registered and invalid license but taxes are not paid.
public:
	int fine;
	non_paid2() {
		fine = 1000;
	}
	int calculate_tax(string type) {
		if (type == "heavy") {
			tollTax = 100;
		}
		else if (type == "light") {
			tollTax = 50;
		}
		total = fine + tollTax + test;
		return total;
	}

	int get_tax() {
		return test;
	}
	string get_statement() {
		return "Dear User! Your license is Invalid and your Taxes are non paid!";
	}

};
class non_registered1 :public valid {
	string get_statement() {
		return  "Your Car is not registered and it has been reported!";
	}

};
class non_registered2 :public invalid {
	string get_statement() {
		return "Your License is Invalid and Car is not registered.It has been reported!";
	}
};
/*class temp {
public:
	string abc() {
		ifstream myfile;
		string a;
		myfile.open("report.txt");
		while (!myfile.eof()) {
			myfile >> a;
		}
		return a;
	}
};*/

#endif
