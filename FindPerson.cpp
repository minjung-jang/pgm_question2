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

/*---------------------------------------------------------------
	알고리즘 1.
	- 전체 주민수와 각 주민이 인터뷰 시 지목한 사람의 숫자가
	큰 차이가 없는 경우 효율적
-----------------------------------------------------------------*/
void FindPerson::search() {

	for (int i = 0; i < m_totNum; i++) {

		/* --------------------------------
			1번째 주민은 무조건 인간
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

/*---------------------------------------------------------------
	알고리즘 2.
	- 전체 주민수와 각 주민이 인터뷰 시 지목한 사람의 숫자가
	큰 차이가 있는 경우 효율적 (p2-2의 경우 비교할 수 없을 정도로 빠름)
-----------------------------------------------------------------*/
void FindPerson::search2() {

	do {
		for (int i = 0; i < m_totNum; i++) {

			/* --------------------------------
				1번째 주민은 무조건 인간
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

/*---------------------------------------------------------------
	해당 주민이 사람이라고 표시하는 함수.
-----------------------------------------------------------------*/
void FindPerson::checkPerson(int person) {
	vector<int>::iterator iter;

	for (iter = m_interview.getInterview()[person].begin(); iter != m_interview.getInterview()[person].end(); ++iter) {		
		m_resident[*iter-1].setIsPerson(true);	
	}	
}

/*---------------------------------------------------------------
	모든 사람인 주민의 인터뷰 확인 여부 반환
-----------------------------------------------------------------*/
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
		cout << "모든 주민은 인간입니다. 총 " << nPerson << " 명" << endl;
	} else {
		cout << nPerson << "명의 주민이 사람이고, " << m_totNum-nPerson << "명의 주민이 마족입니다." << endl;
	}
}

int FindPerson::getTotNum() const {
	return m_totNum;
}
