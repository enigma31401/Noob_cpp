/* * * * * * * *
 *  Coder: Laniakea
 *  This gives the tcalculated and degree of freedom when variances are either equal or unequal
 * * * * * * * */
#include "tMaster.h"

int main() {
    char choice;
    char cont;

 do{   
    std:: cout << "Are the variances equal or unequal< (Perform a preliminary Ftest): E/U ";
	std:: cin >> choice;

  if(choice == 'E') {
	equalVars();

   }

  else if(choice == 'U') {
        unequalVars();
  }

  else if(!(choice == 'E') && !(choice =='U')) {
	  std:: cout << "Error, invalid char supported! Try again!" << std:: endl;
  }

    std:: cout << "Would you like to try another analysis?(y/n): ";
    	std:: cin >> cont;

 }while(cont == 'y');

}

