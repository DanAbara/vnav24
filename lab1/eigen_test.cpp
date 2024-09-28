#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::MatrixXd A(2,2);
    A(0,0) = 1;
    A(0,1) = -1;
    A(1,0) = 0.5;
    A(1,1) = 2.2;
    std::cout << A << std::endl;
    
    return 0;
}
