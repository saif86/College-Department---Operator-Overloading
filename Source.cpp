#include<iostream>
#include<string>
using namespace std;

class CollegeDepartment
{
	char * departmentName;
	char * chair;
	int noOfClasses;
	string * courses;
public:
	//CollegeDepartment();
	CollegeDepartment(char * = NULL, char * = NULL, int = 0, string * = NULL);
	friend ostream & operator <<(ostream &, const CollegeDepartment &);
	bool operator < (const CollegeDepartment &);
	bool operator > (const CollegeDepartment &);
	CollegeDepartment & operator = (const CollegeDepartment &);
};

/*CollegeDepartment::CollegeDepartment() :departmentName(NULL), chair(NULL), noOfClasses(0), courses(NULL)
{

}*/

CollegeDepartment::CollegeDepartment(char * aDepartment, char * aChair, int aNoOfCourses, string * aCourses) : departmentName(NULL), chair(NULL), noOfClasses(0), courses(NULL)
{
	if (aDepartment != NULL)
	{
		departmentName = new char[strlen(aDepartment) + 1];
		strcpy_s(departmentName, strlen(aDepartment) + 1, aDepartment);
	}

	if (aChair != NULL)
	{
		chair = new char[strlen(aChair) + 1];
		strcpy_s(chair, strlen(aChair) + 1, aChair);
	}

	noOfClasses = aNoOfCourses;

	if (aNoOfCourses != 0)
	{
		courses = new string[noOfClasses];
		char name[50];
		for (int i = 0; i < noOfClasses; i++)
		{
			cout << "Enter name of Course" << i + 1 << ": ";
			_flushall();
			gets_s(name);
			courses[i] = name;
		}
	}


}

ostream & operator <<(ostream & os, const CollegeDepartment & d)
{
	cout << "Department: " << (d.departmentName ? d.departmentName : "NULL") << endl;
	cout << "Chairperson: " << (d.chair ? d.chair : "NULL") << endl;
	cout << "Number of courses: " << d.noOfClasses << endl;
	if (d.courses != NULL)
	{
		for (int i = 0; i < d.noOfClasses; i++)
		{
			cout << "Course" << i + 1 << ": " << d.courses[i] << endl;
		}
	}
	else
		cout << "NULL" << endl;

	return os;
}


bool CollegeDepartment::operator < (const CollegeDepartment & d)
{
	if (noOfClasses < d.noOfClasses)
		return true;
	else
		return false;
}

bool CollegeDepartment::operator > (const CollegeDepartment & d)
{
	if (noOfClasses > d.noOfClasses)
		return true;
	else
		return false;
}

CollegeDepartment & CollegeDepartment::operator = (const CollegeDepartment & d)
{
	if (this != &d) {
		noOfClasses = d.noOfClasses;
		delete[] departmentName;
		delete[] chair;
		delete[] courses;


		if (d.departmentName != NULL) {
			departmentName = new char[strlen(d.departmentName) + 1];
			strcpy_s(departmentName, strlen(d.departmentName) + 1, d.departmentName);
		}
		else
			departmentName = NULL;

		if (d.chair != NULL) {
			chair = new char[strlen(d.chair) + 1];
			strcpy_s(chair, strlen(d.chair) + 1, d.chair);
		}
		else
			chair = NULL;

		if (d.courses != NULL) {
			courses = new string[noOfClasses];
			for (int i = 0; i < noOfClasses; i++)
				courses[i] = d.courses[i];
		}
		else
			courses = NULL;
	}
	return *this;
}

void main()
{
	CollegeDepartment cd1("Mathematics", "Dr. Ishaq", 3);
	CollegeDepartment cd2;

	cout << cd1 << cd2 << endl;

	if (cd1 > cd2)
		cout << "cd1 has more courses than cd2" << endl;
	else if (cd1 < cd2)
		cout << "cd1 has less courses than cd2" << endl;
	else
		cout << "cd1 & cd2 has same courses" << endl;
	cd2 = cd1;



	cout << cd1 << cd2 << endl;

	if (cd1 > cd2)
		cout << "cd1 has more courses than cd2" << endl;
	else if (cd1 < cd2)
		cout << "cd1 has less courses than cd2" << endl;
	else
		cout << "cd1 & cd2 has same courses" << endl;

	system("pause");
}
