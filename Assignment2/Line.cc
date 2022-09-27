#include "Line.h"

    //Constructors and Destructor
        Line::Line(double im , double ib ){
            m_ = im;
            b_ = ib;
        }

        Line::Line(const Point& p1, const Point& p2){
            m_ = calcSlope(p1, p2);
            b_ = calcIntercept(p1, p2);
        }

        Line::Line(const Line& line){
            m_ = line.m();
            b_ = line.b();
        }

        Line::~Line(){}

    //Methods

        double Line::calcSlope(const Point& p1, const Point& p2) const {

                if(p1.x() == p2.x()){ return std::numeric_limits<double>::infinity();}

                double slope = (p2.y() - p1.y())/(p2.x() - p1.x());
                return slope; 
        }
        double Line::calcIntercept(const Point& p1, const Point& p2) const {
                
                if(p1.x() == p2.x()){ return -sqrt(-2);}
                
                double m = Line::calcSlope(p1, p2);
                double intercept = p1.y()- m*p1.x();
                return intercept;
        }

        double Line::m() const{ return m_;}
        double Line::b() const{ return b_;}

        void Line::setSlope(double im){ m_ = im;}
        void Line::setSlope(const Point& p1, const Point& p2){
                        m_ = calcSlope(p1, p2);
        }

        void Line::setIntercept(double ib){b_ = ib;}
        void Line::setIntercept(const Point& p1, const Point& p2){
                        b_ = calcIntercept(p1, p2);
        }

        void Line::print() const {
            std::cout << "y = " << m_ << " x + " << b_ << std::endl;
        }

    /*
    //operator
        Line Line::operator=(Line const & right) const{
            Line retLine(right);
            return retLine;
        }
    */