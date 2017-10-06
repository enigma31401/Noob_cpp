/**************************
 *  Coder: Laniakea
 *  Notes:
 *        Yeah this isn't very clean, but it will get the job done.
 * **********************/
#include <iostream>
#include <math.h>

double getEleSummation(int size, double seta[], double setb[], double setc[]);//Function Prototype, for getting the Σx value

double getSquaredElements(int size, double seta[], double setb[], double setc[]);//Funct-PT, for getting the Σx^2 value

double getSSbValue(double setaTot, double setbTot, double setcTot, int size, int fullSet, double eleSums);//Funct-PT for the SSb value in step 5 of Ambrose book 

int main() {
     
     int setSizes; //User determinant, because is assumed utilized in a scientific setting, assume that all sets are a uniform or equal size.

     std:: cout << "Enter the sizes of the sets: ";
     	std:: cin >> setSizes;

     //-------------------------Data Sets-----------//
       double setA[setSizes];  
       double setB[setSizes];
       double setC[setSizes];
    //----------------------------------------------//
    //Additional -----------------------------------//
       int summatedSet = setSizes + setSizes + setSizes; //(the N value)
       double sumOfSquaresTotal; //Initialized further down


   //---------------------------------------------//
                //---------------------------setting values------//
		  std:: cout << "Group 1 Values: \n";
		    for(int a = 0; a < setSizes; a++) {
                         std:: cout << "Enter the #" << a+1 << " element: ";
			 	std:: cin >> setA[a];
		    }
                 std:: cout << "Group 2 Values: \n";
		    for(int b = 0; b < setSizes; b++) { 
                         std:: cout << "Enter the #" << b+1 << " element: ";
			 	std:: cin >> setB[b];
		    }
                 std:: cout << "Group 3 Values: \n";
		    for(int c = 0; c < setSizes; c++) {
                         std:: cout << "Enter the #" << c+1 << " element:";
			 	std:: cin >> setC[c];
		    }
               //----------------------------------------------//
          double elementSums; //(The Σx value)
              elementSums = getEleSummation(setSizes, setA, setB, setC);
	           std:: cout << "Total, Σx value is " << elementSums << std:: endl;
          double SquaredElements; //(The Σx^2 value)
	      SquaredElements = getSquaredElements(setSizes, setA, setB, setC);
	           std:: cout << "Total, Σx^2 value is " << SquaredElements << std:: endl;

	sumOfSquaresTotal = SquaredElements - (pow(elementSums,2)/summatedSet); //(The SSt value)

    //--------Calculating the mean, the Σx, and the sample size of each individual set----//
       double setaTotal = 0.0, setbTotal = 0.0, setcTotal = 0.0;//The summations
       double setaMean, setbMean, setcMean; //The means
       
              for(int r = 0; r < setSizes; r++) {
                        setaTotal += setA[r];              
		 }
                  setaMean = setaTotal/setSizes;

	      for(int t = 0; t < setSizes; t++) {
                       setbTotal += setB[t];
	      }
                 setbMean = setbTotal/setSizes;

	      for(int v = 0; v < setSizes; v++) {
                       setcTotal += setC[v];
	      }
	        setcMean = setcTotal/setSizes;
   //------------------------------------------------------------------------------------//

		double TreatmentFunct; //(The SSb value);
		        TreatmentFunct = getSSbValue(setaTotal, setbTotal, setcTotal, setSizes, summatedSet, elementSums);

               double SSwValue;
	            SSwValue = sumOfSquaresTotal - TreatmentFunct; //(The SSw value)
              
		    double Vb, Vw, Fcalc; 
		        Vb = TreatmentFunct/3-1;  // the denominator is the amount of groups minus 1, which is 3-1
			Vw = SSwValue/summatedSet-3;
				Fcalc = Vb/Vw;

			//----Solution part----//
			std:: cout << "\n\n\n";
			std:: cout << "The SSt value: " << sumOfSquaresTotal << std:: endl;
			std:: cout << "The SSb value: " << TreatmentFunct << std:: endl;
		        std:: cout << "The SSw value: " << SSwValue << std:: endl;
		        std:: cout << "The Vb value: " << Vb << std:: endl;
		        std:: cout << "The Vw value: " << Vw << std:: endl;
		        std:: cout << "The Fcalc value: " << Fcalc << std:: endl;
			//---Additional Solutions---//
			double aMean, bMean, cMean;
			 
			   aMean = setaTotal/setSizes;
			   bMean = setbTotal/setSizes;
			   cMean = setcTotal/setSizes;

			        std:: cout << "Group 1 mean: " << aMean << "\nGroup 1 size: " << setSizes  << std:: endl;
				std:: cout << "Group 2 mean: " << bMean << "\nGroup 2 size: " << setSizes << std:: endl;
				std:: cout << "Group 3 mean: " << cMean << "\nGroup 3 size: " << setSizes << std:: endl;


		       //--------//	
			std:: cout << "\n\nThe  DoF is (2," << summatedSet-3 << ")" << std:: endl; 
}
/*************************
 *  This function gets the Σx value
 * **********************/
double getEleSummation(int size, double seta[], double setb[], double setc[]) {

	double total_elements = 0.0; //Zeroing out initially so it clears any chance of the compiler using memory address as #
	     for(int x = 0; x < size; x++) {
                     total_elements += seta[x] + setb[x] + setc[x];
	     }
                  return total_elements;
}

/*******
 * This function gets the Σx^2 value
 * *************/
double getSquaredElements(int size, double seta[], double setb[], double setc[]) {

	double total_elementsSquared = 0.0; //Zeroing out initially so it clears any chance of the compiler using memory address as #
	     for(int y = 0; y < size; y++) {
                     total_elementsSquared += pow(seta[y],2) + pow(setb[y],2) + pow(setc[y],2);
	     } //Straight from Ambrose format
                  return total_elementsSquared;

}

/*********
 *  Get SSb value
 * ****/
double getSSbValue(double setaTot, double setbTot, double setcTot, int size, int fullSet, double eleSums) {
       double targetValue;
            targetValue = (pow(setaTot,2)/size + pow(setbTot,2)/size + pow(setcTot,2)/size) - pow(eleSums,2)/fullSet;
//Straight from Ambrose format 
	    return targetValue;
    
}
