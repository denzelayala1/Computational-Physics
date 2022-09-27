#ifndef Line_h
#define Line_h
#include "Point.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <limits> // std::numeric_limits
#include <stdexcept>

class Line{
    protected:
        double m_;
        double b_;
        double calcSlope(const Point& p1, const Point& p2) const;
        double calcIntercept(const Point& p1, const Point& p2) const;

    public:
    
    //Constructors and Destructor
        Line(double im =0, double ib =0);
        Line(const Point& p1, const Point& p2);
        Line(const Line& line);
        ~Line();

    //Methods

        double m() const;
        double b() const;

        void setSlope(double im);
        void setSlope(const Point& p1, const Point& p2);
        void setIntercept(double ib);
        void setIntercept(const Point& p1, const Point& p2);

        void print() const;
};

#endif