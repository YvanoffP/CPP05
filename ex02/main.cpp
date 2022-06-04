//#include "Bureaucrat.hpp"
#include "Shrubbery.hpp"
#include "Presidential.hpp"
#include "Robotomy.hpp"

int    main(void)
{
	try
	{
        Bureaucrat jeanmi("Guit", 1);
        Robotomy form("Robotomise me");

        jeanmi.executeForm( form );
        jeanmi.signForm( form );
        jeanmi.executeForm( form );

	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

    	try
	{
		Bureaucrat	edjie("Edjie", 1);
		Shrubbery test("chevre");

		edjie.signForm(test);
		edjie.executeForm(test);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	edjie("Edjie", 1);
		Robotomy Yvan("Yvan");

		edjie.signForm(Yvan);
		edjie.executeForm(Yvan);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	edjie("Edjie", 1);
		Presidential presid("Macron");

		edjie.signForm(presid);
		edjie.executeForm(presid);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	edjie("Edjie", 20);
		Presidential presid("Macron");

		edjie.signForm(presid);
		edjie.executeForm(presid);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
