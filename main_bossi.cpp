#include<iostream>
#include<vector>
#include<functional>
#include<cmath>
#include "gnuplot-iostream.hpp"
std::vector<double> conv(
			const std::function<double( double )> &f1, 
		    	const std::function<double(double)> &f2,
		    	const std::vector<double> &points,
			const double &i_start,
			const double &i_stop,
			const double &step_size){
	std::vector<double> result;
	result.reserve(points.size());
	for(auto x : points){
		//adesso faccio l'integrale
		double sum_integral{0};
		for(double t=i_start;t<i_stop;t+=step_size)
			sum_integral+=f1(t)*f2(x-t)*step_size;	
		std::cout<<"somma integrale="<<sum_integral<<" posizione x="<<x<<std::endl;			
		result.emplace_back(sum_integral);
	}
	return result;
}
std::vector<double> fill_results(
			const std::function<double( double )> &f1, 
		    	const std::vector<double> &points){
	std::vector<double> result;
	result.reserve(points.size());
	for(auto x : points)
		result.emplace_back(f1(x));
	return result;
}	

int main(int argc, char** argv){
	std::vector<double> x;
	int size=100; //definisco numero di punti
	x.reserve(size);//motivi di speed
	for(int i=0;i<size;i++)
		x.emplace_back(double(i)/10); //riempio il vettore delle x
	std::vector<double> result=conv(&sin,&cos,x, 0,1, 1e-4); //faccio la convoluzione tra sin e cos
	

	//printo
	Gnuplot gp ; 
	std::vector<double> res_sin=fill_results(&sin,x); //uso la funzione riempire
	std::vector<double> res_cos=fill_results(&cos,x);// giusto per evitare di scriverla due volte(e per esercitarmi)
	gp<<"plot"<<gp.file1d(boost::make_tuple(x,res_sin))<<"w lp,"<<gp.file1d(boost::make_tuple(x,res_cos))<<"w lp, "<<gp.file1d(boost::make_tuple(x,result))<<"w lp"<<std::endl;

	return 0;}
