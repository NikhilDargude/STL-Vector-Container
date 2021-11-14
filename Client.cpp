#include"Server.h"


template<class T>
void MyMain(T);

int main(void)
{
	
	int iBool = 1;
	int iChoice;

	while(iBool)
	{
		cout << "\n1-:int\n2-:char\n3-:sing Precision floating Point(flolat)\n4-:Double Precision floating Point(double)\n5-:exit" <<endl;
		cout << "\nwhich type of linked list do you want-:\t";
		cin >> iChoice;

		if(iChoice <= 0 || iChoice >= 6)
		{
			cout << "\nInvalid Choice Enter Valid Choice " << endl;
			iChoice = 0;
		}


		switch(iChoice)
		{

		case 1 :
			MyMain(10);
			break;

		case 2 :
			MyMain('S');
			break;

		case 3 :
			MyMain(65.00f);
			break;

		case 4 :
			MyMain(60.00);
			break;

		case 5 :
			iBool = 0;
			break;
		}

	}
	return 0;
}

template<class T>
void MyMain(T)
{
	//an int vector of 10 elements
	Vector<T> intV(10);

	for(size_t iNo = 0; iNo < intV.Size(); iNo++)
		intV[iNo] = iNo; // Fill Vector Randam accesss

	// Vector increase an demand
	intV.insert(intV.end(), 100); // add end the number 100

	//// Use as array
	//for(size_t iNo = 0; iNo < intV.Size(); iNo++) kadaly heee
	//	cout << intV[iNo] << ' ';

	
	// Use as iterator
	for(Vector<T> :: iterator I = intV.Begin(); I != intV.end(); ++I)
		cout << *I <<' ' ;

/****************************************************************************************************/
	cout << endl << endl;

	// Use as iterator
	for(Vector<T> :: iterator I = intV.Begin(); I != intV.end(); ++I)
		cout << *I <<' ' ;

	cout << endl << endl;

	Vector<T> newV(20); // all elements are 0

	//cout << "newV = ";
	//for(size_t  iNo = 0; iNo < newV.Size(); ++iNo)
	//	cout << newV[iNo] << ' ';
		for(Vector<T> :: iterator I = intV.Begin(); I != intV.end(); ++I)
		cout << *I <<' ' ;

	// Swapping two Vectors
	newV.Swap(intV);

	cout << "\nnewV after Swapping = ";
	for(size_t iNo = 0; iNo < newV.Size(); ++iNo)
		cout << newV[iNo] << ' '; // old element of intV

	cout << "\nintV after Swapping =";
	for(size_t iNo = 0; iNo < intV.Size(); ++iNo)
		cout << intV[iNo] << ' '; // old element of newV

	cout << "\n\nintV = ";
	cout << intV;

	cout << "\n\nnewV = ";
	cout << newV;

	cout << endl;
}