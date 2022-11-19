#ifndef CS221UTIL_RGBAPIXEL_H
#define CS221UTIL_RGBAPIXEL_H

namespace cs221util {
    class RGBAPixel 
    {
        public:
        char r,g,b;
        double a;

        RGBAPixel();
        
        RGBAPixel(char r1, char g1, char b1);

        RGBAPixel(char r1, char g1, char b1, double a1);
    };
}

#endif