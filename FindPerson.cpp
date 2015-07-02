#include "FindPerson.h"
using namespace std;

FindPerson::FindPerson(int totNum = 0) {
}

FindPerson::FindPerson(const Interview& interview) {
	m_interview = interview;
	m_totNum = interview.getSize();	
	m_resident = new Resident[m_totNum];
}

FindPerson::~FindPerson() {
	delete[] m_resident;
}

void FindPerson::search() {

	for (int i = 0; i < m_totNum; i++) {

		/* --------------------------------
			1��° �ֹ��� ������ �ΰ�
		--------------------------------- */
		if (i == 0) {
			m_resident[i].setIsPerson(true);
		}

		if (m_resident[i][0] == true && m_resident[i][1] == false) {
			checkPerson(i);
			m_resident[i].setIsInterviewed(true);
		}		

		if (isAllChecked(i) == false) {
			i = 0;
		}	
	}	
}

void FindPerson::search2() {

	do {
		for (int i = 0; i < m_totNum; i++) {

			/* --------------------------------
				1��° �ֹ��� ������ �ΰ�
			--------------------------------- */
			if (i == 0) {
				m_resident[i].setIsPerson(true);
			}

			if (m_resident[i][0] == true && m_resident[i][1] == false) {
				checkPerson(i);
				m_resident[i].setIsInterviewed(true);
			}	
		}
	} while (isAllChecked(m_totNum) == false);
}

void FindPerson::checkPerson(int person) {
	vector<int>::iterator iter;

	for (iter = m_interview.getInterview()[person].begin(); iter != m_interview.getInterview()[person].end(); ++iter) {		
		m_resident[*iter-1].setIsPerson(true);	
	}	
}

bool FindPerson::isAllChecked(int length) {

	for (int i = 0; i < length; i++) {
		if (m_resident[i][0] == true && m_resident[i][1] == false) {			
			return false;
		}
	}

	return true;
}

void FindPerson::printPersonList() const {
	bool isAllPerson = true;
	int nPerson = 0;

	cout << "[Person List]" << endl;
	for (int i = 0; i < m_totNum; i++) {
		if (m_resident[i][0] == true) {
			cout << i+1 << ((i+1)%5 == 0 ? '\n':'\t');

			if (isAllPerson != false) 
				isAllPerson = true;

			nPerson++;
		} else {
			isAllPerson = false;
		}
	}

	if (isAllPerson == true) {
		cout << "��� �ֹ��� �ΰ��Դϴ�. �� " << nPerson << " ��" << endl;
	} else {
		cout << nPerson << "���� �ֹ��� ����̰�, " << m_totNum-nPerson << "���� �ֹ��� �����Դϴ�." << endl;
	}
}

int FindPerson::getTOtNum() const {
	return m_totNum;
}
