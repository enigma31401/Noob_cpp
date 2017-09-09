/************************
This code gives us the chi square, user can choose uniform expected values which are the mean, or custom expected values
coder:: Laniakea (Rogue Philosophy)
Chi square (good fitness) calculator  v.0.0.0 More updates to come soon..
************************/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

void showDataSet(float userSet[], int setSize); //Funct-PT, shows the data table
bool expectedValOption(); //Funct-PT, Gives us the indication for either a uniform or varied expected value(s), powered by bool
float getUniformExpValues(float userSet[], int setSize);//Funct-PT, Gives us expected value as the mean

/*************************************************
 *  Main funtion
 *
 * *********************************************/
int main() {

       int categorySize, //User determinant, sets size of the data table
	        expectedValue; //When the expected value is the mean, and constant or uniform
       bool expectedValDecider;//Logic mechanism to discern between uniform or varied expected value(s)
       float expectedValUniform; //For the expected value when uniform, is the mean(or average) of the data-set
       float chiSquare = 0.0; //Final value, the answer
       char resetOpt; //For the end when you choose to exit or start another statistic
       int degreeOfFreedom;

do {
        cout << "Enter data-set Size: "; //Prompt user to enter choice for expected values
		cin >> categorySize; //Input
        degreeOfFreedom = categorySize - 1;

       float observedValues[categorySize]; //For the observed values, the "real" values
       float expectedValues[categorySize]; //When the expected value varies, this array or set holds them. stat equation hypotheticals
       float algebraicFunctA[categorySize];//An array for the (obs-exp)^2
       float algebraicFunctB[categorySize]; //An array for the (obs-exp)^2/exp

 for(int i = 0; i < categorySize; i++){
      cout << "Enter element #" << i+1 << ": ";
      	cin >> observedValues[i];
 }

       showDataSet(observedValues, categorySize);
       expectedValDecider = expectedValOption();
                                                            //TEST-CODE cout << "expected val decider is " << expectedValDecider << endl;

      if(expectedValDecider == 0) {
             for(int d = 0; d < categorySize; d++) {
               cout << "Enter element #" << d+1 << ": ";
                  cin >> expectedValues[d];
             }
             for(int s = 0; s < categorySize; s++) {
                 algebraicFunctA[s] = pow(observedValues[s] - expectedValues[s], 2);
             }
             for(int n = 0; n < categorySize; n++) {
               algebraicFunctB[n] = algebraicFunctA[n]/expectedValues[n];
             }
             for(int a = 0; a < categorySize; a++) {
               chiSquare += algebraicFunctB[a];
             }
               cout << "Chi Square value calculated: " << chiSquare << endl;
}

      else if(expectedValDecider == 1) {
          expectedValUniform = getUniformExpValues(observedValues, categorySize);

               for(int g = 0; g < categorySize; g++) {
                 algebraicFunctA[g] = pow(observedValues[g] - expectedValUniform, 2);
               }
              for(int f = 0; f < categorySize; f++) {
                algebraicFunctB[f] = algebraicFunctA[f]/expectedValUniform;
              }
              for(int b = 0; b < categorySize; b++) {
                chiSquare += algebraicFunctB[b];
              }
                  cout << "Chi Square value calculated: " << chiSquare << endl;
}
     cout << "Degrees of Freedom: " << degreeOfFreedom << endl;

     cout << "Would you like to load another data set? (Y/N)";
        cin >> resetOpt;
}while(resetOpt == 'Y');

    return 0;
}

/*************************************************
 *  This function displays the data set
 *
 * *********************************************/
void showDataSet(float userSet[], int setSize) {

        for(int e = 0; e < setSize; e++){
                  cout << " |" << userSet[e] << "| ";
	}
          cout << endl;
}
/*************************************************
 *  This function gives us a bool powered answer that can be used
 *  in the main function to decide which expected values method to use.
 *  when Varied is chosen, a new array of respected expected values to the observed is created, else exp vals are uniform mean of init data set
 * *********************************************/
bool expectedValOption() {
  bool decider; //Logic mechanism
  string expectedVal_Choice; //User determinant, to set expected values as either uniform or varied

  do { //Do while to compensate for invalid input
  cout << "Is your expected value Uniform or Varied: ";
    cin >> expectedVal_Choice;

     if(!(expectedVal_Choice == "Uniform" || expectedVal_Choice == "Varied")) { // Logic (!()) means, (Not (Z=A or Z=B))
       cout << endl << "Error, invalid input, try again!" << endl;
     }

   }while(!(expectedVal_Choice == "Uniform" || expectedVal_Choice == "Varied"));

         if(expectedVal_Choice == "Uniform") {
               decider = true; //bool decider set to 1
         }
         else if(expectedVal_Choice == "Varied") {
              decider = false; //bool decider set to 0
         }

                                          //TEST-CODE: cout << "decider is: " << decider;
  return decider;
}
/*************************************************
 *  This function gets the uniform mean
 *
 * *********************************************/
float getUniformExpValues(float userSet[], int setSize) {
      float summation = 0,
                  average;

              for(int y = 0; y < setSize; y++) {
                summation += userSet[y];
              }
                      average = summation/setSize;
  return average;
}
