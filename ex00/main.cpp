#include "Bureaucrat.hpp"

int    main(void)
{
    Bureaucrat employee("Yvan", 3);

	std::cout << "---------- Functions ----------" << std::endl;
	std::cout << employee.getGrade() << std::endl;
	employee.upGrade();
	std::cout << employee.getGrade() << std::endl;
	std::cout << employee.getName() << std::endl;

	std::cout << "--------- Operator << ---------" << std::endl;
	std::cout << employee;
	std::cout << "*** UPGRADE ***" << std::endl;
	employee.upGrade();
	std::cout << employee << std::endl;


	std::cout << "------------- Error -------------" << std::endl;

	try
	{
		Bureaucrat edjie("Edjie", 0);
		std::cout << edjie << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat edjie("Edjie", 1000);
		std::cout << edjie << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat edjie("Edjie", 1);
		std::cout << edjie;
		edjie.upGrade();
		std::cout << edjie << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
