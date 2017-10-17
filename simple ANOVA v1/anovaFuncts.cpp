/*coder: Laniakea/RoguePhilosophy*/

#include "anovaMaster.h"

//Note: Function member order inside and outside classes don't matter.
//Note: Constructors are great for initializing external valuation inside class at the beginning.
//Note: Order in headers, or specifically for classes in headers don't matter for it's/their items
//========================fourFold Parent Class==================================================//
    //constructors
        fourFold :: fourFold(int volume) { //Works like a setter(which is just a conceptual role)
           setSize = volume;
	}

    //setters
        double fourFold :: set_groupA_base(double seta[]) {    //imported from outside set, via parameter
                         double setA_total = 0.0; //Zeroing the space, safety technique for adding totals
			 double setA_average; //Declared the proxy for the mean

			     for(int t = 0; t < setSize; t++) { //for loop for the addition of set A values
                                   setA_total += seta[t];
		             }
				 setA_average = setA_total/setSize;

				 setaSummation = setA_total; //Now gotten by parameter, transfer sum to private item. Also note, parameters are also called arguments too.
				 setaMean = setA_average; //Same as above, now we get the private item mean from transference
	}


double fourFold :: set_groupB_base(double setb[]) {    //imported from outside set, via parameter
                         double setB_total = 0.0; //Zeroing the space, safety technique for adding totals
			 double setB_average; //Declared the proxy for the mean

			     for(int e = 0; e < setSize; e++) { //for loop for the addition of set B values
                                   setB_total += setb[e];
		             }
				 setB_average = setB_total/setSize;

				 setbSummation = setB_total; //Now gotten by parameter, transfer sum to private item. Also note, parameters are also called arguments too.
				 setbMean = setB_average; //Same as above, now we get the private item mean from transference
	}


double fourFold :: set_groupC_base(double setc[]) {    //imported from outside set, via parameter
                         double setC_total = 0.0; //Zeroing the space, safety technique for adding totals
			 double setC_average; //Declared the proxy for the mean

			     for(int q = 0; q < setSize; q++) { //for loop for the addition of set C values
                                   setC_total += setc[q];
		             }
				 setC_average = setC_total/setSize;

				 setcSummation = setC_total; //Now gotten by parameter, transfer sum to private item. Also note, parameters are also called arguments too.
				 setcMean = setC_average; //Same as above, now we get the private item mean from transference
	}

double fourFold :: set_groupD_base(double setd[]) {    //imported from outside set, via parameter
                         double setD_total = 0.0; //Zeroing the space, safety technique for adding totals
			 double setD_average; //Declared the proxy for the mean

			     for(int m = 0; m < setSize; m++) { //for loop for the addition of set D values
                                   setD_total += setd[m];
		             }
				 setD_average = setD_total/setSize;

				 setdSummation = setD_total; //Now gotten by parameter, transfer sum to private item. Also note, parameters are also called arguments too.
				 setdMean = setD_average; //Same as above, now we get the private item mean from transference
	}

double fourFold :: set_allset_summation(double seta[], double setb[], double setc[], double setd[]) {
                   double allSet_total = 0.0;
		    //Extra note: use setSize, it's in the class innately now! If i forgot, now ye know

                for(int r = 0; r < setSize; r++) {
                    allSet_total += seta[r] + setb[r] + setc[r] + setd[r];
		}

		allsetSummation = allSet_total;
}

double fourFold :: set_allsetSqrd_sum(double seta[], double setb[], double setc[], double setd[]) {
                   double allSetsquared_total = 0.0;
		    //Extra note: use setSize, it's in the class innately now! If i forgot, now ye know

                for(int r = 0; r < setSize; r++) {
                    allSetsquared_total += pow(seta[r],2) + pow(setb[r],2) + pow(setc[r],2) + pow(setd[r],2);
		}

		allsetSqredSum = allSetsquared_total;
}

double fourFold :: set_sumOfSquares() {
           double SSt_value; //SSt
	   double N_value = setSize *4;
                                                   //Main algebraic part
	          SSt_value = allsetSqredSum - pow(allsetSummation,2)/N_value;
                                               //Putting parantheses could have worked, around right hald
					       //But oh well
           sumOfSquares = SSt_value;    //Acquisition of SSt value in function
}

