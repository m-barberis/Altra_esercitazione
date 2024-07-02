#include<iostream>

#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "List.h"

const int LISTL=100; 

Quadrilateral* quadList[LISTL];
void menu();

void Show() {
	cout << endl;
	cout << "\t\t*** Show function ***" << endl;
	cout << endl;
	int i; 
	
	for (i=0; i<LISTL; i++)
		if (quadList[i] != NULL)
		{
			cout << "Quadrilateral number " << i << ":" << endl;
			quadList[i]->Drawing();
		}
	cout << endl;
	cout << endl;
	
}


int main() {


	Format f1, f2;
	
	f1.fill = r;
	f1.outline = b; 
	f2.fill = g;
	f2.outline = w;
/*
	Rectangle rectA(10,5);
	Rectangle rectB(3,7,f1);
	Rectangle rectC = rectA;

	Rhombus rhoA(6,2,f2);
	Rhombus rhoB = rhoA;
	Rhombus rhoC(4,3);
		
	quadList[0]= &rectA;
	quadList[1]= &rectB;
	quadList[2]= &rectC;
	quadList[3]= &rhoA;
	quadList[4]= &rhoB;
	quadList[5]= &rhoC;

	Show();
	
	rectA.SetFill(g);
	rhoC.SetOutline(r);
	rhoA=rhoC;
	rectB.SetFormat(f2);
	
	Show();

*/
	List list;

/*
	Quadrilateral* q = new Rectangle(2, 4);
	list.AddShape(q);
	list.ViewAll();
	Quadrilateral* p = new Rhombus(3, 1, f2);
	list.AddShape(p);
	list.ViewAll();
	list.RmShape(0);
	list.ViewAll();
*/
	menu();
	int choice = 0;
	int choice2 = 0;
	int width = 0;
	int height = 0;
	int diagL = 0;
	int diagS = 0;
	Quadrilateral* quadPtr = NULL;
	do
	{
		cout << endl;
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			cout << "Inserisci larghezza: ";
			scanf_s("%d", &width);
			cout << endl;
			cout << "Inserisci altezza: ";
			scanf_s("%d", &height);
			cout << endl;
			quadPtr = new Rectangle(width, height);
			list.AddShape(quadPtr);
			break;
		case 2:
			cout << "Inserisci diagonale min: ";
			scanf_s("%d", &diagL);
			cout << endl;
			cout << "Inserisci diagonale mag: ";
			scanf_s("%d", &diagS);
			cout << endl;
			quadPtr = new Rhombus(diagL, diagS);
			list.AddShape(quadPtr);
			break;
		case 3:
			list.ViewAll();
			cout << "Quale forma vuoi rimuovere?" << endl;
			cout << "Inserisci il numero:" << endl;
			scanf_s("%d", &choice2);
			list.RmShape(choice2);
			break;
		case 4:
			list.ViewAll();
			break;
		case 5:
			cout << "Quale forma vuoi visualizzare?" << endl;
			cout << "Inserisci il numero:" << endl;
			scanf_s("%d", &choice2);
			list.ViewShape(choice2);
			break;
		case 6:
			cout << endl;
			cout << "TERMINO IL PROGRAMMA" << endl;
			break;
		default:
			cout << endl;
			cout << "WARNING: input non valido" << endl;
			menu();
			break;
		}
	} while (choice != 6);
	return 0;

}

void menu()
{
	cout << endl;
	cout << "\t\t\t**** MENU INTERATTIVO ****" << endl;
	cout << endl;
	cout << "COMANDI: " << endl;
	cout << endl;
	cout << "- Premi 1 per aggiungere un RETTANGOLO" << endl;
	cout << "- Premi 2 per aggiungere un ROMBO" << endl;
	cout << "- Premi 3 per rimuovere una forma dalla lista" << endl;
	cout << "- Premi 4 per visualizzare tutte le forme" << endl;
	cout << "- Premi 5 per visualizzare una forma" << endl;
	cout << "- Premi 6 per uscire dal programma" << endl;
	cout << endl;
}