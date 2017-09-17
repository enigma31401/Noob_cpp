#include "temperatura.h"  //to connect to where all the prototypes and objects originate from
#include <iostream> //cin/cout functionality, can be in here or header, or both

using namespace std;//Namespace always go in with int main(), doesn't work inside header

int main() {
    Temp tmp1; //"Class calling" or i forgot how you say this logical mechanism

      string userInitUnit, //initial unit
	  userDesiredUnit; //desired unit

      char choice; //for the do-while loop

      float celsius_desired,
	           kelvin_desired,
	       fahrenheit_desired,
                  initValue;

   //The whole thing in a do while loop so you can do this more than once.
 do{
           cout << "Enter initial temperature unit: ";
	            cin >> userInitUnit;
	         cout << "Enter the temperature value: ";
	   	        cin >> initValue;
           cout << "Enter unit of temp-measure desired: ";
	            cin >> userDesiredUnit;

      if((userInitUnit == "fahrenheit") && (userDesiredUnit == "celsius")){
          tmp1.setFahrenheit(initValue); //Pass the initValue, the raw # into setFahrenheit parameters
		      celsius_desired = tmp1.getFtoC(); //Then getFtoC() function member object w/in the class Temp returns value here and assigned in celsius_desired
		      cout << "Celsius: " << celsius_desired << " " << endl; //Displaying the content desired now.
      }                                           //The rest works the same.

      else if((userInitUnit == "celsius") && (userDesiredUnit == "fahrenheit")) {
          tmp1.setCelsius(initValue);
		      fahrenheit_desired = tmp1.getCtoF();
		      cout << "Fahrenheit : " << fahrenheit_desired << " " << endl;
      }

      else if ((userInitUnit == "celcius") && (userDesiredUnit == "kelvin")) {
          tmp1.setCelsius(initValue);
		      kelvin_desired = tmp1.getCtoK();
		      cout << "Kelvin: " << kelvin_desired << " " << endl;
      }

      else if ((userInitUnit == "kelvin") && (userDesiredUnit == "celsius")) {
          tmp1.setKelvin(initValue);
		      celsius_desired = tmp1.getKtoC();
		      cout << "Celsius: " << celsius_desired << " " << endl;
      }

      else if ((userInitUnit == "fahrenheit") && (userDesiredUnit == "kelvin")) {
          tmp1.setFahrenheit(initValue);
		      kelvin_desired = tmp1.getFtoK();
		      cout << "Kelvin: " << kelvin_desired << " " << endl;       
      }

      else if ((userInitUnit == "kelvin") && (userDesiredUnit == "fahrenheit")) {
           tmp1.setKelvin(initValue);
		       fahrenheit_desired = tmp1.getKtoF();
		       cout << "Fahrenheit: " << fahrenheit_desired << " " << endl;
      }

      else {
           cout << "Value likely erroneous, try again please!" << endl;
      }

      cout << "Do you want to calculate another unit(y/n): ";
  	     cin >> choice;

 }while(choice == 'y');
    
    return 0;
}
