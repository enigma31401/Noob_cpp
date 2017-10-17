/*coder: Laniakea/RoguePhilosophy*/
#ifndef ANOVAMASTER_H
#define ANOVAMASTER_H
#include <iostream>
#include <math.h>


class fourFold {
    private:

     double setaSummation; //Total or summation of the treatment/group/category/set A values
     double setbSummation; //Summation(sum,addition, additive value) of set B values
     double setcSummation; //Sum of set C values
     double setdSummation; //Sum of set D values
     double allsetSummation; //Summation of all x's (All members of all sets);
     double allsetSqredSum; //Summation of all squared x's(all members of all sets, sqared)

	    double setaMean; //Average or mean of set A
            double setbMean; //Mean of set A
	    double setcMean; //Mean of set B
	    double setdMean; //Mean of set C

     double sumOfSquares; //The SSt value
     double SqrSumsBetween; //The SSb value
     double SqrSumsWithin; //The SSw value
     double Var_between; //Variance between groups -> Vb value
     double Var_within; //Variance within groups -> Vw value
     double F_ratio; //Basically the F calc or F statistic

	    int setSize; //Assuming uniformity of all sets, scientific quality control of sample sizes



    public:
            //constructors
	     fourFold(int volume); //Is the getter for setSize, except as a constructor it takes primary precedence and initialization and setting(up)

	    //setters
	     double set_groupA_base(double seta[]); //Sets up category/treatment/group/set A or 1's summation and mean
	     double set_groupB_base(double setb[]); //Sets up treatment B summation and mean
	     double set_groupC_base(double setc[]); //Sets up treatment C summation and mean
	     double set_groupD_base(double setd[]); //Sets up treatment D summation and mean
             double set_allset_summation(double seta[], double setb[], double setc[], double setd[]);
             double set_allsetSqrd_sum(double seta[], double setb[], double setc[], double setd[]);
             double set_sumOfSquares(void); //SSt value, void param or arg cause your using privated items within the class

             double set_SqrSumsBetween(void); //SSb value, void for same reason, no imported value(data)
             double set_SqrSumsWithin(void); //SSw value, void for same reason too
             double set_variances(void); //Sets Vb and Vw values
             double set_Fratio(void);

	    //getters
	          double get_groupAsum(void);    //Gets, or displays to main() the sum of group A
		  double get_groupAmean(void);   //Same as above, and funct() is same as funct(void)
		  double get_groupBsum(void);    //Same
		  double get_groupBmean(void);   //Same
		  double get_groupCsum(void);    //Same
		  double get_groupCmean(void);   //Same
	  	  double get_groupDsum(void);    //Same
		  double get_groupDmean(void);   //Same
	          double get_allgroupsum(void);  //Gets or displays the sum of all members of all groups
		  double get_allsetSqrdsum(void);   //Gets the sum of all members squared of all groups
                  double get_sumOfSquares(void); //As to the setter version, this is for the SSt value
                  double get_SqrSumsBetween(void); //Getter of the respective setter too
                  double get_SqrSumsWithin(void); //Getter part
                  double get_VarianceBetween(void); //Vb
		  double get_VarianceWithin(void); //Vw
                  double get_Fratio(void);
                  double get_DOF(void);


};


class threeFold {
    private:

     double setaSummation;   //Total or summation of the treatment/group/category/set A values
     double setbSummation;   //Summation(sum,addition, additive value) of set B values
     double setcSummation;   //Sum of set C values
     double allsetSummation; //Summation of all x's (All members of all sets);
     double allsetSqredSum; //Summation of all squared x's(all members of all sets, sqared)


	    double setaMean; //Average or mean of set A
            double setbMean; //Mean of set B
	    double setcMean; //Mean of set C

     double sumOfSquares; //The SSt value
     double SqrSumsBetween; //The SSb value
     double SqrSumsWithin; //The SSw value
     double Var_between; //Variance between groups -> Vb value
     double Var_within; //Variance within groups -> Vw value
     double F_ratio; //f statistic

	    int setSize; //Assuming uniformity of all sets, scientific quality control of sample sizes



    public:
            //constructors
	     threeFold(int volume); //Is the getter for setSize, except as a constructor it takes primary precedence and initialization and setting(up)

	    //setters
	     double set_groupA_base(double seta[]); //Sets up category/treatment/group/set A or 1's summation and mean
	     double set_groupB_base(double setb[]); //Sets up treatment B summation and mean
	     double set_groupC_base(double setc[]); //Sets up treatment C summation and mean
	     double set_allset_summation(double seta[], double setb[], double setc[]);
             double set_allsetSqrd_sum(double seta[], double setb[], double setc[]);
             double set_sumOfSquares(void); //SSt value, void param or arg cause your using privated items within the class
             double set_SqrSumsBetween(void); //SSb value, void for same reason, no imported value(data)
             double set_SqrSumsWithin(void); //SSw value, void for same reasons
	     double set_variances(void); //Sets Vb and Vw values
             double set_Fratio(void);

	    //getters
	          double get_groupAsum(void);    //Gets, or displays to main() the sum of group A
		  double get_groupAmean(void);   //Same as above, and funct() is same as funct(void)
		  double get_groupBsum(void);    //Same
		  double get_groupBmean(void);   //Same
		  double get_groupCsum(void);    //Same
		  double get_groupCmean(void);   //Same
		  double get_allgroupsum(void);  //Gets or displays the sum of all members of all groups.
		  double get_allsetSqrdsum(void);   //Gets the sum of all members squared of all groups
	          double get_sumOfSquares(void); //As to the setter version, this is for the SSt value
                  double get_SqrSumsBetween(void); //Getter of the respective setter too
                  double get_SqrSumsWithin(void); //getter
                  double get_VarianceBetween(void); //Vb
	 	  double get_VarianceWithin(void); //Vw
                  double get_Fratio(void);
                  double get_DOF(void);
};


//---------for main()

void sizeThree();  //Corresponding to logical sequence when user selects option of 3 groups only
void sizeFour();   //Corresponding to when user selects 4 groups
#endif
