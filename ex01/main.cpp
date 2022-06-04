#include "Bureaucrat.hpp"

int    main(void)
{
    Bureaucrat guit("Guit", 8);
	Form form("Formulaire", 10, 15);

	std::cout << "---------- Functions ----------" << std::endl;
	std::cout << "Sign Grade : " << form.getSignGrade() << std::endl;
	std::cout << "Execute Grade : " << form.getExecuteGrade() << std::endl;
	std::cout << form.getName() << std::endl;

	std::cout << "--------- Operator << ---------" << std::endl;
	std::cout << guit;
	std::cout << form;
	std::cout << "isSigned = " << form.isSigned() << std::endl;
	form.beSigned(guit);
	std::cout << "isSigned = " << form.isSigned() << std::endl;
	guit.signForm(form);

	std::cout << "------------- Error -------------" << std::endl;

	try
	{
		Bureaucrat 	guit("Guit", 5);
		Form		form("Formulaire", 0, 0);
		std::cout << guit << std::endl;
		std::cout << form << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;

	try
	{
		Bureaucrat	guit("Guit", 5);
		Form		form("Formulaire", 1000, 5);
		std::cout << guit << std::endl;
		std::cout << form << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;

	try
	{
		Bureaucrat guit("Guit", 8);
		Form		form("Formulaire", 10, 5);
		std::cout << form << std::endl;
		form.beSigned(guit);
		std::cout << form;
		form.beSigned(guit);
		std::cout << form;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;

	try
	{
		Bureaucrat	guit("Guit", 60);
		Form		form("Formulaire", 50, 5);
		guit.signForm(form);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
