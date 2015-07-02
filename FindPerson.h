
#ifndef _FINDPERSON_CLASS
#define _FINDPERSON_CLASS

#include "Interview.h"
#include "Resident.h"
using namespace std;

class FindPerson {
private :
	Interview m_interview;
	Resident* m_resident;
	int m_totNum;

public :
	explicit FindPerson(int totNum);
	explicit FindPerson(const Interview& interview);
	~FindPerson();
	void search();
	void search2();
	void printPersonList() const;
	int getTOtNum() const;
	
private :
	void checkPerson(int person);
	bool isAllChecked(int length);
};

#endif

