#include "calc_H0H1.h"
using namespace std;
 
double harmonic_1d(const std::vector<double>& cv,\
    const double y0, const double k) {
    // V(x,y)= 1/2 * k * (x-x0)^2

    double E;
    double y;

    y = cv[1];

    E = 0.5 * k * pow((y-y0),2);
    
    return E;
}

double harmonic_2d(const std::vector<double>& cv,\
    const double x0,const double y0,const double k) {
    // V(x,y)= 1/2 * k * ( (x-x0)^2 + (y-y0)^2 )

    double E;
    double x;
    double y;

    x = cv[0];
    y = cv[1];


    E = 0.5 * k *( pow((x-x0),2)+pow((y-y0),2) );
    
    return E;
}


double EVB_pontential_1d(const std::vector<double>& cv,const double ya,\
    const double yb,const double k_a,const double k_b,const double H12,const double deltaV){
    // V_evb =  0.5 * ( Va+Vb ) - 0.5 * sqrt( (Va-Vb)**2  + 4 * H12 )

    double V_evb;
    double Va;
    double Vb;

    Va = harmonic_1d(cv,ya,k_a);
    Vb = harmonic_1d(cv,yb,k_b) + deltaV;
    V_evb =  0.5 * ( Va+Vb ) - 0.5 * sqrt( pow((Va-Vb),2)  + 4 * H12 );
    return V_evb;
}

double EVB_pontential_2d(const std::vector<double>& cv,const double xa,const double ya,\
    const double xb,const double yb,const double k_a,const double k_b,const double H12,const double deltaV){
    // V_evb =  0.5 * ( Va+Vb ) - 0.5 * sqrt( (Va-Vb)**2  + 4 * H12 )

    double V_evb;
    double Va;
    double Vb;

    Va = harmonic_2d(cv,xa,ya,k_a);
    Vb = harmonic_2d(cv,xb,yb,k_b) + deltaV;
    V_evb =  0.5 * ( Va+Vb ) - 0.5 * sqrt( pow((Va-Vb),2)  + 4 * H12 );
    return V_evb;
}

double EVB0(const std::vector<double>& cv){

    double xa = -3;
    double ya = -1;
    double xb = 2.5;
    double yb = -1;
    double k_a = 4;
    double k_b = 4;
    double H12 = 5;
    double deltaV = 0;

    double y0_a = -1;
    double y0_b = 2;
    double ky_a = 12;
    double ky_b = 12;
    double H12_y = 10;
    double deltaV_y = 0;

    return EVB_pontential_2d(cv,xa,ya,xb,yb,k_a,k_b,H12,deltaV)
    +EVB_pontential_1d(cv,y0_a,y0_b,ky_a,ky_b,H12_y,deltaV_y);
}

double EVB1(const std::vector<double>& cv){

    double xa = -2.5;
    double ya = 2;
    double xb = 2.5;
    double yb = 2;
    double k_a = 4;
    double k_b = 4;
    double H12 = 15;
    double deltaV = 10;

    return EVB_pontential_2d(cv,xa,ya,xb,yb,k_a,k_b,H12,deltaV);
}
double H1(const std::vector<double>& cv){
    return EVB1(cv);
}

double H0(const std::vector<double>& cv){
    return EVB0(cv);
}
 
//inline void cal_H0H1_func() {
//    double potential_energy[2];
//    std::vector<double> cv;
//    const char* ener_file = "H0H1";
//    const char* cv_file = "CV_xy";
//    double temp;
//    std::ifstream inputFile(cv_file);
//
//    if (!inputFile.is_open()) {
//        std::cerr << "Can not open the file CV_xy!" << std::endl;
//    }
//
//    for (int i = 0; i < 2; i++) {
//        if (inputFile >> temp) {
//            cv.push_back(temp);
//        }
//        else
//        {
//            inputFile.close(); 
//            std::cerr << "Can not open the file CV_xy!" << std::endl;
//        }
//    }
//    inputFile.close();
// 
//    double h0 = H0(cv);
//    double h1 = H1(cv);
//
//    std::ofstream outfile(ener_file);
//    
//    if (outfile.is_open()) {
//        outfile << std::to_string(h0) << std::endl;
//        outfile << std::to_string(h1) << std::endl;
//        outfile.close();
//    } else {
//        std::cerr << "Can not open the file H0H1!" << std::endl;
//        outfile.close();
//    }
//
//}

void cal_H0H1_func(const std::vector<double>& cv,double potential_energy[2]) {
    double h0 = H0(cv);
    double h1 = H1(cv);

    potential_energy[0]=h0;
    potential_energy[1]=h1;

}