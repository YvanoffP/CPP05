//#include "Bureaucrat.hpp"
#include "Shrubbery.hpp"
#include "Presidential.hpp"
#include "Robotomy.hpp"

#include "Intern.hpp"

int main (void)
{
	try
	{
		Intern intern;
		Form *form;
		Bureaucrat guit("Guit", 5);

		form = intern.makeForm("PresidentialForm", "Yvan");
		guit.signForm(*form);
		guit.executeForm(*form);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Intern intern;
		Form *form;
		Bureaucrat guit("Guit", 50);

		form = intern.makeForm("Presidential Request", "Yvan");
		form = intern.makeForm("RobotomyForm", "Yvan");

		guit.signForm(*form);
		guit.executeForm(*form);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
