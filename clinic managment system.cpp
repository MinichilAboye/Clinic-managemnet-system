//CLINICAL MANAGEMENT SYSTEM BY MINICHIL ABOYE
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
class student
{
	int id;
	char name[50]; 
	int age;
	char dep[50];
	char past_dis[50];
	char current_symp[50];
	char diagnosis[50];
	char lab_report[50]; 
	char blood_type[2];
	char prescription[50];
	public:
		void getdata();
		void showdata() const;
		int retrollno() const;	
};

void student::getdata()
{
cout<<"\nEnter the ID number of student\n";
cin>>id;
cout<<"\n\nEnter the name of student\n";
cin.ignore( );
cin.getline(name,50);
cout<<"\n\nEnter the student age\n";
cin>>age;
cout<<"\n\nEnter the student departement \n";
cin.ignore( );
cin.getline(dep,50);
cout<<"\n\nEnter the student past disease\n";
//cin.ignore( );
cin.getline(past_dis,50);
cout<<"\n\nEnter the student current symptoms\n";
//cin.ignore( );
cin.getline(diagnosis,50);
cout<<"\n\nEnter the student lab report result\n";
//cin.ignore( );
cin.getline(lab_report,50);
cout<<"\n\nEnter the blood type of student\n";
cin>>blood_type;
cout<<"\n\nEnter the docter prescription\n";
cin.ignore( );
cin.getline(prescription,50);	

}
void student::showdata() const
{
	cout<<"\nRoll number of student   :"<<id;
	cout<<"\nName of student          :"<<name;
	cout<<"\nAge of student           :"<<age;
	cout<<"\nDepartement of student   :"<<dep;
	cout<<"\nStudent past disease     :"<<past_dis;
	cout<<"\nStudent current symptoms :"<<current_symp;
	cout<<"\nStudent diagnosis        :"<<diagnosis;
	cout<<"\nResult of lab report     :"<<lab_report;
	cout<<"\nStudent blood type       :"<<blood_type;
    cout<<"\nDoctor prescription      :"<<prescription;

	
}
int student::retrollno() const
{
	return id;
}
void write_student();
void display_all();
void display_sp(int);
void modify_student(int);
void delete_student(int);
void class_result();
void result();
void intro();
void entry_menu();

