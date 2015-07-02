
#ifndef _INTERVIEW_CLASS
#define _INTERVIEW_CLASS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Interview {
private :
	vector<int>* m_interview;
	ifstream m_file;
	int m_size;

public :
	Interview();
	explicit Interview(char* arg_file);
	~Interview();
	int getInterview(int i, int j) const;
	vector<int>* getInterview() const;
	void setInterview(char* arg_file);
	void printInterview() const;
	int getSize() const;
	ifstream getFile() const;
	Interview& operator =(const Interview& interview);
};

#endif

