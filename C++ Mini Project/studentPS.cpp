//student managment using file handling
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
using namespace std;
class student{
	private:
		string name,roll_no, course, email_id, contact_no;
	public:
		void menu();
		void insert();
		void display();
		void modify();
		void search();
		void deleted();
};

void student::menu(){
	menustart:
	int choice;
	char x;
	system("cls");
	
	cout<<"\t\t\t---------------------------"<<endl;
	cout<<"\t\t\t| STUDENT MANAGMENT SYSTEM | "<<endl;
	cout<<"\t\t\t---------------------------"<<endl;
	
	cout<<"\t\t\t 1. Enter new Record"<<endl;
	cout<<"\t\t\t 2. Display Record"<<endl;
	cout<<"\t\t\t 3. Modify Record"<<endl;
	cout<<"\t\t\t 4. Search Record"<<endl;
	cout<<"\t\t\t 5. Delete Record "<<endl;
	cout<<"\t\t\t 6. Exit "<<endl;
	
	cout<<"\t\t\t---------------------------"<<endl;
	cout<<"\t\t\t Chooze Option[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t---------------------------"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			do
			{
				insert();
				cout<<"\n\t\t\t Add Another student Record[Y/N]: ";
				cin>>x;	
			}while(x=='y' || x=='Y');
			break;
		case 2:
			display();
			break;
		case 3:
			modify();
			break;
		case 4:
			search();
			break;
		case 5:
			deleted();
			break;
		
		case 6:
			exit(0);
			
		default:
			cout<<"\n\t\t\t Invalid Choice....please try again.....";	
	}
	getch();
	goto menustart;	
}

void student::insert() //adding student details
{
	system("cls");
	fstream file;
	cout<<"\n----------------------------------------------------------------------------------------------";
	cout<<"\n-----------------------------ADD STUDENT DETAILS-----------------------------------------------"<<endl;
	cout<<"\t\t\t Enter name: ";
	cin>>name;
	cout<<"\t\t\t Enter Roll No: ";
	cin>>roll_no;
	cout<<"\t\t\t Enter course: ";
	cin>>course;
	cout<<"\t\t\t Enter email Id: ";
	cin>>email_id;
	cout<<"\t\t\t Enter Contact No: ";
	cin>>contact_no;
	file.open("studentRecord.txt", ios::app | ios::out);
	file<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<"\n";
	file.close();	
}

void student::display() //method for displaying data
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n----------------------------------------------------------------------------------------------";
	cout<<"\n-----------------------------DISPLAY STUDENT DETAILS-----------------------------------------------"<<endl;
	file.open("studentRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\t---No data is present---";
		file.close();
	}
	else
	{
		file>>name>>roll_no>>course>>email_id>>contact_no;
		while(!file.eof())
		{
			cout<<"\n\n\t\t Student No.: " << total++ <<endl;
			cout<<"\t\t\t Student Name: " << name <<endl;
			cout<<"\t\t\t Student Roll No: " << roll_no <<endl;
			cout<<"\t\t\t Student Course: " << course<<endl;
			cout<<"\t\t\t Student Email Id: " << email_id <<endl;
			cout<<"\t\t\t Student Contact No:  " << contact_no <<endl;
			file>>name>>roll_no>>course>>email_id>>contact_no;		
		}
		if(total==0)
		{
			cout<<"\n\t\t\t---No data is present---";
		}
	}
	file.close();	
}

void student::modify()
{
	system("cls");
	fstream file,file1;
	string rollno;
	int found=0;
	cout<<"\n----------------------------------------------------------------------------------------------";
	cout<<"\n-----------------------------MODIFY STUDENT DETAILS-----------------------------------------------"<<endl;
	file.open("studentRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\t---No Data Present----";
		file.close();
	}
	else
	{
		cout<<"\n Enter the roll no of student which you want to modify: ";
		cin>>rollno;
		file1.open("Record.txt",ios::app | ios::out);
		file>>name>>roll_no>>course>>email_id>>contact_no;
		while(!file.eof())
		{
			if(rollno != roll_no)
			{
				file1<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<"\n";
			}
			else
			{
				cout<<"\t\t\t Enter name: ";
				cin>>name;
				cout<<"\t\t\t Enter Roll No: ";
				cin>>roll_no;
				cout<<"\t\t\t Enter course: ";
				cin>>course;
				cout<<"\t\t\t Enter email Id: ";
				cin>>email_id;
				cout<<"\t\t\t Enter Contact No: ";
				cin>>contact_no;
				file1<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<"\n";
				found++; 	
			}
			file>>name>>roll_no>>course>>email_id>>contact_no;
			if(found == 0)
			{
				cout<<"\n\t\t\t Student Roll no not found...";
			}
			
		}
		file1.close();
		file.close();
		remove("studentRecord.txt");
		rename("record.txt","studentRecord.txt");
	}	
}

void student::search() //search the data
{
	system("cls");
	fstream file;
	int found=0;
	file.open("studentRecord.txt",ios::in);
	if(!file)
	{
	cout<<"\n----------------------------------------------------------------------------------------------";
	cout<<"\n-----------------------------SEARCH STUDENT DETAILS-----------------------------------------------"<<endl;
	cout<<"\n\t\t\t No Data is Present...";	
	}
	else
	{
		string rollno;
		cout<<"\n----------------------------------------------------------------------------------------------";
		cout<<"\n-----------------------------SEARCH STUDENT DETAILS-----------------------------------------------"<<endl;
		cout<<"\n Enter the roll no of student you want to find: ";
		cin>>rollno;
		file>>name>>roll_no>>course>>email_id>>contact_no;
		while(!file.eof())
		{
			if(rollno==roll_no)
			{
				cout<<"n\t\t\t Student Name: " << name <<endl;
				cout<<"\t\t\t Student Roll No: " << roll_no <<endl;
				cout<<"\t\t\t Student Course: " << course<<endl;
				cout<<"\t\t\t Student Email Id: " << email_id <<endl;
				cout<<"\t\t\t Student Contact No:  " << contact_no <<endl;
				found++;
			}
			file>>name>>roll_no>>course>>email_id>>contact_no;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t ....Student rollno not found...";	
		}
		file.close();		
	}
}

void student::deleted()
{
	system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no<< "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
	}
}


main(){
	student project;
	project.menu();
	return 0;
	
}
