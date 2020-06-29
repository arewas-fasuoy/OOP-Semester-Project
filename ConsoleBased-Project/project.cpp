#include <iostream>
#include <fstream>
using namespace std;
int test;
class vehicle{
public:
	string reg_no,license_no, taxes;
	int tax_amount,total,tollTax,fine;
	virtual int calculate_tax(int type)=0;
	virtual void generate_receipt()=0;

	bool registeration(string regNo){
		ifstream myfile;
		ofstream infile;
		string R_no,L_no,tax;
		bool check = 0;
		int amount;
		infile.open("report.txt", ios::app);
		myfile.open("data.txt");
		while(!myfile.eof()){
			myfile>>R_no>>L_no>>tax>>amount;
			if(regNo==R_no){
				reg_no=R_no;
				check = 1;
			} 
		}
		if(check){
			return check;
		}
		else{
			infile<<regNo<<endl;
			infile.close();
			return 0;
		}
		
	}
	bool license(string licenseNo){
		ifstream myfile;
		string R_no,L_no,tax;
		int amount;
		bool check=0;
		myfile.open("data.txt");
		while(!myfile.eof()){
			myfile>>R_no>>L_no>>tax>>amount;;
			if(licenseNo==L_no){
				license_no=L_no;
				check=1;
				
			}
		}
		if(check){
			return check;
		}
		else{

			return 0;
		}

	}
	bool taxes_(){
		ifstream myfile;
		string R_no,L_no,tax;
		int amount;
		myfile.open("data.txt");
		while(!myfile.eof()){
			myfile>>R_no>>L_no>>tax>>amount;
			if(reg_no==R_no){
				if(tax=="yes"){
					return 1;
				} 
				else if(tax=="no"){
					tax_amount=amount;
					test = amount;
					return 0;
				}
			}

		}

	}

};
  class valid:public vehicle{
  public:
  	int calculate_tax(int type){
  		if (type==1){
  			tollTax=100;
  		}
  		else if(type==2){
  			tollTax=50;
  		}
  		total=tollTax;
  		ofstream file;
  		file.open("log.txt", ios::app);
  		file<<total<<endl;
  	}
  	void generate_receipt(){
 		cout<<"Toll Tax: Rs "<<tollTax<<endl;
 		cout<<"Other Taxes: Rs "<<0<<endl;
 		cout<<"Fine: Rs "<<0<<endl;
 		cout<<"Total: Rs "<<total<<endl;
 	}
 	
 };
 class invalid:public vehicle{
  public:
  	int fine,taxx;
  	invalid(){
  		fine=1000;
  	}
   	int calculate_tax(int type){
  		if (type==1){
  			tollTax=100;
  		}
  		else if(type==2){
  			tollTax=50;
  		}
  		total=fine+tollTax;
  		ofstream file;
  		file.open("log.txt", ios::app);
  		file<<total<<endl;
  	}
  	void generate_receipt(){
 		cout<<"Toll Tax: Rs "<<tollTax<<endl;
 		cout<<"Other Taxes: Rs "<<0<<endl;
 		cout<<"Fine: Rs "<<fine<<endl;
 		cout<<"Total: Rs "<<total<<endl;
 	}

  };


 class paid1:public valid{ //when a car is registered and have paid taxes and is valid license
 public:
 	void generate_receipt(){
 		cout<<"Toll Tax: Rs "<<tollTax<<endl;
 		cout<<"Other Taxes: Rs "<<0<<endl;
 		cout<<"Fine: Rs "<<0<<endl;
 		cout<<"Total: Rs "<<total<<endl;
 	}

 };
