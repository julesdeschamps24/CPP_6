#include "Bureaucrat.hpp"

int main()
{
    
    try {
        Bureaucrat a("Jules", 160);
    } catch (const std::string err) {
        std::cerr << err << std::endl;
    } catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}

