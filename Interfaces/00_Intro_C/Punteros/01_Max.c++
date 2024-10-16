#include <iostream>

using namespace std;

void incrementar (int *p) {
	*p = *p + 1;
}

int *maximo (int *i, int *j) {
	if ( *i > *j ) return i;
	else return j;

}





int main (int argc, char *argv[]) {

	int i = 8;
	int j = 9;
	
	int *max;
	max = maximo(&i, &j);
	(*max)++;
	
	//i debe valer 8
	//j debe valer 10

	cout << "i vale: " << i << endl;
	cout << "j vale: " << j << endl;
	//cout << "max vale: " << max << endl;


}
