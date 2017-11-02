#include <iostream> //cin cout functionality
#include <math.h> //algrebraic functionality
#include <vector> //vector functionality



void show_OBSset(std:: vector <double> vecA);  //Funct PT, displays your observed values table
double uniform_method(std:: vector <double> vecA); //Funct PT, gets the expected value when uniform, aka the mean is all exp values
double get_chiSqureU(std:: vector <double> vecA, double exp_val); //Funct PT, gets the chi square from the above information, actual calc
double varied_method(std:: vector <double> & vecB, int param); //Funct PT, Getting varied array
double get_chiSquareV(std:: vector <double> vecB, std:: vector <double> vecA); //Funct PT, getting calculation for varied exp chi sqr

int main() {
         
    int userOBS;  //User determinant, user enters number of observed measures(elements)
    std:: vector <double> OBSvalues; //Primary vector for the observed values
    std:: vector <double> variedExpVal; //For when the expected value is not unform
    double chiSquare; //the chi square value calulated from above informations(to be gotten)
    int DOF; //Degrees of freedom; #categories (vector.size()) - 1

    char choice; //decider for the choice of uniform or varied
    double expectedValue; //expected value, correlated with the choice if uniform expected values

        std:: cout << "How many observed values are there: ";
	    std:: cin >> userOBS;

        std:: cout << "Entering OBS values\n____________________________________________\n";

        for(int i = 0; i < userOBS; i++) { //Getting the valuation, assinging value to elements in the determinant sized vector
              double tmp_obsval;
		std:: cout << "Enter the #" << i+1 << " element: ";
		std:: cin >> tmp_obsval;
		      OBSvalues.push_back(tmp_obsval);
     	      	      
	}
               std:: cout << "Are the expected values Uniform(u) or Varied(v): ";
               std:: cin >> choice;
	             
	             if(choice == 'u' || choice == 'U') {  //When uniform(and the exp values are all the same, the mean(average)
                         expectedValue =  uniform_method(OBSvalues);
                         chiSquare = get_chiSqureU(OBSvalues, expectedValue); //Calculate chi square

	             }

		     else if(choice =='v' || choice == 'V') { //When varied(and the exp values are all potentially dif, user determinant)
			     varied_method(variedExpVal, userOBS);
	                     chiSquare = get_chiSquareV(OBSvalues, variedExpVal);		     
		     }



      show_OBSset(OBSvalues); //Display user input information
               std:: cout << "Calculated chi square value: " << chiSquare << std:: endl;

	 DOF = OBSvalues.size() - 1; //Getting degrees of freedom
	 std:: cout << "Degrees of freedom: " << DOF << std:: endl;
}

//This function displays the observed values in a table (In a future version i can include a better tab with categories and expected values)
void show_OBSset(std:: vector <double> vecA) {
      int param = vecA.size(); // param var is equal to the total number of elements in the vector
       
      std:: cout << "Displaying set: \n______________________________________\n";

      for(int d = 0; d < param; d++) {
     
	      std:: cout << " | " << vecA[d] << " | ";
      }
            std:: cout << std:: endl;
  
}

//This gets the expected value when uniform, all the mean
double uniform_method(std:: vector <double> vecA) {
    
   double summation = 0.0,
	           expVal; 
  
       for(int e = 0; e < vecA.size(); e++) {
            summation += vecA[e]; 
       }  

       expVal = summation/vecA.size();
         
     return expVal;        
}

double get_chiSqureU(std:: vector <double> vecA, double exp_val) { //Appropiate chi square calculator when the exp val are uniform
       double chiS_value = 0.0;

       for(int y = 0; y < vecA.size(); y++) {
              double temp_OBSandEXP1 = vecA[y]- exp_val;
	      double temp_OBSandEXP2 = pow(temp_OBSandEXP1,2)/exp_val;
	        chiS_value += temp_OBSandEXP2;
       }
       return chiS_value;

}

//Apporopiate chi square calculator when the exp val are varied
double varied_method(std:: vector <double> & vecB, int param) {
        for(int f = 0; f < param; f++) {
               double temp_vecBval;
	       std:: cout << "Enter the #" << f+1 << " expected value: ";
	       std:: cin >> temp_vecBval;
	       vecB.push_back(temp_vecBval);
	}
}

//Appropiate chi square calculator when the exp val are varied
double get_chiSquareV(std:: vector <double> vecB, std:: vector <double> vecA) {
         double chiS_value = 0.0;
	     for(int o = 0; o < vecA.size(); o++) { //Choice now of using vecA or vecB size is arbiturary as they are established by now
		 double temp_OBSandEXP1 =  vecA[o]-vecB[o];		 //to both be the same size
                 double temp_OBSandEXP2 = pow(temp_OBSandEXP1,2)/vecB[o];
		 chiS_value += temp_OBSandEXP2;
	     } 
	  return chiS_value;

}
