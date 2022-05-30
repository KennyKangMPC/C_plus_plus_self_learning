#include <memory> // Required C++11 or above
#include <iostream>

int main() {
    std::shared_ptr<int> p_x(new int);
    std::cout<<"p_x use count: "<<p_x.use_count()<<"\n";

    *p_x = 5; // ’de-reference’ to alter contents

    // Use this pointer elsewhere
    std::shared_ptr<int> p_y = p_x;
    std::cout<<"p_x use count: "<<p_x.use_count()<<"\n";
    p_y.reset();
    std::cout<<"p_x use count: "<<p_x.use_count()<<"\n";
    p_x.reset();
    std::cout<<"p_x use count: "<<p_x.use_count()<<"\n";
    return 0;

    // textbook p73 has weak_ptr w/ expired and lock functions which can
    // be used to check if its resource has been deleted and, if it has obt been deleted,
    // to get to the resource. weak_ptr is a smart pointer that does not
    // contribute to the use count. It can be used in situations where variables
    // need to be accessed.

}