double fourFold :: set_SqrSumsBetween() {
           double righthand_side = pow(setaSummation,2)/setSize + pow(setbSummation,2)/setSize + pow(setcSummation,2)/setSize + pow(setdSummation,2)/setSize;
           double SSb_value;
           double N_value = setSize * 4;
           double lefthand_side = pow(allsetSummation,2)/N_value;

              SSb_value = righthand_side - lefthand_side;
           SqrSumsBetween = SSb_value; //Transfer value to inside class private item
}

double fourFold :: set_SqrSumsWithin() {
           double SSw_value = sumOfSquares - SqrSumsBetween;

	   SqrSumsWithin = SSw_value;
}

double fourFold :: set_variances() {
             double Vb, Vw;
	     double N_value = 4 * setSize;
	     Vb = SqrSumsBetween/(4-1); //4, like the other spotted 4 const here are the sets present
	     Vw = SqrSumsWithin /(N_value-4);

	     Var_between = Vb;
	     Var_within = Vw;
}

double fourFold :: set_Fratio() {
          double Fcalc = Var_between/Var_within;

	  F_ratio = Fcalc;
}

    //getters
        double fourFold :: get_groupAsum() {
                 return setaSummation;
	}

        double fourFold :: get_groupAmean() {
                 return setaMean;
	}

        double fourFold :: get_groupBsum() {
                 return setbSummation;
	}

        double fourFold :: get_groupBmean() {
                 return setbMean;
	}

        double fourFold :: get_groupCsum() {
                 return setcSummation;
	}

        double fourFold :: get_groupCmean() {
                 return setcMean;
	}

        double fourFold :: get_groupDsum() {
                 return setdSummation;
	}

        double fourFold :: get_groupDmean() {
                 return setdMean;
	}

        double fourFold :: get_allgroupsum() {
                 return allsetSummation;
	}

        double fourFold :: get_allsetSqrdsum() {
                 return allsetSqredSum;
	}

        double fourFold :: get_sumOfSquares() {
                 return sumOfSquares;
        }

        double fourFold :: get_SqrSumsBetween() {
                 return SqrSumsBetween;
        }

        double fourFold :: get_SqrSumsWithin() {
                 return SqrSumsWithin;
	}

        double fourFold :: get_VarianceBetween() {
                 return Var_between;
	}

        double fourFold :: get_VarianceWithin() {
                 return Var_within;
	}

        double fourFold :: get_Fratio() {
                 return F_ratio;
	}

        double fourFold :: get_DOF() {
		std:: cout << "Degree of freedom: \n";
		std:: cout << "(" << 4-1 << ", " << 4*setSize-4 << ")" << std:: endl;
	}
//-----------------------------------------------------------------------------------------------//




//========================threeFold Parent Class==================================================//
    //constructors
        threeFold :: threeFold(int volume) { //Works like a setter(which is just a conceptual role)
           setSize = volume;
	}

    //setters
        double threeFold :: set_groupA_base(double seta[]) {    //imported from outside set, via parameter
                         double setA_total = 0.0; //Zeroing the space, safety technique for adding totals
			 double setA_average; //Declared the proxy for the mean

			     for(int t = 0; t < setSize; t++) { //for loop for the addition of set A values
                                   setA_total += seta[t];
		             }
				 setA_average = setA_total/setSize;

				 setaSummation = setA_total; //Now gotten by parameter, transfer sum to private item. Also note, parameters are also called arguments too.
				 setaMean = setA_average; //Same as above, now we get the private item mean from transference
	}


double threeFold :: set_groupB_base(double setb[]) {    //imported from outside set, via parameter
                         double setB_total = 0.0; //Zeroing the space, safety technique for adding totals
			 double setB_average; //Declared the proxy for the mean

			     for(int e = 0; e < setSize; e++) { //for loop for the addition of set B values
                                   setB_total += setb[e];
		             }
				 setB_average = setB_total/setSize;

				 setbSummation = setB_total; //Now gotten by parameter, transfer sum to private item. Also note, parameters are also called arguments too.
				 setbMean = setB_average; //Same as above, now we get the private item mean from transference
	}


