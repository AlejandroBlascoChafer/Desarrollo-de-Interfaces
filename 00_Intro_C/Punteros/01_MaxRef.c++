#include <iostream>

using namespace std;

void incrementar (int *p) {
	*p = *p + 1;
}

int &maximo (int &uno, int &otro) {

	if ( uno > otro ) return uno;
	
	return otro;

}





int main (int argc, char *argv[]) {

	int i = 8;
	int j = 9;
	
	int &max = maximo(i, j);
	max++;
	
	//i debe valer 8
	//j debe valer 10

	cout << "i vale: " << i << endl;
	cout << "j vale: " << j << endl;
	//cout << "max vale: " << max << endl;


}
