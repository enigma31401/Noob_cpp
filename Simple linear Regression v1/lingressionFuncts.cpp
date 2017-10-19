#include "linrMaster.h"
//----------------------------------------Class genData START ----------------------------------------------------------------------//


//Constructors |===============================================================================================

   /* * * * * * * * * * * * * * * 
    * Constructor-pass, to create the initial passing of size into the data cluster that is class genData
    * * * * * * * * * * * * * * */

       genData :: genData(int size) {
              sizeOfSets = size;
       }


//Setters |===================================================================================================

    
   /* * * * * * * * * * * * * *
    * This function gives us the summation of the x-set(x values) or x-array
    * * * * * * * * * * * * * */
double genData ::  setX_sum(double xSetA[], int size) {
	        
      	double sumX = 0.0;

        for(int x = 0; x < size; x++) {
		sumX += xSetA[x];  
	}

	      setX_summation = sumX;
}

   /* * * * * * * * * * * *
    * This function gives us the summation of the y-set(y values) or y-array
    * * * * * * * * * * * */
double genData :: setY_sum(double ySetA[], int size) {
	double sumY = 0.0;

        for(int u = 0; u < size; u++) {
                sumY += ySetA[u];
	}
	      setY_summation = sumY;
}


   /* * * * * * * * * * * *
    *This function gives us the summation of squared x values 
    * * * * * * * * * * * */
double genData :: setXvalues_sqrd(double xSetB[], int size) {
	double sumXsqr = 0.0;
			   		 
	for(int f = 0; f < size; f++) {
	        sumXsqr += pow(xSetB[f], 2);    
	}

	      setXsum_squared = sumXsqr;
}

   /* * * * * * * * * * * *
    * This function gives us the summation of squared y values
    * * * * * * * * * * * */
double genData :: setYvalues_sqrd(double ySetB[], int size) {
	double sumYsqr = 0.0;

	for(int u = 0; u < size; u++) {
		sumYsqr += pow(ySetB[u], 2);
	}

	      setYsum_squared = sumYsqr;
}

   /* * * * * * * * * * * * * 
    * This is mean of x values (NOT squared)
    * * * * * * * * * * * * */
double genData :: setXmeans(double setAsum, int size) {
	double Aset_mean; //repping set x, associative proxy(logic)
	       Aset_mean = setAsum/size;
	       setX_mean = Aset_mean;
}

   /* * * * * * * * * * * 
    * This is the mean of y values (Not squared)
    * * * * * * * * * * */
double genData :: setYmeans(double setBsum, int size) {
	double Bset_mean; //repping set y, associative proxy(logic)
	       Bset_mean = setBsum/size;
	       setY_mean = Bset_mean;
}

   /* * * * * * * * * * * *
    * This is the summation of the product of respected x,y values starting from [0]* [0] to [max]*[max]
    * * * * * * * * * * * */
double genData :: setthe_SetProduct(double setOne[], double setTwo[], int size) {
        double setProductSum = 0.0;

	for(int m = 0; m < size; m++) {
            setProductSum +=  setOne[m]*setTwo[m];
	}
	   setProduct = setProductSum; 

            n_setSizeSums = size+size;	   
}

double genData :: seta(double b_val) {
         double gettingA;
	   gettingA = setY_mean - b_val*setX_mean;

	   A_value = gettingA;
}


//getters
           double genData :: getXYadditive_product() {
                 return setProduct;   
	   }
           
           double genData :: getTotalSize() {
                return n_setSizeSums;
	   }
          
           double genData :: displaySlope(double b_num) {
		   std:: cout << "Y = " << A_value << " + " << b_num  << "X" << std:: endl;
	   }
                  
	   
//Others







  /* * * * * * * * * *
   * Gets the b value(see page 74 in Ambrose biostats book)
   * * * * * * * * * */
double getB_value(double summationXY, double summationX, double summationY, double summationXsqrd, int volume) {
            double  bNumerator = summationXY - (summationX*summationY/volume);
	    double bDenominator = summationXsqrd -(pow(summationX,2)/volume);
	    double bTrue_value = bNumerator/bDenominator;

	      return bTrue_value;
}

double getSSt_value(double summationYsqrd, double summationY, int volume) {
            double SSt_value = summationYsqrd - (pow(summationY, 2)/volume);
	       
	      return SSt_value;
}

double getSSr_value(double bValue, double summationXY, double summationX, double summationY, int volume) {
                 double rightSide =  summationXY - (summationX*summationY/volume);
		 double SSrVal = bValue * rightSide;

		    return SSrVal;
}

double getVr(double SSr) {

     double Vr = SSr/1;
     return Vr;
}

double getVe(double SSe, int param) { //param = parameter = size
     double Ve = SSe/(param-2);
}


double get_Fcalc(double varR, double varE) {
    double fCalc = varR/varE;
       return fCalc; 
}