int main()
{
char ch;
cout.setf(ios::fixed|ios::showpoint);
cout<<setprecision(2);
intro();
do
{
	system("cls");
	cout<<"\n\n\n\tMAIN MENU";
	cout<<"\n\n\n\t1:ENTERY MENU";
	cout<<"\n\n\n\t2:EXIT";
	cout<<"\n\n\n\tplease select your option(1-2)";
	cin>>ch;
switch(ch)
{
	case '1':
		entry_menu();
		break;
	case '2':
		break;
	default:cout<<"\a";
	
	}	
	}while(ch!='2');	
return 0;
 } 
 int c=0;
 void write_student()
 {
 	
 	student st;
 	ofstream outfile;
 	outfile.open("clin.dat",ios::binary|ios::app);
 	c=c+1;
 	st.getdata();
 	outfile.write(reinterpret_cast<char *> (&st),sizeof(student));
 	outfile.close();
 	cout<<"\n\nstudent record has been created ";
 	cin.ignore();
 	cin.get();
 	
 }
 void display_all()
 {
 	student st;
 	ifstream infile;
 	infile.open("clin.dat",ios::binary);
 	if(!infile)
 	{
 		cout<<"\n\n\n\tDISPLAY ALL RECORD!!\n\n";
 		cin.ignore();
 		cin.get();
 		return;
	 }
	 cout<<"\n\n\n\tDISPLAY ALL RECORD !!\n\n";
	 while(infile.read(reinterpret_cast<char *> (&st),sizeof(student)))
	 {
	 	st.showdata();
	 	cout<<"\n\n======================================================\n";
	 }
	 infile.close();
	 cin.ignore();
	 cin.get();
 }
 void display_sp(int n)
 {
 	student st;
 	ifstream infile;
 	infile.open("clin.dat",ios::binary);
 	if(!infile)
 	{
 	cout<<"file could not open!!! press any key...";
	 cin.ignore();
	 cin.get();
	 return;	
	 }
	 bool flag=true;
	 while(infile.read(reinterpret_cast<char *> (&st),sizeof(student)));
	 {
	 	if(st.retrollno()==n)
	 	{
	 		st.showdata();
	 		flag=true;
		 }
	 }
	 infile.close();
	 if(flag==false)
	 cout<<"\n\nrecord not exist";
	 cin.ignore();
	 cin.get();
 }
 void modify_student(int n)
 {
 	bool found=false;
 	student st;
 	fstream file;
 	file.open("clin.dat",ios::binary|ios::in|ios::out);
 	if(!file)
 	{
 	cout<<"file could not open!! press any key";
	 cin.ignore();
	 cin.get();
	 return;	
	 }
	 while(!file.eof()&&found==false)
	 {
	 	file.read(reinterpret_cast<char *> (&st),sizeof(student));
	 	if(st.retrollno()==n)
	 	{
	 	st.showdata();
		 cout<<"\n\nplease enter student new detial student\n";
		 st.getdata();
		 int pos=(-1)*static_cast<int>(sizeof(st));
		 file.seekp(pos,ios::cur);
		 file.write(reinterpret_cast<char *> (&st),sizeof(student));
		 cout<<"\n\n\t record updated";
		 found=true;	
	 		
		 }
	 }
	 file.close();
	 if(found==false)
	 cout<<"\n\nrecord not found ";
	 cin.ignore();
	 cin.get();
 }
 void delete_student(int n)
 {
 	student st;
 	ifstream infile;
 	infile.open("clin.dat",ios::binary);
 	if(!infile)
 	{
 	cout<<"file could not open!! press any key...";
	 cin.ignore();
	 cin.get();
	 return;	
	 }
	 ofstream outfile;
	 outfile.open("temp.dat",ios::out);
	 infile.seekg(0,ios::beg);
	 while(infile.read(reinterpret_cast<char *> (&st),sizeof(student)))
	 {
	 	if(st.retrollno()!=n)
	 	{
	 		outfile.write(reinterpret_cast<char *> (&st),sizeof(student));
		 }
	 }
	 outfile.close();
	 remove("clin.dat");
	 rename("temp.dat","clinic.dat");
	 cout<<"\n\n\trecord delated..";
	 cin.ignore();
	 cin.get();
 }
void intro()
{
	cout<<"===========================================================\n";
	cout<<"        WELCOME TO WOLKITE UNIVERSITY CLINIC\n";
	cout<<"           THIS SOFTWARE IS DEVELOPED BY     \n";
	cout<<"                   MINICHIL ABOYE        \n";
	//cout<<"           ABDULWUHAB MOHAMMED   0050/13        \n";
//	cout<<"           ABDULAZIZ  HABTAMU    0038/13         \n";
	cout<<"===========================================================\n";
    cout<<"########## CLINICAL MANAGEMENT SYSTEM FOR WKU STUDENTS #################\n";
	cout<<"\n\n\n\t\t      PROJECT";
	//cout<<"\n\n\n\t\t BY GROUP SIX STUDENT";
	cout<<"\n\n\n\t\tPRESS ANY KEY TO CONTINUE\n";
	cin.get();
}
void entry_menu()
{
	char ch;
	int num;
	system("cls");
	cout<<"\n\n\n\t enter menu";
	cout<<"\n\n\n\t 1:create student record";
	cout<<"\n\n\n\t 2:display all student record";
	cout<<"\n\n\n\t 3:search student record";
	cout<<"\n\n\n\t 4:modify student record";
	cout<<"\n\n\n\t 5:delete student record";
	cout<<"\n\n\n\t 6:back to menu";
	cout<<"\n\n\tplease enter your choice (1_6) ";
	cin>>ch;
	system("cls");
 	switch(ch)
 	{
 	case '1':
	 write_student();
	 break;
	 case '2':
	 display_all();
	 break;
	 case '3':
	 cout<<"\n\n\t please enter the ID number";cin>>num;
	 display_sp(num);break;
	 display_sp(num);break;
	 display_sp(num);break;
	 display_sp(num);break;
	 display_sp(num);break;	
	 case '4':cout<<"\n\n\tplease enter the ID number";cin>>num;
	 modify_student(num);break;
	 case '5':cout<<"\n\n\tplease enter the ID number";cin>>num;
	 delete_student(num);break;
	 case '6':break;
	 default:cout<<"\a";entry_menu();
 		
	 }
	
} 


