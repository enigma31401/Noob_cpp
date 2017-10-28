/* * * * * *
 * Coder: Laniakea
 *
 * * * * * */
#include "tMaster.h"

//=========================== Class testA ===============================//
//setters
double testA :: setMeans(double m1, double m2) {
           meanA = m1;
	   meanB = m2;
}	

double testA :: setSizes(double s1, double s2) {
           sizeA = s1;
	   sizeB = s2;
}

double testA :: setVaries(double v1, double v2) {
           variA = v1;
	   variB = v2;
}

double testA :: set_tCalc() {
          double t_numerator = meanA-meanB;
	        if(t_numerator < 0) { //If statement works as absolute value
                   t_numerator *= -1;
		}
          double t_denomLa = (sizeA - 1) * variA + (sizeB - 1) * variB;          double t_denomLb = sizeA + sizeB - 2;
	  double t_denomLc = sqrt(t_denomLa/t_denomLb);
	  double t_denomRa = sqrt(1/sizeA + 1/sizeB);
	  double t_denominator = t_denomLc * t_denomRa;

	  double t_whole = t_numerator / t_denominator;
	  
	  tCalc = t_whole;
}

double testA :: set_DOF() {
       double theDOF = sizeA + sizeB - 2; 
          
         DOF = theDOF;
}


//getters
double testA :: get_DOF() {
      return DOF;
}
double testA :: get_tCalc() {
       return tCalc;
}



//========================================================================//

//==================================class testB=======================//
 
//setters
double testB :: setMeans(double m1, double m2) {
           meanA = m1;
	   meanB = m2;
}	

double testB :: setSizes(double s1, double s2) {
           sizeA = s1;
	   sizeB = s2;
}

double testB :: setVaries(double v1, double v2) {
           variA = v1;
	   variB = v2;
}

double testB :: set_tCalc() {
           double t_numerator = meanA - meanB;
	     if(t_numerator < 0) {   //Works like absolute value 
                  t_numerator *= -1;
	     }

           double t_denominator = sqrt(variA/sizeA + variB/sizeB);
	        double t_whole = t_numerator/t_denominator;

		tCalc = t_whole;

}
 
double testB :: set_DOF() {
           double dof_numeratorA = variA/sizeA + variB/sizeB;
	   double dof_numerator = pow(dof_numeratorA,2);
	   double dof_denomLA = variA/sizeA;
	   double dof_denomLB = pow(dof_denomLA,2);
	   double dof_denomLeft = dof_denomLB / sizeA+1;
	   double dof_denomRA = variB/sizeB;
	   double dof_denomRB = pow(dof_denomRA,2);
	   double dof_denomRight = dof_denomRB / sizeB+2;
	   double  dof_denominator = dof_denomLeft + dof_denomRight;
	   double theDOF = dof_numerator/dof_denominator - 2;

	   DOF = theDOF;
}


//getters
double testB :: get_tCalc() {
        return tCalc;
}

double testB :: get_DOF() {
        return DOF;
}
//=====================================================================//

//-----main shit ---//
void equalVars() {
testA t1;

    double avg1, avg2, volume1, volume2, var1, var2;
          
        std:: cout << "Enter the larger mean: ";
		std:: cin >> avg1;
	std:: cout << "Enter the smaller mean: ";
		std:: cin >> avg2;
	std:: cout << "Enter the larger sized set: ";
		std:: cin >> volume1;
	std:: cout << "Enter the smaller sized set: ";
		std:: cin >> volume2;
	std:: cout << "Enter the larger variance: ";
		std:: cin >> var1;
	std:: cout << "Enter the smaller variance: ";
		std:: cin >> var2;

	t1.setMeans(avg1, avg2);
        t1.setSizes(volume1, volume2);	
        t1.setVaries(var1, var2);
        t1.set_tCalc();
        t1.set_DOF();

	std:: cout << "T calculated: " << t1.get_tCalc() << std:: endl;

        std:: cout << "DOF: " << t1.get_DOF() << std:: endl;
}

void unequalVars() {
testB t1;

    double avg1, avg2, volume1, volume2, var1, var2;
          
        std:: cout << "Enter the larger mean: ";
		std:: cin >> avg1;
	std:: cout << "Enter the smaller mean: ";
		std:: cin >> avg2;
	std:: cout << "Enter the larger sized set: ";
		std:: cin >> volume1;
	std:: cout << "Enter the smaller sized set: ";
		std:: cin >> volume2;
	std:: cout << "Enter the larger variance: ";
		std:: cin >> var1;
	std:: cout << "Enter the smaller variance: ";
		std:: cin >> var2;

	t1.setMeans(avg1, avg2);
        t1.setSizes(volume1, volume2);	
        t1.setVaries(var1, var2);
        t1.set_tCalc();
        t1.set_DOF();

	std:: cout << "T calculated: " << t1.get_tCalc() << std:: endl;

        std:: cout << "DOF: " << t1.get_DOF() << std:: endl;
}
