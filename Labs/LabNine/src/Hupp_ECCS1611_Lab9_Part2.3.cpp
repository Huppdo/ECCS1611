//Dominic Hupp - ECCS1611 - 10/22/20
//Combines two vectors

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b);

int main(){
	vector<int> vectorA{ 1, 4, 9, 16 };
	cout << "Vector A: ";
	for (int i = 0; i < vectorA.size(); i++) {
		cout << vectorA[i] << " ";
	}
	cout << endl;

	vector<int> vectorB{ 9, 7, 4, 9, 11 };
	cout << "Vector B: ";
	for (int i = 0; i < vectorB.size(); i++) {
		cout << vectorB[i] << " ";
	}
	cout << endl;

	vector<int> finalVector = append(vectorA, vectorB);
	cout << "  Output: ";
	for (int i = 0; i < finalVector.size(); i++) {
		cout << finalVector[i] << " ";
	}
}

vector<int> append(vector<int> a, vector<int> b) {
	vector<int> returnVect;
	for (int i = 0; i < a.size(); i++) {
		returnVect.push_back(a[i]);
	}
	for (int i = 0; i < b.size(); i++) {
		returnVect.push_back(b[i]);
	}
	return returnVect;
}