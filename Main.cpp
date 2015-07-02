#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Interview.h"
#include "FindPerson.h"
#include "Resident.h"
using namespace std;

void main(int argc, char* argv[])
{
	if (argc < 2) {
		cout << "execute : Program.exe file.txt" << endl;
		exit(-1);
	}

	Interview interview(argv[1]);

	FindPerson findPerson(interview);	

	cout << "ÃÑ " << findPerson.getTOtNum() << "¸íÀÇ ÁÖ¹Î" << endl;
	findPerson.search2();
	findPerson.printPersonList();

}