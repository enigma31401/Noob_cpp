/********************************
This code gives us the mean only.
coder:: Laniakea (Rogue Philosophy)

Basic Stats calculator  v.0.0.0
********************************/
#include <iostream> //For cin cout functionality
#include <iomanip> //For rounding, not in v.0.0.0 but will be in v.0.0.1
#include <cmath> //For algebraic functions

using namespace std;

      struct multipleParams {
          float mean;
          float summationPart;
          float varianceFinal; //Really tailored for the function for variance, but can be pooled to alternative blocs
          float standardDevi;
      };

//A bit of function overloading here? At least in the data being placeholded and mirrored?
float arrayMean(float showSet[], int size); //Function prototype
float arrayVarianceA(float showSet[], int size, float avg);//Function prototype
float arrayVarianceB(float summatedVal, int setSize);//Function to finish the variance and standard deviation (of a sample)
float arrayVarianceC(float summatedValALT, int SetSizeALT);//Function is the standard dev is a population
float standardDev(float importVariance);//Function to get the standard deviation

int main() {

multipleParams p;
   int x; // Will be the variable to determine the size of the array
   float mySet[x]; //Declaring the array
   float average; //Self explainatory, but will be using data here and within an outside function

   char initiatorChar;
do {
    cout << "Enter array size: ";
      cin >> x; //Giving size to the array

                            //This forloop gives us the scalable inputs to the values of the elements in the set/array
                        for(int n = 0; n < x; n++) {             //n+1 to give the illusion of alignment starting w/ 1 instead of zero
                              cout << "Enter the value of the " << n+1 << "th element: ";
                                cin >> mySet[n];
                        }

        p.mean  = arrayMean(mySet, x); //To get the mean/average (not mathematical but grammatic synonymity)
        average = p.mean; //Works mechanistically here. To ascertain a fixed average value you must do it. p.mean here only applies in this function so it's safe too.
          cout << endl << "The mean or average is: " << p.mean << endl;


          p.varianceFinal = arrayVarianceA(mySet, x, average);
          cout << "The Variance value is : " << p.varianceFinal << endl;
          p.standardDevi = standardDev(p.varianceFinal);

          cout << "The standard deviation is: " << p.standardDevi << endl;

          cout << "\n\n\n\n\nWould you like to load another calculation?(y/n) _";
            cin >> initiatorChar;
        } while(initiatorChar == 'y');

    return 0;
}
/********************************
This function: Gives us the average
********************************/
float arrayMean(float showSet[], int size) {
    float summation = 0,
               mean = 0;

      for(int i = 0; i < size; i++){
          cout << showSet[i] << endl << "This is the " << i+1 << "# element.\n";

                summation += showSet[i]; //This is really the summation here at this state

      }
            mean = summation/size;


      //cout << "The mean is: " << mean << endl; //The summation formulaically turned into mean

      return mean;
}
/********************************
This function: Gives us the variance, with help from another function
   Two step away from deducing the stnd dev in the main()
********************************/

float arrayVarianceA(float showSet[], int size, float avg) {
            multipleParams mp; //Pooling to struct

  int minusSize = size-1;
  float VarianceValue,
     summationSBJ = 0;
     float sampleSpecial = summationSBJ/minusSize;
  char choiceChar;

  cout << "Are you working with a population or sample(s/p): "; //Samp
    cin >> choiceChar;

          if(choiceChar == 's') { //So this represents and gives the option when it's the standard deviation of a sample
                 for(int c = 0; c < size; c++) {
                   cout << "testing value identity: " << showSet[c] << " and avg: " << avg << endl;
                    summationSBJ += pow((showSet[c] - avg),2); // Is the http://imgur.com/a/kfYPG part
                      cout << summationSBJ << "  is the summation part value  in finding the variance" << endl;
                 }

                  VarianceValue = arrayVarianceB(summationSBJ, minusSize);
}
          else  if(choiceChar == 'p'){
            for(int c = 0; c < size; c++) {
              cout << "testing value identity: " << showSet[c] << " and avg: " << avg << endl;
               summationSBJ += pow((showSet[c] - avg),2); // Is the (summations) http://imgur.com/a/kfYPG part
                 cout << summationSBJ << "  is the summation part value  in finding the variance" << endl;
            }
                  VarianceValue = arrayVarianceC(summationSBJ, size);
          }


  return VarianceValue;
}
/********************************
This function: Gives us the variance
  And just a single step away from deducing the stnd dev in the main()
********************************/
float arrayVarianceB(float summatedVal, int minusSetSize) {

  float theVariance;

      theVariance = summatedVal/minusSetSize;

  return theVariance;
}

/********************************
This function: Gives us the variance for a population
  And just a single step away from deducing the stnd dev in the main()
********************************/
float arrayVarianceC(float summatedValALT, int SetSizeALT) {

  float theVarianceALT;

      theVarianceALT = summatedValALT/SetSizeALT;

  return theVarianceALT;
}

/********************************
This function: Gives us the standard deviation
   No steps away from the standard deviation, for this is the function to give it!
********************************/
float standardDev(float importVariance) {
  float stndDev;

    stndDev = sqrt(importVariance);

  return stndDev;
}