class paid2:public invalid{ //when a car is registered and have paid taxes but invalid license
 public:
  	void generate_receipt(){
 		cout<<"Toll Tax: Rs "<<tollTax<<endl;
 		cout<<"Other Taxes: Rs "<<0<<endl;
 		cout<<"Fine: Rs "<<fine<<endl;
 		cout<<"Total: Rs "<<total<<endl;
 	}

 };

 class non_paid1:public valid{ //when a car is registered and valid license but taxes are not paid.
  public:
 	non_paid1(){
 	}
 	int calculate_tax(int type){
 		if (type==1){
 			tollTax=100;
 		}
 		else if(type==2){
 			tollTax=50;
 		}

 		total=tollTax+test;
  		ofstream file;
  		file.open("log.txt", ios::app);
  		file<<total<<endl;
 	}
  	void generate_receipt(){
 		cout<<"Toll Tax: Rs "<<tollTax<<endl;
 		cout<<"Other Taxes: Rs "<<test<<endl;
 		cout<<"Fine: Rs "<<0<<endl;
 		cout<<"Total: Rs "<<total<<endl;
 	}
 };
 class non_paid2:public invalid{	//when a car is registered and invalid license but taxes are not paid.
  public:
 	int fine;
 	non_paid2(){
 	 	fine=1000;
 	 }
   	int calculate_tax(int type){
 	 	if (type==1){
 	 		tollTax=100;
 	 	}
 	 	else if(type==2){
 	 		tollTax=50;
 	 	}
 	 	total=fine+tollTax+test;
  		ofstream file;
  		file.open("log.txt", ios::app);
  		file<<total<<endl;
 	 }
 	   	void generate_receipt(){
 		cout<<"Toll Tax: Rs "<<tollTax<<endl;
 		cout<<"Other Taxes: Rs "<<test<<endl;
 		cout<<"Fine: Rs "<<fine<<endl;
 		cout<<"Total: Rs "<<total<<endl;
 	}

 };
 class non_registered1:public valid{
 	   	void generate_receipt(){
 	   	cout<<"Your Car is not registered and it has been reported!"<<endl;
 		cout<<"Toll Tax: Rs "<<tollTax<<endl;
 		cout<<"Other Taxes: Rs "<<0<<endl;
 		cout<<"Fine: Rs "<<0<<endl;
 		cout<<"Total: Rs "<<total<<endl;
 	}

 };
 class non_registered2:public invalid{
 	   	void generate_receipt(){
 	   	cout<<"Your Car is not registered and it has been reported!"<<endl;
 		cout<<"Toll Tax: Rs "<<tollTax<<endl;
 		cout<<"Other Taxes: Rs "<<0<<endl;
 		cout<<"Fine: Rs "<<fine<<endl;
 		cout<<"Total: Rs "<<total<<endl;
 	}
 };


int main(){
	vehicle *obj1;
	valid obj,*obj2;
	obj1=&obj;
	
	string regNumber, LNumber;
	int Type;
	char input;
	do{
		cout<<"Enter Registeration number of your car: ";
		cin>>regNumber;
		cout<<"Enter Driving License Number: ";
		cin>>LNumber;
		cout<<"Choose The Vehicle Type: "<<endl;
		cout<<"1-Heavy Vehicle"<<endl;
		cout<<"2-Light Vehicle"<<endl;
		cin>>Type;
		if(obj1->license(LNumber)){
			if(obj1->registeration(regNumber)){
				if(obj1->taxes_()){
					paid1 P;
					obj2=&P;
					obj2->calculate_tax(Type);
					obj2->generate_receipt();
				}
		 		else {
					non_paid1 P;
					obj2=&P;
					obj2->calculate_tax(Type);
					obj2->generate_receipt();
				}
			}
			else{
				non_registered1 A;
				obj2=&A;
				obj2->calculate_tax(Type);
				obj2->generate_receipt();
			}
		}
		else{
			invalid I,*b;
	  		obj1=&I;
			if(obj1->registeration(regNumber)){
				if(obj1->taxes_()){
					paid2 P;
					b=&P;
					b->calculate_tax(Type);
					b->generate_receipt();
				}
				else{
					non_paid2 P;
					b=&P;
					b->calculate_tax(Type);
					b->generate_receipt();
				}
			}
			else{
				non_registered2 A;
				b=&A;
				b->calculate_tax(Type);
				b->generate_receipt();
			}

		}
	cout<<"Do You Want to Exit y/n ?"<<endl;
	cin>>input;
	}
	while(input!='y');

	return 0;



}