double threeFold :: set_groupC_base(double setc[]) {    //imported from outside set, via parameter
                         double setC_total = 0.0; //Zeroing the space, safety technique for adding totals
			 double setC_average; //Declared the proxy for the mean

			     for(int q = 0; q < setSize; q++) { //for loop for the addition of set C values
                                   setC_total += setc[q];
		             }
				 setC_average = setC_total/setSize;

				 setcSummation = setC_total; //Now gotten by parameter, transfer sum to private item. Also note, parameters are also called arguments too.
				 setcMean = setC_average; //Same as above, now we get the private item mean from transference
	}

double threeFold :: set_allset_summation(double seta[], double setb[], double setc[]) {
                   double allSet_total = 0.0;
		    //Extra note: use setSize, it's in the class innately now! If i forgot, now ye know

                for(int r = 0; r < setSize; r++) {
                    allSet_total += seta[r] + setb[r] + setc[r];
		}

		allsetSummation = allSet_total;
}

double threeFold :: set_allsetSqrd_sum(double seta[], double setb[], double setc[]) {
                   double allSetsquared_total = 0.0;
		    //Extra note: use setSize, it's in the class innately now! If i forgot, now ye know

                for(int r = 0; r < setSize; r++) {
                    allSetsquared_total += pow(seta[r],2) + pow(setb[r],2) + pow(setc[r],2);
		}

		allsetSqredSum = allSetsquared_total;
}

double threeFold :: set_sumOfSquares() {
           double SSt_value; //SSt
	   double N_value = setSize * 3; //Three here, because three set option
                                                   //Main algebraic part
	          SSt_value = allsetSqredSum - pow(allsetSummation,2)/N_value;
                                               //Putting parantheses could have worked, around right hald
					       //But oh well
           sumOfSquares = SSt_value;    //Acquisition of SSt value in function
}

double threeFold :: set_SqrSumsBetween() {
           double righthand_side = pow(setaSummation,2)/setSize + pow(setbSummation,2)/setSize + pow(setcSummation,2)/setSize;
           double SSb_value;
           double N_value = setSize * 3;
           double lefthand_side = pow(allsetSummation,2)/N_value;

              SSb_value = righthand_side - lefthand_side;
           SqrSumsBetween = SSb_value; //Transfer value to inside class private item
}

double threeFold :: set_SqrSumsWithin() {
           double SSw_value = sumOfSquares - SqrSumsBetween;

	   SqrSumsWithin = SSw_value;
}

double threeFold :: set_variances() {
             double Vb, Vw;
	     double N_value = 3 * setSize;
	     Vb = SqrSumsBetween/(3-1); //3, like the other spotted 3 const here are the sets present
	     Vw = SqrSumsWithin /(N_value-3);

	     Var_between = Vb;
	     Var_within = Vw;
}

double threeFold :: set_Fratio() {
          double Fcalc = Var_between/Var_within;

	  F_ratio = Fcalc;
}


    //getters
        double threeFold :: get_groupAsum() {
                 return setaSummation;
	}

        double threeFold :: get_groupAmean() {
                 return setaMean;
	}

        double threeFold :: get_groupBsum() {
                 return setbSummation;
	}

        double threeFold :: get_groupBmean() {
                 return setbMean;
	}

        double threeFold :: get_groupCsum() {
                 return setcSummation;
	}

        double threeFold :: get_groupCmean() {
                 return setcMean;
	}

        double threeFold :: get_allgroupsum() {
                 return allsetSummation;
	}

        double threeFold :: get_allsetSqrdsum() {
                 return allsetSqredSum;
	}

        double threeFold :: get_sumOfSquares() {
                 return sumOfSquares;
        }

        double threeFold :: get_SqrSumsBetween() {
                 return SqrSumsBetween;
        }

        double threeFold :: get_SqrSumsWithin() {
                 return SqrSumsWithin;
	}

        double threeFold :: get_VarianceBetween() {
                 return Var_between;
	}

        double threeFold :: get_VarianceWithin() {
                 return Var_within;
	}

        double threeFold :: get_Fratio() {
                 return F_ratio;
	}
        double threeFold :: get_DOF() {
		std:: cout << "Degree of freedom: \n";
		std:: cout << "(" << 3-1 << ", " << 3*setSize-3 << ")" << std:: endl;
	}
