#include <iostream>
using namespace std;

void incrementa (int &num) {
	num++;

}
int main (int argc, char *argv[]){

	int i;
	i=8;
	
	int &j = i;
	incrementa(i);
	cout << "i vale " << i << endl;





}
