#include<iostream>

using namespace std;

int main(int argc, const char * argv[]) 
{
    int maxx=0;
	cout << "Number of command-line arguments: " << argc << endl;
	for (int i = 0; i < argc; i++) {
        if(*argv[i] > maxx) maxx = *argv[i];
		cout << "Argument #" << i << ": _" << argv[i] << "_\n";
	}
    for(int i=0; i<maxx; i++){
        cout<<i<<endl;
    }
	return 0;
}
