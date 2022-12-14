#pragma once
#include <cstring>
#include "PatientNode.h"

class PatientBSTNode
{
private:
	char * Name;
	char Disease;

	PatientBSTNode * pLeft;
	PatientBSTNode * pRight;

public:
	PatientBSTNode(PatientNode * node);
	~PatientBSTNode();

	char * GetName();
	char GetDisease();
	PatientBSTNode * GetLeft();
	PatientBSTNode * GetRight();

	void SetName(char * name);
	void SetDisease(char disease);
	void SetLeft(PatientBSTNode * node);
	void SetRight(PatientBSTNode * node);
};
