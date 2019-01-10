/**
* @file Source.cpp
*
* @brief C++ Program to demostrate operator overloading.
*
* @author Saif Ullah Ijaz
*
*/

// SYSTEM INCLUDES
#include <iostream> 
#include <string>
using namespace std;

// CollegeDepartment class definition
class CollegeDepartment {
public:
// LIFECYCLE
	/** Default + Overloaded constructor.
	*/
	CollegeDepartment(const string& = "", const string& = "", int = 0, const string* = NULL);

	// Use compiler-generated copy constructor, and destructor.
	// CollegeDepartment(const CollegeDepartment&);
	// ~CollegeDepartment();


// OPERATORS
	/** Stream Insertion operator.
	*
	* @param os Standard Output Stream.
	* @param from The value to be inserted to the output stream.
	*
	* @return A reference to the standard output stream.
	*/
	friend std::ostream& operator <<(std::ostream& os, const CollegeDepartment& from);

	/** Stream Extraction operator.
	*
	* @param is Standard Intput Stream.
	* @param to The value to be extracted from the input stream.
	*
	* @return A reference to the standard input stream.
	*/
	friend std::istream& operator >>(std::istream& is, CollegeDepartment& to);

	/** Less than operator.
	*
	* @param rhs The reference to the right hand operand.
	*
	* @return True if the object has less courses than rhs object, false otherwise.
	*/
	bool operator < (const CollegeDepartment& rhs);

	/** Greater than operator.
	*
	* @param rhs The reference to the right hand operand.
	*
	* @return True if the object has more courses than rhs object, false otherwise.
	*/
	bool operator > (const CollegeDepartment& rhs);

	/** Assignment operator.
	*
	* @param rhs The reference to the right hand operand.
	*
	* @return Reference to the (assigned/updated) current object.
	*/
	CollegeDepartment& operator =(const CollegeDepartment& rhs);



// ACCESS
	// setters
	void SetDepartmentName(const string& = "");
	void SetChair(const string& = "");
	void SetNoOfClasses(int = 0);
	void SetCourses(const string* = NULL);
	void SetCollegeDepartment(const string& = "", const string& = "", int = 0, const string* = NULL);
	/**
	# @overload void SetCollegeDepartment(const CollegeDepartment& aCollegeDepartment);
	*/
	void SetCollegeDepartment(const CollegeDepartment& aCollegeDepartment);

	// getters
	const string& GetDepartmentName() const;
	const string& GetChair() const;
	int GetNoOfClasses() const;
	const string* GetCourses() const;
	const CollegeDepartment& GetCollegeDepartment()const;

private:

	// DATA MEMBERS
	string mDepartmentName;
	string mChair;
	int mNoOfClasses;
	string* mCourses;
};
// end class CollegeDepartment

// File scope starts here 

/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

// CollegeDepartment Default+Overloaded Constructor
CollegeDepartment::CollegeDepartment(const string& aDepartmentName, const string& aChair, int aNoOfClasses, const string* aCourses) : mDepartmentName(aDepartmentName), mChair(aChair), mNoOfClasses(aNoOfClasses) {
	this->SetCollegeDepartment(aDepartmentName, aChair, aNoOfClasses, aCourses);
}
// end CollegeDepartment constructor 

//============================= OPERATORS ====================================
// Stream Insertion
ostream & operator <<(ostream & os, const CollegeDepartment& from) {
	cout << "Department: " << from.GetDepartmentName() << endl;
	cout << "Chairperson: " << from.GetChair() << endl;
	cout << "Number of courses: " << from.GetNoOfClasses() << endl;
	if (from.mCourses != NULL)
	{
		for (int i = 0; i < from.GetNoOfClasses(); i++)
		{
			cout << "Course" << i + 1 << ": " << from.mCourses[i] << endl;
		}
	}
	else
		cout << "NULL" << endl;

	return os;
}
// end stream insertion

// Stream Extraction
istream & operator >>(istream & is, CollegeDepartment& to) {
	string aName, aChair;
	int aNoOfCourses;
	cout << "Enter name of Department: ";
	getline(is, aName);
	cout << "Enter chairperson's name: ";
	getline(is, aChair);
	cout << "Enter no. of classes: ";
	is >> aNoOfCourses;
	to.SetCollegeDepartment(aName, aChair, aNoOfCourses, NULL);

	string name[50];
	cout << to.GetNoOfClasses() << endl;
	
	to.mCourses = new string[to.GetNoOfClasses()];
	is.ignore();
	for (int i = 0; i < to.GetNoOfClasses(); i++) {
		cout << "Enter name of Course" << i + 1 << ": ";
		getline(is, name[i]);
		to.mCourses[i] = name[i];
	}
	
	return is;
}
// end Stream Extraction

