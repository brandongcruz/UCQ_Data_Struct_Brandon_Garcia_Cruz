#pragma once

class RawArray 
{
public: 
	RawArray(int in_Size); 

	~RawArray(); 

	void Initial(int InitialValue = 0); 

	void Print(); 

	void Replace(int X, int Y);

	int* InitialElement; 

	int Size; 

};