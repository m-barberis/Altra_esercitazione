#include "List.h"

List::List() 
{
	cout << "List - constructor - default" << endl;
	Init();
}

List::List(List& l)
{
	cout << "List - constructor" << endl;
	Reset();
	Init(l);
}

List::~List()
{
	cout << "List - destructor" << endl;
	Reset();
}

int List::AddShape(Quadrilateral* quad)
{
	for (int i = 0; i < DIM; i++) {
		if (quadList[i] == NULL)
		{
			cout << endl;
			cout << "AddShape: ADDING SHAPE NUMBER " << i << endl;
			cout << endl;
			quadList[i] = quad;
			return 0;
		}
	}
	cout << "NO ROOM AVAILABLE!" << endl;
	return 1;
}

void List::RmShape(int index)
{
	if (quadList[index] != NULL)
	{
		cout << endl;
		cout << "RmShape: REMOVING SHAPE NUMBER " << index << endl;
		cout << endl;
		delete quadList[index];
		quadList[index] = NULL;
	}
	else
	{
		cout << "RmShape: NO SHAPE TO REMOVE" << endl;
	}
}

void List::ViewShape(int index)
{
	if (quadList[index] != NULL)
	{
		cout << "ViewShape: DRAWING SHAPE NUMBER " << index << ":" << endl;
		quadList[index]->Drawing();
	}
	else
		cout << "ViewShape: NO SHAPE TO VIEW" << endl;
}

void List::ViewAll()
{
	cout << endl;
	cout << "\t\t *** ViewAll: DRAWING EVERY SHAPE ***" << endl;
	cout << endl;
	for (int i = 0; i < DIM; i++) {
		ViewShape(i);
	}
	cout << endl;
	cout << "\t\t\t\t ******" << endl;
	cout << endl;
}

void List::Init()
{
	
	for (int i = 0; i < DIM; i++) {
		quadList[i] = NULL;
	}
}

void List::Init(List& l)
{
	Reset();
}

void List::Reset()
{
	for (int i = 0; i < DIM; i++) {
		delete quadList[i];
		quadList[i] = NULL;
	}
}