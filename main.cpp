#include <iostream>
#include <fstream>
#include <iomanip>

double map (double D)
{
    return (D-1)*3.0/4.0 - 1.0;
}


int main()
{
    std::string filename = "data.csv";
    std::ifstream ifstr(filename);

    if(ifstr.fail())
    {
        std::cerr << "File not found" << std::endl;
        return 2;
    }

    std::ofstream ofstr("result.csv");
    ofstr << "# N Mean" << std::endl;

    double N;
    double sumValues = 0;
    int i = 0;
    while (ifstr >> N)
    {
        i++;
        double mean = 0;
        sumValues += map(N);
        mean = sumValues/i;
        ofstr << i << " " << std::setprecision(16) << std::scientific << mean << std::endl;

    }
    ifstr.close();
    ofstr.close();

    return 0;
}
