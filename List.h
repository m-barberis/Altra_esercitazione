#ifndef LIST_H
#define LIST_H

#include "CQuadrilateral.h"
#include <iostream>
#define DIM 100

class List
{
protected:
	Quadrilateral* quadList[DIM];

public:
	List();
	List(List& l);
	~List();
	int AddShape(Quadrilateral* quad);
	void RmShape(int index);
	void ViewShape(int index);
	void ViewAll();
	void Init();
	void Init(List& l);
	void Reset();
};

#endif // !LIST_H

