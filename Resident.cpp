
#include <iostream>
#include "Resident.h"
using namespace std;

Resident::Resident() {
	m_isPerson = false;
	m_isInterviewed = false;
}

bool Resident::getIsPerson() const {
	return m_isPerson;
}

bool Resident::getIsInterviewed() const {
	return m_isInterviewed;
}

void Resident::setIsPerson(bool isPerson) {
	m_isPerson = isPerson;
}

void Resident::setIsInterviewed(bool isInterviewed) {
	m_isInterviewed = isInterviewed;
}

/*--------------------------------------------------------
	멤버변수에 편리하게 접근하기 위한 연산자 오버로딩
	0 - m_isPerson (사람인지 아닌지)
	1 - m_isInterviewed (인터뷰 확인 완료 여부)
----------------------------------------------------------*/
bool Resident::operator [](int index) const {
	if (index == 0) {
		return m_isPerson;
	} else if (index == 1) {
		return m_isInterviewed;
	} else {
		cout << "overflow! index range {0, 1}" << endl;
		return false;
	}
}

