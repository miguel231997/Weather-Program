#include <fstream>
#include <iostream>
#include "matrix.h"

//default constructor - dynamically allocated 2d array
Matrix::Matrix(void) :numRows(MAXROWS), numCols(MAXCOLS)
{
	matrix = new Type*[numRows];
	for (int i = 0; i<numRows; i++)
		matrix[i] = new Type[numCols];
	for (int row = 0; row < numRows; row++) {

		for (int col = 0; col < numCols; col++) {
			matrix[row][col] = 0;
		}

	}
}

Matrix::Matrix(int r, int c) :numRows(r), numCols(c)
{
	matrix = new Type*[numRows];
	for (int i = 0; i<numRows; i++)
		matrix[i] = new Type[numCols];
	for (int row = 0; row < numRows; row++) {

		for (int col = 0; col < numCols; col++) {
			matrix[row][col] = 0;
		}

	}


}


//copy constructor
Matrix::Matrix(const Matrix &c){

	numRows = c.numRows;
	numCols = c.numCols;
	matrix = new Type*[numRows];
	for (int i = 0; i<numRows; i++)
		matrix[i] = new Type[numCols];



	for (int row = 0; row < numRows; row++) {

		for (int col = 0; col < numCols; col++) {
			matrix[row][col] = c.matrix[row][col];
		}

	}
}




void Matrix::read(const char * fileName) {

	fstream fileIn;

	fileIn.open(fileName);
	if (!fileIn.is_open()) {
		cerr << fileName << " is not open";
	}
	for (int row = 0; row < numRows; row++) {

		for (int col = 0; col < numCols; col++) {
			fileIn >> matrix[row][col];
		}

	}


}

void Matrix::read(fstream &fileIn) {

	if (!fileIn.is_open()) {
		cerr << " file is not open";
	}
	for (int row = 0; row < numRows; row++) {

		for (int col = 0; col < numCols; col++) {
			fileIn >> matrix[row][col];
		}

	}


}

Type Matrix::highestForRow(int r){
	Type highest = matrix[r][0];
	for (int col = 1; col < numCols; col++){
		if (matrix[r][col] > highest)
			highest = matrix[r][col];
	}
	return highest;
}



Type Matrix::sumRow(const int r)const{
	Type sum = 0;


	for (int col = 0; col < numCols; col++){
		sum += matrix[r - 1][col];
	}
	return sum;
}



float Matrix::avgRow(int r){
	Type sum = 0;
	//r--;
	for (int col = 0; col < numCols; col++){
		sum += matrix[r][col];
	}
	return sum / numCols;
}



Matrix Matrix::operator + (Matrix mat){
	Matrix *answer = new Matrix;
	for (int row = 0; row < numRows; row++) {

		for (int col = 0; col < numCols; col++) {
			answer->matrix[row][col] = matrix[row][col] + mat.matrix[row][col];
		}

	}
	//answer->print();
	return *answer;
}
const Matrix & Matrix::operator = (const Matrix & mat){

	for (int row = 0; row < numRows; row++) {

		for (int col = 0; col < numCols; col++) {
			matrix[row][col] = mat.matrix[row][col];
		}

	}

	return *this;


}

Type Matrix::get(int i, int j){
	return matrix[i][j];
}

void Matrix::set(int i, int j, Type value) {
	matrix[i][j] = value;
}

void Matrix::print(){
	for (int row = 0; row < numRows; row++) {

		for (int col = 0; col < numCols; col++) {
			cout << matrix[row][col] << " ";
		}
		cout << endl << endl;

	}
}


Matrix Matrix::operator * (Matrix & m){
	Matrix * result = new Matrix(numRows, m.numCols);

	// check if matricies can be multiplied
	if (numCols == m.numRows) {
		for (int i = 0; i<result->numRows; i++) {

			for (int j = 0; j<result->numCols; j++) {

				for (int k = 0; k<m.numRows; k++) {
					result->matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}

			}
		}
	}
	else {
		cout << ("Matrices cannot be multiplied!");
	}


	return *result;
}


Matrix::~Matrix(void)
{
	for (int row = 0; row < numRows; row++)
		delete[] matrix[row];
	delete[] matrix;
}


ostream& operator << (ostream& osObject,
	const Matrix& m)
{
	for (int row = 0; row < m.numRows; row++) {

		for (int col = 0; col < m.numCols; col++) {
			osObject << m.matrix[row][col] << " ";
		}
		osObject << endl << endl;

	}

	return osObject;
}

istream& operator >> (istream& isObject,
	Matrix& m)
{
	isObject >> m.numRows >> m.numCols;

	return isObject;
}

//Type Matrix::lowestForRow(int r){}
//Type Matrix::lowestForCol(int c){}

Type Matrix::highestForCol(int c){
	Type highest = matrix[0][c];
	for (int row = 1; row < numRows; row++){
		if (matrix[row][c] > highest)
			highest = matrix[row][c];
	}
	return highest;
}

float Matrix::avgCol(int c){
	Type sum = 0;
	//c--;
	for (int row = 0; row < numRows; row++){
		sum += matrix[row][c];
	}
	return sum / numRows;
}

Matrix Matrix::multiply(Matrix m){
	Matrix * result = new Matrix;

	result->matrix[0][0] = matrix[0][0] * m.matrix[0][0] +
		matrix[0][1] * m.matrix[1][0];
	result->matrix[0][1] = matrix[0][0] * m.matrix[0][1] +
		matrix[0][1] * m.matrix[1][1];
	result->matrix[1][0] = matrix[1][0] * m.matrix[0][0] +
		matrix[1][1] * m.matrix[1][0];
	result->matrix[1][1] = matrix[1][0] * m.matrix[0][1] +
		matrix[1][1] * m.matrix[1][1];

	return *result;
}


//Matrix::Matrix (int a, int b, int c, int d) {//set the values sent for 2X2
//	matrix = new Type*[2];
//	for (int i = 0; i<2; i++)
//		matrix[i] = new Type [2];
//	numRows =2;
//	numCols =2;
//
//	matrix[0][0] = a;
//	matrix[0][1] = b;
//	matrix[1][0] = c;
//	matrix[1][1] = d;
//}