#include <iostream>
#include <string>

using namespace std;

int main()
{	
	float fAccSubject = 0.f; 
	float fAccCredit = 0.f; 

	char szSubjectName[51] = {};
	char chGrade[3] = {};
	float fCredit = 0.f;

	for (int i = 0; i < 20; i++)
	{
		cin >> szSubjectName;
		cin >> fCredit;
		cin >> chGrade;

		if ('P' == chGrade[0])
			continue;

		fAccCredit += fCredit;

		if ('F' == chGrade[0])
			continue;
		
		float fSubjectAverage = 4.5f - float(chGrade[0] - 'A');

		if ('0' == chGrade[1])
			fSubjectAverage -= 0.5f;

		fAccSubject += fCredit * fSubjectAverage;
	}
	
	(0.f == fAccSubject) ? cout << 0.f : cout << fAccSubject / fAccCredit;

	return 0;
}