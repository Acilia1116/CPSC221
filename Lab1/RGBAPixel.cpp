#include "RGBAPixel.h"

using namespace cs221util;
    RGBAPixel::RGBAPixel() {
        r = '255';
        g = '255';
        b = '255';
        a = 1.0;
    }
    
    RGBAPixel::RGBAPixel(char r1,char g1,char b1) {
        r = r1;
        g = g1;
        b = b1;
        a = 0.0;
    }

    RGBAPixel::RGBAPixel(char r1,char g1,char b1,double a1) {
        r = r1;
        g = g1;
        b = b1;  
        a = a1; 
    }
   