//-----------------------------------------------------------------------------------------------//


void sizeThree() {
       int count; //Declaring count, size of the sets

	   std:: cout << "Enter the uniform set size(for all sets): "; //Is uniformed because science
	     std:: cin >> count;

                        threeFold anova3(count); //Declare and substatiating class via constructor taking count's value


           double groupOne[count];    //Group one set created, with the size being the value of count
           double groupTwo[count];    //Group two created, w/ same
	   double groupThree[count];  //Group three created


	           std:: cout << "\n\n";

	           std:: cout << "----------Setting Up Group One----------\n";
		      for(int u = 0; u < count; u++) {
                          std:: cout << "Enter the #" << u+1 << " element: ";
	   			std:: cin >> groupOne[u];
		      }

		   std:: cout << "----------Setting Up Group Two----------\n";
                      for(int u = 0; u < count; u++) {
                          std:: cout << "Enter the #" << u+1 << " element: ";
	   			std:: cin >> groupTwo[u];
		      }

                   std:: cout << "----------Setting Up Group Three----------\n";
	              for(int t = 0; t < count; t++) {
                          std:: cout << "Enter the #" << t+1 << " element: ";
	   		        std:: cin >> groupThree[t];
		      }



		   std:: cout << "\n\n";

	           anova3.set_groupA_base(groupOne);    //Passing the away to class item(function here)  to set up summation and mean.
		   anova3.set_groupB_base(groupTwo);    //Same as above, for the second group
		   anova3.set_groupC_base(groupThree);  //Same as above, for the third group
                   anova3.set_allset_summation(groupOne, groupTwo, groupThree);
                   anova3.set_allsetSqrd_sum(groupOne, groupTwo, groupThree);
                   anova3.set_sumOfSquares(); //Sets up the sum of squares
                   anova3.set_SqrSumsBetween(); //Sets up the sum of sqrs between groups SSb
                   anova3.set_SqrSumsWithin(); //Sets up the sum of sqrs within groups SSw
                   anova3.set_variances(); //Sets up Vb and Vw values
                   anova3.set_Fratio(); //Sets up F calc value

                   std:: cout << "Set a mean: " << anova3.get_groupAmean() << std:: endl;
		   std:: cout << "Set b mean: " << anova3.get_groupBmean() << std:: endl;
		   std:: cout << "Set c mean: " << anova3.get_groupCmean() << std:: endl;
		   std:: cout << "Set a total: " << anova3.get_groupAsum() << std:: endl;
		   std:: cout << "Set b total: " << anova3.get_groupBsum() << std:: endl;
		   std:: cout << "Set c total: " << anova3.get_groupCsum() << std:: endl;
		   std:: cout << "Sum of all sets: " << anova3.get_allgroupsum() << std:: endl;
                std:: cout << "Sum of all squared items: " << anova3.get_allsetSqrdsum()  << std:: endl;
                std:: cout << "Sum of Sqr's (SSt val): " << anova3.get_sumOfSquares() << std:: endl;
		std:: cout << "Sum of Sqr B/w (SSb val): " << anova3.get_SqrSumsBetween() << std:: endl;
                std:: cout << "Sum of Sqr W/i (SSw val): " << anova3.get_SqrSumsWithin() << std:: endl;
                std:: cout << "Variance between (Vb): " << anova3.get_VarianceBetween() << std:: endl;
		std:: cout << "Variance within(Vw): " << anova3.get_VarianceWithin() << std:: endl;
                std:: cout << "F statistic: " << anova3.get_Fratio() << std:: endl;
                std:: cout << anova3.get_DOF();


}


