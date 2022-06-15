#include "ExampleClass.hpp"

// Constructor to set private members
ExampleClass::ExampleClass(double member1, double member2) {
    mMemberVariable1 = member1;
    mMemberVariable2 = member2;
}

// GetMinimum is a member method
double ExampleClass::GetMinimum() const {
    if (mMemberVariable1 < mMemberVariable2) {
        return mMemberVariable1;
    } else {
        return mMemberVariable2;
    }
}

// GetMaximum is a friend function
double GetMaximum(const ExampleClass& eg_class) {
    if (eg_class.mMemberVariable1 >
        eg_class.mMemberVariable2) {
            return eg_class.mMemberVariable1;
        } else {
            return eg_class.mMemberVariable2;
        }
}