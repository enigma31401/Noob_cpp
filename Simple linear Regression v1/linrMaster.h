#ifndef LINRMASTER_H
#define LINRMASTER_H

#include <iostream>
#include <math.h>


class genData { 

  //Must have been late when I was making this, didn't mean to have "set" in the name of items here
  //For clarity sake (As a still-nub)	
      private:
	      double setX_summation;     //Sum of x values (sum of "x" set)
	      double setY_summation;     //Sum of y values (sum of "y" set)
	      double setX_mean;          //Mean or average of x values
	      double setY_mean;          //Mean or average of y values
	      int sizeOfSets;            //Number of elements/items in each of the sets (x and y)
	      double setXsum_squared;    //Summation of squared x values
	      double setYsum_squared;    //Summation of squared y values
	      double setProduct;         //Summation of the (x,y) of oth sets, so it's like the total of setX[1]*setY[1] + [2]*[2]
	      double n_setSizeSums;      //size total of set-x and set-y sizes
	      double A_value;         //The a value, a is (y~mean) - (b~value * x~mean)
              
	      
	                  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
			   *  NOTE:  set = {12, 12} = total 24, and 24^2 =/= 12^2+12^2
			   * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
             
	      
	      

      public:
	      //Setters
	      double setX_sum(double xSetA[],int size);           //setup the summation of x-set //xSetA and ySatA are named that way to avoid errors since their most be some differentiation in parameters(arguments) in functions. This is like semi-funt overloading since i didn't name the functions the same too. so size can stay the same, but had to add a bit of spice
	      double setY_sum(double ySetA[], int size);         //setup the summation of y-set
	      double setXvalues_sqrd(double xSetB[], int size);
	      double setYvalues_sqrd(double ySetBp[], int size);
	      double setXmeans(double setAsum, int size);        //setA represents set-x
	      double setYmeans(double setBsum, int size);
	      double setthe_SetProduct(double setOne[], double setTwo[], int size);  //setOne and setTwo as proxies for x-set and y-set
    
	     double seta(double b_val); //Associated w/ seta_value

	      //Actual working getters
	      double getXYadditive_product(void);
              double getTotalSize(void);
	      

	      //Constructor
	      genData(int size); //Set size passed in constructor
	       
	     
            //Others and getters
	      double displaySlope(double b_num);
	    
	    
}; 

//Others
 
double getB_value(double summationXY, double summationX, double summationY, double summationXsqrd, int volume); //Where volume is the size of the sets 

double getSSt_value( double summationYsqrd, double summationY, int volume);

double getSSr_value(double bValue, double summationXY, double summationX, double summationY, int volume);

double getVr(double SSr);

double getVe(double SSe, int param);

double get_Fcalc(double varR, double varE);
    



#endif
