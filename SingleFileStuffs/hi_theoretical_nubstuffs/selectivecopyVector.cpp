// Very elementary logic and principals, here for help in referencing highly applicable logic/mechanics in the future

#include <iostream> //For cin, cout functionality which isn't really here
#include <math.h> //Just in case, for any breakout algebra needed
#include <vector> //For vector usage and their functionalities
#include <iterator> //Sort of necessary here, but not really I don't think? artifact?

//It's like CRISPR but for vectors 

int main() {

	std:: vector <int> Vec1 = {2,5,7,8};
	
	std:: cout << "set 1(original): " << std:: endl;

	for(int f = 0; f < 4; f++) {
             std:: cout << f+1 << " index(element) =  " << Vec1[f] << std:: endl;

	}
             std:: cout << "\nset 2(selective copy): " << std:: endl;

	std:: vector<int> Vec2(Vec1.begin() + 2, Vec1.begin() +2 + 2);
                              //           + x                + x  + y <-- the arbituary amt of eles you want   
                                               // <-- the x is the starting point ele you want, so here it starts at 2 which is 7 and up

	for(int y = 0; y < Vec2.size(); y++) {
             std:: cout << y+1 << " index(element) =  " << Vec2[y] << std:: endl;
                       
   }
	std:: cout << "\n";




}