void sizeFour() {
      int count; //Declaring count, size of the sets

	   std:: cout << "Enter the uniform set size(for all sets): "; //Is uniformed because science
	     std:: cin >> count;

                        fourFold anova4(count); //Declare and substatiating class via constructor taking count's value


           double groupOne[count];    //Group one set created, with the size being the value of count
           double groupTwo[count];    //Group two created, w/ same
	   double groupThree[count];  //Group three created
	   double groupFour[count];   //Group four created

	           std:: cout << "\n\n";

	           std:: cout << "----------Setting Up Group One----------\n";
		      for(int u = 0; u < count; u++) {
                          std:: cout << "Enter the #" << u+1 << " element: ";
	   			std:: cin >> groupOne[u];
		      }

		   std:: cout << "----------Setting Up Group Two----------\n";
                      for(int u = 0; u < count; u++) {
                          std:: cout << "Enter the #" << u+1 << " element: ";
	   			std:: cin >> groupTwo[u];
		      }

                   std:: cout << "----------Setting Up Group Three----------\n";
	              for(int t = 0; t < count; t++) {
                          std:: cout << "Enter the #" << t+1 << " element: ";
	   		        std:: cin >> groupThree[t];
		      }

	           std:: cout << "----------Setting Up Group Four----------\n";
		      for(int y = 0; y < count; y++) {
                          std:: cout << "Enter the #" << y+1 << " element: ";
	   		        std:: cin >> groupFour[y];
		      }

		   std:: cout << "\n\n";

	           anova4.set_groupA_base(groupOne);    //Passing the away to class item(function here)  to set up summation and mean.
		   anova4.set_groupB_base(groupTwo);    //Same as above, for the second group
		   anova4.set_groupC_base(groupThree);  //Same as above, for the third group
		   anova4.set_groupD_base(groupFour);   //Same as above, for the fourth group
                   anova4.set_allset_summation(groupOne, groupTwo, groupThree, groupFour);
                   anova4.set_allsetSqrd_sum(groupOne, groupTwo, groupThree, groupFour);
                   anova4.set_sumOfSquares(); //Sets up the sum of squares
	           anova4.set_SqrSumsBetween(); //Sets up the sum of sqrs between groups
                   anova4.set_SqrSumsWithin(); //Sets up the SSw value
                   anova4.set_variances(); //Sets up Vb and Vw values
		   anova4.set_Fratio(); //Sets up F calc value

                   std:: cout << "Set a mean: " << anova4.get_groupAmean() << std:: endl;
		   std:: cout << "Set b mean: " << anova4.get_groupBmean() << std:: endl;
		   std:: cout << "Set c mean: " << anova4.get_groupCmean() << std:: endl;
		   std:: cout << "Set d mean: " << anova4.get_groupDmean() << std:: endl;
		   std:: cout << "Set a total: " << anova4.get_groupAsum() << std:: endl;
		   std:: cout << "Set b total: " << anova4.get_groupBsum() << std:: endl;
		   std:: cout << "Set c total: " << anova4.get_groupCsum() << std:: endl;
		   std:: cout << "Set d total: " << anova4.get_groupDsum() << std:: endl;
                   std:: cout << "Sum of all sets: " << anova4.get_allgroupsum() << std:: endl;
		std:: cout << "Sum of all squared items: " << anova4.get_allsetSqrdsum()  << std:: endl;
                std:: cout << "Sum of Sqr's (SSt val): " << anova4.get_sumOfSquares() << std:: endl;
                std:: cout << "Sum of Sqr B/w (SSb val): " << anova4.get_SqrSumsBetween() << std:: endl;
		std:: cout << "Sum of sqr W/i (SSw val): " << anova4.get_SqrSumsWithin() << std:: endl;
                std:: cout << "Variance between (Vb): " << anova4.get_VarianceBetween() << std:: endl;
		std:: cout << "Variance within(Vw): " << anova4.get_VarianceWithin() << std:: endl;
                std:: cout << "F statistic: " << anova4.get_Fratio() << std:: endl;
                std:: cout << anova4.get_DOF();

}
