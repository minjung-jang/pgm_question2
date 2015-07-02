
#ifndef _RESIDENT_CLASS
#define _RESIDENT_CLASS

class Resident {
private :
	bool m_isPerson;
	bool m_isInterviewed;

public :
	Resident();
	bool getIsPerson() const;
	bool getIsInterviewed() const;
	void setIsPerson(bool isPerson);
	void setIsInterviewed(bool isInterviewed);
	bool operator [](int index) const;
};

#endif

