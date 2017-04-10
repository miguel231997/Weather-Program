#pragma once
using namespace std;
typedef float Type;

class Matrix
{
public:
	//defaults
	static const int MAXROWS = 2;
	static const int MAXCOLS = 2;
	//Overload the stream insertion and extraction operators
	friend ostream& operator << (ostream&, const Matrix &);
	friend istream& operator >> (istream&, Matrix &);
	Matrix(void);
	Matrix(int, int);
	Matrix(const Matrix & c);

	void read(const char * fileName);
	void read(fstream &fileIn);
	Type sumRow(const int r)const;
	float avgCol(int c);
	float avgRow(int r);
	Type highestForRow(int r);
	Type highestForCol(int c);
	//Type lowestForRow(int r);
	//Type lowestForCol(int c);
	Matrix operator + (Matrix mat);
	Matrix operator * (Matrix & m);
	const Matrix & operator = (const Matrix & mat);
	Type & operator () (int, int);
	Type get(int, int);
	void set(int, int, Type);
	void print();

	Matrix  multiply(Matrix m);
	~Matrix(void);
private:
	int numRows;
	int numCols;
	Type ** matrix;							//dynamically allocated

};
