/*
    coder: Laniakea
    Purpose: Gets you temperature conversions. Very useful for ye' STEM studentens
*/
#ifndef TEMPERATURA_H
#define TEMPERATURA_H
#include <string>
#include <cmath>


class Temp {
	private:
      float fahrenheit;
      float celsius;
      float kelvin;
       public:
// member function declaration aka prototypes
    //setters  
      float setFahrenheit(float fahren);
      float setCelsius(float cels);
      float setKelvin(float kelv);
   
    //getters
      float getFtoC(void); //fahrenheit to celcius convertor function
      float getCtoF(void); //celsius to faherenheit convertor function 
      float getCtoK(void); //celsius to kelvin convertor function
      float getKtoC(void); //kelvin to celsius convertor function
      float getKtoF(void); //kelvin to fahrenheit convertor function
      float getFtoK(void); //fahrenheit to kelvin convertor function


};

#endif
