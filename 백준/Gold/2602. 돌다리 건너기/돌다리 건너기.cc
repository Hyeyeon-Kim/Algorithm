#include <iostream>
#include <string>
using namespace std;

int main(){
	string magic, devil, angel;

	cin >> magic >> devil >> angel;

	int dpdevil[22][102] = {0};
	int dpangel[22][102] = {0};

	for (int j = 0; j <= devil.size(); j++){
		dpangel[0][j] = 1;
		dpdevil[0][j] = 1;
	}

	for (int i = 1 ; i <= magic.size(); i++){
		for (int j = 1; j <= devil.size(); j++){
			dpdevil[i][j] = dpdevil[i][j-1];
			if (magic[i-1] == devil[j-1])
				dpdevil[i][j] += dpangel[i-1][j-1];
			
			dpangel[i][j] = dpangel[i][j-1];
			if (magic[i-1] == angel[j-1])
				dpangel[i][j] += dpdevil[i-1][j-1];
		}
	}

	// for (int i = 1 ; i <= magic.size(); i++){
	// 	for (int j = 1; j <= devil.size(); j++){
	// 		cout << dpdevil[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	// for (int i = 1 ; i <= magic.size(); i++){
	// 	for (int j = 1; j <= devil.size(); j++){
	// 		cout << dpangel[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dpdevil[magic.size()][devil.size()] + dpangel[magic.size()][devil.size()];
}