//  Less than operator.
bool CollegeDepartment::operator <(const CollegeDepartment& rhs) {
	if (this->GetNoOfClasses() < rhs.GetNoOfClasses())
		return true;
	else
		return false;
}
// end less than operator

//  Greater than operator.
bool CollegeDepartment::operator >(const CollegeDepartment& rhs) {
	if (this->GetNoOfClasses() > rhs.GetNoOfClasses())
		return true;
	else
		return false;
}
// end greater than operator

// Assignment operator.
CollegeDepartment & CollegeDepartment::operator =(const CollegeDepartment& rhs)
{
	
	if (this != &rhs) {
		this->SetDepartmentName(rhs.GetDepartmentName());
		this->SetChair(rhs.GetChair());
		this->SetNoOfClasses(rhs.GetNoOfClasses());
		if(this->mCourses)
			delete[] this->mCourses;
		
		if (rhs.GetCourses() != NULL) {
			this->mCourses = new string[this->GetNoOfClasses()];
			for (int i = 0; i < this->GetNoOfClasses(); i++)
				this->mCourses[i] = rhs.mCourses[i];
		}
		else
			this->mCourses = NULL;
	}
	return *this;
}
// end assignment operator

//============================= ACESS      ===================================

// function that sets name of CollegeDepartment
void CollegeDepartment::SetDepartmentName(const string& aDepartmentName) {
	this->mDepartmentName = aDepartmentName;
}
// end function SetDepartmentName

// function that sets chairperson of CollegeDepartment
void CollegeDepartment::SetChair(const string& aChair) {
	this->mChair = aChair;
}
// end function SetChair

// function that sets no. of classes
void CollegeDepartment::SetNoOfClasses(int aNoOfClasses) {
	if (aNoOfClasses < 0)
		cout << "Error: Number of classes cannot be nagative." << endl;
	else
		this->mNoOfClasses = aNoOfClasses;
}
// end function SetNoOfClasses

// function that sets courses of CollegeDepartment
void CollegeDepartment::SetCourses(const string* aCourses) {
	if (aCourses != NULL)
	{
		this->mCourses = new string[this->GetNoOfClasses()];
		for (int i = 0; i < this->GetNoOfClasses(); i++) {
			this->mCourses[i] = *aCourses;
			aCourses++;
		}
	}
	else
		this->mCourses = NULL;
}
// end function SetCourses

// function that sets the CollegeDepartment
void CollegeDepartment::SetCollegeDepartment(const string& aDepartmentName, const string& aChair, int aNoOfClasses, const string* aCourses) {
	this->SetDepartmentName(aDepartmentName);
	this->SetChair(aChair);
	this->SetNoOfClasses(aNoOfClasses);
	this->SetCourses(aCourses);
}
// end function SetCollegeDepartment

// overloaded function that sets the CollegeDepartment
void CollegeDepartment::SetCollegeDepartment(const CollegeDepartment& obj) {
	this->SetCollegeDepartment(obj.GetDepartmentName(), obj.GetChair(), obj.GetNoOfClasses(), obj.GetCourses());
}
// end function SetCollegeDepartment

// function that gets name of CollegeDepartment
const string& CollegeDepartment::GetDepartmentName() const {
	return this->mDepartmentName;
}
// end function GetDepartmentName

// function that gets chairperson of CollegeDepartment
const string& CollegeDepartment::GetChair() const {
	return this->mChair;
}
// end function GetChair

// function that gets no. of classes
int CollegeDepartment::GetNoOfClasses() const {
	return this->mNoOfClasses;
}
// end function GetNoOfClasses

// function that gets courses of CollegeDepartment
const string* CollegeDepartment::GetCourses() const {
	return this->mCourses;
}
// end function GetCourses

// function that gets the CollegeDepartment
const CollegeDepartment& CollegeDepartment::GetCollegeDepartment()const {
	return *this;
}
// end function GetCollegeDepartment

/////////////////////////////// MAIN   ///////////////////////////////////////

// function main begins program execution
void main() {
	string cours[3] = { "MAT101", "COMP5366", "ENG234" };

	CollegeDepartment cd1("Mathematics and Stats.", "Dr. M. Ishaq", 3, cours);
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
// end main
