#ifndef _VECTOR_H
#define _VECTOR_H

#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;


template<class T>
class Vector
{
	int iSize;
	T* pPtr;

public:
	// Constructor
	Vector();
	~Vector();
	Vector(int);

	int Size();
	void Swap(Vector&);

	T& operator [](int);

	template<typename T>
	friend ostream& operator <<(ostream& out, Vector<T>&);


	class iterator
	{
		int iCurrentIndex;
		T* iPtr;
	public:
		void SetCurrentIndex(int, T*);
		int GetCurrentIndex();

		T operator*();
		iterator& operator++();
		bool operator!=(iterator&);

	};

private:
	iterator Start;
	iterator End;

public:
	iterator& Begin();
	iterator& end();

	void insert(iterator&, T);
};

template<typename T>
Vector<T>::Vector()
{
	iSize = 0;
	pPtr = NULL;
};

template<typename T>
Vector<T>::Vector(int iNum)
{
	pPtr = new T[iNum];

	if (pPtr == NULL)
		cout << " Memory allocation faild \n";

	iSize = iNum;

	memset(pPtr, 0, sizeof(T) * iNum);

	//for(int iNo = 0; iNo < iNum; iNo++)
	//	pPtr[iNo] = 0;
};

template<typename T>
Vector<T>::~Vector()
{
	iSize = 0;
	if (pPtr != NULL)
		delete[]pPtr;

	pPtr = NULL;
};

template<typename T>
typename Vector<T>::iterator& Vector<T>::iterator::operator++()
{
	iCurrentIndex = iCurrentIndex + 1;

	return *this;
};

template<typename T>
bool Vector<T>::iterator::operator!=(iterator& RefObj)
{
	if (iCurrentIndex != RefObj.iCurrentIndex)
		return true;
	else
		return false;
};

template<typename T>
T Vector<T>::iterator::operator*()
{
	return iPtr[iCurrentIndex];
};

template<typename T>
T& Vector<T>::operator[](int iNum)
{
	return pPtr[iNum];
};

template<typename T>
int Vector<T>::Size()
{
	return iSize;
};

template<typename T>
typename Vector<T>::iterator& Vector<T>::end()
{
	Start.SetCurrentIndex(iSize, pPtr);

	return Start;
};

template<typename T>
typename Vector<T>::iterator& Vector<T>::Begin()
{
	Start.SetCurrentIndex(0, pPtr);

	return Start;
};

template<typename T>
void Vector<T>::iterator::SetCurrentIndex(int iIndex, T* pPtr)
{
	iCurrentIndex = iIndex;
	iPtr = pPtr;
};

template<typename T>
int Vector<T>::iterator::GetCurrentIndex()
{
	return iCurrentIndex;
};


template<typename T>
void Vector<T>::insert(iterator& LastIndex, T iValue)
{
	T* pTemp = NULL;
	int iTemp;
	int iNo1 = 0;

	iTemp = LastIndex.GetCurrentIndex();

	iSize++;

	pTemp = new T[iSize];
	if (NULL == pTemp)
	{
		cout << " memory Allocation Faild";
		return;
	}

	for (int iNo = 0; iNo < iSize; iNo++, iNo1++)
	{
		if (iTemp == iNo)
		{
			pTemp[iNo1] = iValue;
			iNo1++;
		}

		pTemp[iNo1] = pPtr[iNo];
	}

	delete pPtr;
	pPtr = pTemp;

};

template<typename T>
void Vector<T>::Swap(Vector<T>& intv)
{
	T* pTemp = NULL;
	int iTemp;

	pTemp = intv.pPtr;
	iTemp = intv.iSize;

	intv.pPtr = this->pPtr;
	intv.iSize = this->iSize;

	this->pPtr = pTemp;
	this->iSize = iTemp;

	pTemp = NULL;
	iTemp = 0;
};

template<typename T>
ostream& operator << (ostream& out, Vector<T>& refObj)
{
	int iNo = 0;

	if (refObj.pPtr != NULL)
		for (iNo; iNo < refObj.iSize; iNo++)
			out << refObj.pPtr[iNo] << ' ';

	return out;
}

#endif