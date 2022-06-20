#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF

/*
Using the class structure described above, the base class AbstractOdeSolver
would not actually include a numerical method for calculating a numerical solution
of a differential equation, and so we would not want to ever create an instance of
this class. We can automatically enforce this by making AbstractOdeSolver
an abstract class. This is implemented by setting the virtual functions SolveEquation and RightHandSide to be pure virtual functions as shown in lines 15
and 16 of the listing for AbstractOdeSolver.hpp below. We indicate that these
functions are pure virtual functions by completing the declaration of these members
with “= 0” as shown in the listing below. Should we mistakenly attempt to create
an instance of the class AbstractOdeSolver we would get a compilation error.
*/
class AbstractOdeSolver {
    protected:
        double stepSize;
        double initialTime;
        double finalTime;
        double initialValue;
    public:
        void SetStepSize(double h);
        void SetTimeInterval(double t0, double t1);
        void SetInitialValue(double y0);
        virtual double RightHandSide(double y, double t) = 0;
        virtual double SolveEquation() = 0;
};

#endif