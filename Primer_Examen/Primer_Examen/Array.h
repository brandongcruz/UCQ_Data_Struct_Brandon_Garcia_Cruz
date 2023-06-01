#pragma once
class RawArray
{
public:
	RawArray(int in_Size);

	~RawArray();

	void Initial(int InitialValue = 0);

	void Print();

	void Replace(int X, int Y);

	// A PARTIR DE AQUI SE DECLARARON LAS FUNCIONES PARA EL EXAMEN. 

	void AssignEveryXElements(int v, int x);

	void SortFunction();

	void AppendArray(RawArray arrayToAppend);

	void SetSize(int newSize);

	void Insert(RawArray arrayToInsert, int startIndex);

	void SumArrays(RawArray A, RawArray B);

	int GetIndexOf(int x);

	int GetLastOf(int x); 

	RawArray GetIndicesOf(int x);

	int* InitialElement;

	int Size;

};

