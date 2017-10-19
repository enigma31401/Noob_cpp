#include "linrMaster.h"


int main() {

  int theSize;
        std:: cout << "Enter size of set: ";
		std:: cin >> theSize;

           genData data1(theSize);

      double seta[theSize];
      double setb[theSize];

              std:: cout << "x-set values setup " << std:: endl;

	          for(int m = 0; m < theSize; m++) {
                       std:: cout << "Enter the #" << m+1 << " element: ";
		       	std:: cin >> seta[m];
		  }

      std:: cout << "\n--------\n";

              std:: cout << "y-set values setup : " << std:: endl;

	          for(int d = 0; d < theSize; d++) {
                       std:: cout << "Enter the #" << d+1 << " element: ";
		       	std:: cin >> setb[d];
		  }

		  //set-a associated with X, set-b associated with Y

		       double Aset_total = data1.setX_sum(seta, theSize);            //X values sum 
                       double Bset_total = data1.setY_sum(setb, theSize);            //Y values sum
		       double AsetTotal_sqr = data1.setXvalues_sqrd(seta, theSize);  //X^2 values sum
                       double BsetTotal_sqr = data1.setYvalues_sqrd(setb, theSize);  //Y^2 values sum
                       double Aset_average = data1.setXmeans(Aset_total, theSize);   //X values mean
                       double Bset_average = data1.setYmeans(Bset_total, theSize);   //Y values mean 
		       data1.setthe_SetProduct(seta, setb, theSize);                 //setting the values, doing it in the way to make us/me then use getters . This is the setter, right below is the related or respective getter that follows
		       double setAB_product = data1.getXYadditive_product();         //Gets the sums of all respective x,y pairing products, explained deeper in code.
		       double setSizeSum = data1.getTotalSize();                     //Gets the total of each set size

		       double btest = getB_value(setAB_product, Aset_total, Bset_total, AsetTotal_sqr, theSize); //Gets the b value
		       double SStValue = getSSt_value(BsetTotal_sqr, Bset_total, theSize); //Gets the SSt value, as Ambrose educated us on
                       double Value_SSr = getSSr_value(btest, setAB_product, Aset_total, Bset_total, theSize);
                       double SSe_value = SStValue - Value_SSr;
                       double Vr_value = getVr(Value_SSr);
		       double Ve_value = getVe(SSe_value, theSize);
                       double fcalc_value = get_Fcalc(Vr_value, Ve_value);

		       data1.seta(btest);
		       
		       std:: cout << "\n\n------------\n\n";

      std:: cout << "Set-x summation = " << Aset_total << std:: endl;
      std:: cout << "Set-x mean = " << Aset_average << std:: endl;
      std:: cout << "Set-x sqrd summation = " << AsetTotal_sqr << "\n\n";   

      std:: cout << "Set-y summation = " << Bset_total << std:: endl;
      std:: cout << "Set-y mean = " << Bset_average << std:: endl;
      std:: cout << "Set-y sqrd summation = " << BsetTotal_sqr << "\n\n";

      std:: cout << "\"Sum of the products of set x and y respectively w/ their elements:\" " << setAB_product << std:: endl;
      std:: cout << "The total size (combined) of set-x and set-y: " << setSizeSum << "\n\n";
    
      std:: cout << "b-value : " <<  btest << std:: endl;
      std:: cout << "SSt value: " << SStValue << std:: endl;
      std:: cout << "SSr value: " << Value_SSr << std:: endl;              
      std:: cout << "SSe value: " << SSe_value << std:: endl;
      std:: cout << "SSr's degree of freedom is: 1" << std:: endl;
      std:: cout << "SSe's degree of freedom is (n-2): " << theSize-2 << std:: endl;
      std:: cout << "Fcalc coordinance is: (1," << theSize-2 << ")" << std:: endl;
      std:: cout << "Vr(variance 1): " << Vr_value << std:: endl;
      std:: cout << "Ve(variance 2): " << Ve_value << std:: endl;
      std:: cout << "F calc value: " << fcalc_value << std:: endl;
      std:: cout << data1.displaySlope(btest) << std:: endl;


}
