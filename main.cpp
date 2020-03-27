#include <iostream>
#include <vector>
#include "gnuplot-iostream.hpp"
#include <cmath>  


// This function compute the covolution 

std::vector<double> conv(std::vector<double> const & a,std::vector<double> const & b, const int size) 

{

 auto j=b.crbegin(); // constant reverse iterator 
 auto i=a.begin();  // iterator 
 
 double res ;       // used for temporarily store the result  


 std::vector<double> conv_vect(size) ;   // vector containig the computed convolution

 auto k = conv_vect.begin() ;         // iterator

 
 for ( i ; i !=a.end() ; i++ ) {

 res =   (*j++)*(*i) + res ;    // NOTE: the ++ on the j iterator is decresing its value since j it's a reverse operator 
 				// so that increasing means retrating 

*k = res; 		        // put res in the vector conv_vect 

 k++ ;				// increase the value ok k  

}

return conv_vect ; 

}





int main()

 {
const int size{21} ; // dimesione dei vettori 
const double step {0.5} ; // step zize del vettore delle x

std::vector<double> a(size) ; // vettore che contiene la prima funzione  
std::vector<double> b(size) ; // vettpre che contiene la seconda funzion
auto j = a.begin() ; // iterator
auto m = b.begin() ; // iteratore
 
std::vector<double> x(size) ;  // vettore delle x 

int k {0} ; 

for ( auto i= x.begin() ; i != x.end() ; i++)  // con questo for riempio il vettore x , a , b 
{

// vettore x 
 *i = k * step;  
  

// vectors that are convolved 

*j=  sin (2*3.14*0.1*(*i));
*m = cos (2*3.14*0.1*(*i)) ;  

k++ ; j++ ; m++ ; 

}

// result of the convolution
std::vector<double> ans = conv(a,b,size) ;  


// this is needed to plot with gnuplot 

 Gnuplot gp ; 
gp<<"plot"<<gp.file1d(boost::make_tuple(x,a))<<"w lp,"<<gp.file1d(boost::make_tuple(x,b))<<"w lp, "<<gp.file1d(boost::make_tuple(x,ans))<<"w lp"<<std::endl;

return 0 ; }
