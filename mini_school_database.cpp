#include<iostream>
#include<string>
using namespace std;

int s_count = 0;
int t_count = 0;
void addscount()
{
	s_count++;
}
void addtcount()
{
	t_count++;
}
struct login
{
	string id;
	string password;
};

void admin_login(login &l)
{
	cout << "Set ID:";
	cin >> l.id;
	cout << "Set password:";
	cin >> l.password;
}

bool access(login check)
{
	cout << endl;
	string id, pass;
	cout << "Enter ID:";
	cin >> id;
	if (id == check.id)
	{
		cout << "Input password:";
		cin >> pass;
		if (pass == check.password)
		{
			cout << "------------------------------" << endl;
			cout << "        Welcome " << check.id << endl;
			cout << "------------------------------" << endl;
			return true;
		}
		else
		{
			cout << "Incorrect password" << endl;
			return false;
		}
	}
	else
		cout << "ID not found!" << endl;

	return false;
}

class person
{
public:
	string name;
	int age;
	string cnic;
	int c_number; //contact
	person()
	{
		name = "";
		age = 0;
		cnic = "";
		c_number = 0;
	}
	void setname(string nam)
	{
		name = nam;
	}
	string getname()
	{
		return name;
	}
	void setage(int agee)
	{
		age = agee;
	}
	int getage()
	{
		return age;
	}
	void setcnic(string nic)
	{
		cnic = nic;
	}
	string getcnic()
	{
		return cnic;
	}
	void setnumber(int num)
	{
		c_number = num;
	}
	int getnumber()
	{
		return c_number;
	}
	void input()
	{
		cin.ignore();
		cout << "Input name:";
		getline(cin, name);
		cout << "Input age:";
		cin >> age;
		cin.ignore();
		cout << "Input cnic:";
		cin >> cnic;
		cin.ignore();
		cout << "Input contact number:";
		cin >> c_number;
		cin.ignore();
	}
	void print()
	{
		cout << "-----------------------------" << endl;
		cout << "Name:" << name << endl;
		cout << "Age:" << age << endl;
		cout << "Cnic:" << cnic << endl;
		cout << "Contact number:" << c_number << endl;
	}
	person(person &ob)
	{
		name = ob.name;
		age = ob.age;
		cnic = ob.cnic;
		c_number = ob.c_number;
	}
	~person()
	{
	}
};

class teacher : public person
{
public:
	string emp_id;
	string course;
	int salary;
	teacher()
	{
		emp_id = "";
		course = "";
		salary = 0;
	}
	void setemp_id(string id)
	{
		emp_id = id;
	}
	string getemp_id()
	{
		return emp_id;
	}
	void setsalary(int salry)
	{
		salary = salry;
	}
	int getsalary()
	{
		return salary;
	}
	void setcourse(string c)
	{
		course = c;
	}
	string getcourse()
	{
		return course;
	}
	void input()
	{
		person::input();
		cout << "Input employee id:";
		cin >> emp_id;
		cout << "Input course:";
		cin >> course;
		cout << "Input salary:";
		cin >> salary;

	}
	void searchname(string n)
	{
		if (n == getname())
		{
			print();
		}
	}
	void searchid(string n)
	{
		if (n == getemp_id())
		{
			print();
		}
	}
	void searchage(int n)
	{
		if (n == getage())
		{
			print();
		}
	}
	void searchsalaryg(double n)
	{
		if (salary >= getsalary())
		{
			print();
		}

	}
	void searchsalaryl(double n)
	{
		if (salary <= getsalary())
		{
			print();
		}

	}
	void print()
	{
		person::print();
		cout << "Employee Id:" << emp_id << endl;
		cout << "Course:" << course << endl;
		cout << "Salary:" << salary << endl;
		cout << "-----------------------------" << endl;
		cout << endl;
	}
	teacher(teacher &ob) : person(ob)
	{
		emp_id = ob.emp_id;
		course = ob.course;
		salary = ob.salary;
	}
	~teacher()
	{
	}
};

class student : public person
{
public:
	double cgpa;
	string degree;
	string rollno;
	student()
	{
		cgpa = 0;
		degree = "";
		rollno = "";
	}
	void setroll(string roll)
	{
		rollno = roll;
	}
	string getroll()
	{
		return rollno;
	}
	void setcgpa(double gpa)
	{
		cgpa = gpa;
	}
	double getcgpa()
	{
		return cgpa;
	}
	void setdegree(string degre)
	{
		degree = degre;
	}
	string getdegree()
	{
		return degree;
	}
	void input()
	{
		person::input();
		cout << "Input cgpa:";
		cin >> cgpa;
		cout << "Input degree:";
		cin >> degree;
		cout << "Input roll number:";
		cin >> rollno;
	}
	void print()
	{
		person::print();
		cout << "Roll#:" << rollno << endl;
		cout << "CGPA:" << cgpa << endl;
		cout << "Degree:" << degree << endl;
		cout << "-----------------------------" << endl;
		cout << endl;
	}
	void searchname(string n)
	{
		if (n == name)
		{
			print();
		}
	}
	void searchroll(string n)
	{
		if (n == getroll())
		{
			print();
		}
	}
	void searchage(int n)
	{
		if (getage() >= n)
		{
			print();
		}
	}

