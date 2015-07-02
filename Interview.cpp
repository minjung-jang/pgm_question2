
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Interview.h"
using namespace std;

Interview::Interview() {	
	m_size = 0;
	m_interview = 0;
}

Interview::Interview(char* arg_file) {
	m_file.open(arg_file);

	string size;
	
	getline(m_file, size);
	
	m_size = atoi(size.c_str());
	m_interview = new vector<int>[m_size];
    
	setInterview(arg_file);
}

Interview::~Interview() {
	if (m_file.is_open()) {
		m_file.close();
		delete[] m_interview;
		m_interview = 0;
	} 
}

int Interview::getInterview(int i, int j) const {
	return m_interview[i][j];
}

vector<int>* Interview::getInterview() const {
	return m_interview;
}

void Interview::setInterview(char* arg_file) {

	if (!m_file.is_open()) {
		m_file.open(arg_file);

		string size;
	
		getline(m_file, size);
		m_size = atoi(size.c_str());
	}
		
	string fileRecord, toNumber;
	int nPos = 0;

	while (getline(m_file, fileRecord)) {	
		vector<int> v_temp;
		toNumber = "";

		for (int i = 0; i < fileRecord.length(); i++) {
			if (fileRecord[i] != ' ') {
				toNumber += fileRecord[i];
			} else if (fileRecord[i] == ' ') {				
				v_temp.push_back(atoi(toNumber.c_str()));
				toNumber = "";
				continue;
			}
		}

		if (atoi(toNumber.c_str()) != 0) {
			v_temp.push_back(atoi(toNumber.c_str()));
		}

		vector<int>::iterator iter;
		for (iter = v_temp.begin(); iter != v_temp.end(); ++iter) {
			m_interview[nPos].push_back(*iter);
		}

		nPos++;		
	}
}

void Interview::printInterview() const {
	cout << "[Print Interview]" << endl;

	vector<int>::iterator iter;
	for (int nPos = 0; nPos < m_size; nPos++) {

		for (iter = m_interview[nPos].begin(); iter != m_interview[nPos].end(); ++iter) {
			cout << *iter << ' ';
		}
		cout << endl;
	}
}

int Interview::getSize() const {
	return m_size;
}

ifstream Interview::getFile() const {
	return m_file;
}

Interview& Interview::operator =(const Interview& interview) {
	(*this).m_interview = interview.getInterview();
	(*this).m_size = interview.getSize();
	
	return *this;
}

