#include <iostream>
#include "regexp.h"

using namespace std;


int main(){
    char *text = "aabbccddee";
    char *reg                 = "fe$";
    regexp re;
	cout << re.match(reg, text) << endl;

	return 0;
}