	void searchgpag(double n)
	{
		if (getcgpa() >= n)
		{
			print();
		}
	}
	void searchgpal(double n)
	{
		if (getcgpa() <= n)
		{
			print();
		}
	}
	student(student &ob) : person(ob)
	{
		cgpa = ob.cgpa;
		degree = ob.degree;
	}
	~student()
	{
	}
};

int main()
{
	const int capacity_student = 10;
	const int capacity_teacher = 5;
	login admin;
	admin_login(admin);
	if (access(admin))
	{
		student *s = new student[capacity_student];
		teacher *t = new teacher[capacity_teacher];
		int choice;
		do
		{
			int i, x, modify1;
			string modify2;
			cout << "------------------------------" << endl;
			cout << "|        For student         |" << endl;
			cout << "|Input 1 to add student      |" << endl;
			cout << "|Input 2 to modify student   |" << endl;
			cout << "|Input 3 to search student   |" << endl;
			cout << "|Input 8 to display all student|" << endl;
			cout << "------------------------------" << endl;
			cout << "|        For Teacher         |" << endl;
			cout << "|Input 4 to add teacher      |" << endl;
			cout << "|Input 5 to modify teacher   |" << endl;
			cout << "|Input 6 to search teacher   |" << endl;
			cout << "|Input 7 to display all teacher|" << endl;
			cout << "-----------------------------" << endl;
			cout << "|Input 9 to exit             |" << endl;
			cout << "-----------------------------" << endl;
			cin >> choice;
			if (choice == 1)
			{
				s[s_count].input();
			}
			else if (choice == 2)
			{
				cout << "------------------------------" << endl;
				cout << "|        Modify Student      |" << endl;
				cout << "|Input 1 for name            |" << endl;
				cout << "|Input 2 for age             |" << endl;
				cout << "|Input 3 for cnic            |" << endl;
				cout << "|Input 4 for contact         |" << endl;
				cout << "|Input 5 for Roll number     |" << endl;
				cout << "|Input 6 for Cgpa            |" << endl;
				cout << "|Input 7 for degree          |" << endl;
				cout << "|Input 8 for modify all      |" << endl;
				cout << "------------------------------" << endl;
				cin >> x;
				cout << "Input student number:";
				cin >> i;
				i--;
				if (x == 1)
				{
					cin.ignore();
					cout << "Input new name:";
					cin >> modify2;
					s[i].setname(modify2);
				}
				else if (x == 2)
				{
					cout << "Input new age:";
					cin >> modify1;
					s[i].setage(modify1);
				}
				else if (x == 3)
				{
					cin.ignore();
					cout << "Input new cnic:";
					cin >> modify2;
					s[i].setcnic(modify2);
				}
				else if (x == 4)
				{
					cout << "Input new contact:";
					cin >> modify1;
					s[i].setnumber(modify1);
				}
				else if (x == 5)
				{
					cin.ignore();
					cout << "Input new roll#:";
					cin >> modify2;
					s[i].setroll(modify2);
				}
				else if (x == 6)
				{
					cout << "Input new Cgpa:";
					cin >> modify1;
					s[i].setcgpa(modify1);
				}
				else if (x == 7)
				{
					cin.ignore();
					cout << "Input modify degree:";
					cin >> modify2;
					s[i].setdegree(modify2);
				}
				else if (x == 8)
				{
					s[i].input();
				}
			}
			else if (choice == 3)
			{
				cout << "------------------------------" << endl;
				cout << "|        Search student      |" << endl;
				cout << "|1 by name                   |" << endl;
				cout << "|2 by roll  no               |" << endl;
				cout << "|3 by all specific age       |" << endl;
				cout << "|4 student cgpa more then given by admin|" << endl;
				cout << "|5 student cgpa less then given by admin|" << endl;
				cout << "------------------------------------------" << endl;
				cin >> x;
				string name;
				if (x == 1)
				{
					cout << "Input student name you want to search data:";
					cin >> name;
					for (int i = 0; i < capacity_student; i++)
					{
						if (name == s[i].getname())
						{
							s[i].searchname(name);
						}
					}
				}
				else if (x == 2)
				{
					cout << "Input student roll no you want to search data:";
					cin >> name;
					for (int i = 0; i < capacity_student; i++)
					{
						if (name == s[i].getroll())
						{
							s[i].print();
						}
					}
				}
				else if (x == 3)
				{
					int age;
					cout << "Input student age you want to search data:";
					cin >> age;
					for (int i = 0; i < capacity_student; i++)
					{
						s[i].searchage(age);
					}
				}
				else if (x == 4)
				{
					double gpa;
					cout << "Input cgpa to search student more cgpa:";
					cin >> gpa;
					for (int i = 0; i < capacity_student; i++)
					{
						s[i].searchgpag(gpa);
					}
				}
				else if (x == 5)
				{
					double gpa;
					cout << "Input cgpa to search student less cgpa:";
					cin >> gpa;
					for (int i = 0; i < capacity_student; i++)
					{
						s[i].searchgpal(gpa);
					}
				}
			}
			else if (choice == 4)
			{
				t[t_count].input();

			}
			else if (choice == 5)
			{
				cout << "------------------------------" << endl;
				cout << "|        Modify Teacher      |" << endl;
				cout << "|Input 1 for name            |" << endl;
				cout << "|Input 2 for age             |" << endl;
				cout << "|Input 3 for cnic            |" << endl;
				cout << "|Input 4 for contact         |" << endl;
				cout << "|Input 5 for Employee ID     |" << endl;
				cout << "|Input 6 for Course          |" << endl;
				cout << "|Input 7 for salary          |" << endl;
				cout << "|Input 8 for update all      |" << endl;
				cout << "------------------------------" << endl;
				cin >> x;
				cout << "Input teacher number:";
				cin >> i;
				i--;
				if (x == 1)
				{
					cin.ignore();
					cout << "Input new name:";
					cin >> modify2;
					t[i].setname(modify2);
				}
				else if (x == 2)
				{
					cout << "Input new age:";
					cin >> modify1;
					t[i].setage(modify1);
				}
				else if (x == 3)
				{
					cin.ignore();
					cout << "Input new cnic:";
					cin >> modify2;
					t[i].setcnic(modify2);
				}
				else if (x == 4)
				{
					cout << "Input new contact no:";
					cin >> modify1;
					t[i].setnumber(modify1);
				}
				else if (x == 5)
				{
					cin.ignore();
					cout << "Input new employee id:";
					cin >> modify2;
					t[i].setemp_id(modify2);
				}
				else if (x == 6)
				{
					cin.ignore();
					cout << "Input modify course:";
					cin >> modify2;
					t[i].setcourse(modify2);
				}
				else if (x == 7)
				{
					cout << "Input modify salary:";
					cin >> modify1;
					t[i].setsalary(modify1);
				}
				else if (x == 8)
				{
					t[i].input();
				}
				cout << "Data is updated!" << endl;
			}
			else if (choice == 6)
			{
				cout << "------------------------------" << endl;
				cout << "|        Search Teacher      |" << endl;
				cout << "|1 by name                   |" << endl;
				cout << "|2 by employee ID            |" << endl;
				cout << "|3 by all specific age       |" << endl;
				cout << "|4 teachers salary more then given by admin|" << endl;
				cout << "|5 Teachers salary less then given by admin|" << endl;
				cout << "-------------------------------------------" << endl;
				cin >> x;
				string name;
				if (x == 1)
				{
					cout << "Input teacher name you want to search data:";
					cin >> name;
					for (int i = 0; i < capacity_teacher; i++)
					{
						t[i].searchname(name);
					}
				}
				else if (x == 2)
				{
					cout << "Input teacher employee id you want to search data:";
					cin >> name;
					for (int i = 0; i < capacity_teacher; i++)
					{
						t[i].searchid(name);
					}
				}
				else if (x == 3)
				{
					int age;
					cout << "Input teacher age you want to search data:";
					cin >> age;
					for (int i = 0; i < capacity_teacher; i++)
					{
						t[i].searchage(age);
					}
				}
				else if (x == 4)
				{
					int salary;
					cout << "Input salary to search teachers have more salary:";
					cin >> salary;
					for (int i = 0; i < capacity_teacher; i++)
					{
						t[i].searchsalaryg(salary);
					}
				}
				else if (x == 5)
				{
					double salary;
					cout << "Input salary to search teachers have less salary:";
					cin >> salary;
					for (int i = 0; i <capacity_teacher; i++)
					{
						t[i].searchsalaryg(salary);
					}
				}
			}
			else if (choice == 7)
			{
				for (int i = 0; i <= t_count; i++)
				{
					t[i].print();
				}
			}
			else if (choice == 8)
			{
				for (int i = 0; i <= s_count; i++)
				{
					s[i].print();
				}
			}
		} while (choice != 9);
		system("pause");
		delete[] s;
		delete[] t;
	}
	system("pause");
	return 0;
}
