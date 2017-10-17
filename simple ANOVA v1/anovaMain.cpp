/*coder: Laniakea/RoguePhilosophy*/
#include "anovaMaster.h" //As seen in anovaFunct.cpp this is necessary in linking to a common header w/ functs and clsses and preprocessors directive. Intergral part of multipart programming.

//Note: return 0; at the end of function not needed in modern cpp programming





int main() {
	int groupNum;


do{
  std:: cout << "Enter the amount of groups(treatments|sets): ";
    std:: cin >> groupNum;
        if(!(groupNum == 3) && !(groupNum == 4)) {
              std:: cout << "Error, quantity not supported! Please try again!\n";
	      std:: cout << "The program only supports set quantities of 3 or 4 as of now.\n";
	}
}while(!(groupNum == 3) && !(groupNum == 4));

  if(groupNum == 3) {
     sizeThree();
  }
  else if(groupNum ==4) {
   sizeFour();
  }




}
