/* * * * * * * * * 
 * coder: Laniakea
 * Not perfect but works.
 * Links supplement: https://www.statsdirect.com/help/parametric_methods/ft.htm
 *                   https://stats.idre.ucla.edu/other/mult-pkg/faq/general/faq-what-are-the-differences-between-one-tailed-and-two-tailed-tests/
 * * * * * * * * */
#ifndef TMASTER_H
#define TMASTER_H
#include <iostream>
#include <math.h>




class testA { //When variances are "equal"
     private: 
	     double meanA; //Larger mean
	     double meanB; //Smaller mean
	     double sizeA; //Larger sets size
	     double sizeB; //Smaller sets size
	     double variA; //Larger variance
	     double variB; //Smaller variance
	     double tCalc; //Tcalculated value
	     double DOF; //Degree of freedom

     public:
	     //Setters
	        //~initial setters for the core values
                 double setMeans(double m1, double m2); //Gets both means
		 double setSizes(double s1, double s2); //Gets both sizes
		 double setVaries(double v1, double v2); //Gets both variances
		  
		 //~setter for the t value itself
		    double set_tCalc(void);  //Sets up tcalc value
	            double set_DOF(void);    //Sets up dof value
	     //Getters
                 double get_tCalc(void);  //Returns the tcalc value	     
	         double get_DOF(void);   //Returns the dof value

};

class testB {
    private:
	     double meanA;
	     double meanB;
	     double sizeA;
	     double sizeB;
	     double variA;
	     double variB;
	     double tCalc;
	     double DOF;

    public:	  
	     //Setters
	        //~initial setters for the core values
                 double setMeans(double m1, double m2);
		 double setSizes(double s1, double s2);
		 double setVaries(double v1, double v2);
		  
		 //~setter for the t value itself
		    double set_tCalc(void);
	            double set_DOF(void);	  
	     //Getters
                 double get_tCalc(void);	     
	         double get_DOF(void);
};

//------------for main-----------//
void equalVars();  //Called when variances are equal
void unequalVars();  //Called when variances are unequal

#endif
