#include "temperatura.h"

//Setters member functions
float Temp :: setFahrenheit(float fahren) {
         fahrenheit = fahren;
}

float Temp :: setCelsius(float cels) {
         celsius = cels;
}

float Temp :: setKelvin(float kelv) {
         kelvin = kelv;
}

//getters member functions

float Temp :: getFtoC(void) {
       return (fahrenheit-32)*5/9;
}

float Temp :: getCtoF(void) { //Remember, cpp default operator order is BODMAS like algebra
       return celsius*1.8+32;
}

float Temp :: getCtoK(void) {
       return celsius+273.15;
}

float Temp :: getKtoC(void) {
       return kelvin-273.15;
}

float Temp :: getKtoF(void) {
       return (kelvin*1.8)-459.67;
}

float Temp :: getFtoK(void) {
       return (fahrenheit+459.67)*5/9;
}
