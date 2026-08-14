#ifndef __calc_H0H1_h
#define __calc_H0H1_h

#include <iostream>
#include <fstream>
#include <cstdio> 
#include <vector>
#include <cmath>
 
double harmonic_1d(const std::vector<double>& cv,\
    const double y0, const double k);
double harmonic_2d(const std::vector<double>& cv,\
    const double x0,const double y0,const double k);
double EVB_pontential_1d(const std::vector<double>& cv,const double ya,\
    const double yb,const double k_a,const double k_b,const double H12,const double deltaV);
double EVB_pontential_2d(const std::vector<double>& cv,const double xa,const double ya,\
    const double xb,const double yb,const double k_a,const double k_b,const double H12,const double deltaV);
double EVB0(const std::vector<double>& cv);
double EVB1(const std::vector<double>& cv);
double H1(const std::vector<double>& cv);
double H0(const std::vector<double>& cv);
void cal_H0H1_func(const std::vector<double>& cv,double potential_energy[2]);

#endif