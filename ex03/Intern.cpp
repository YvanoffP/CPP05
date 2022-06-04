#include "Intern.hpp"
#include "Presidential.hpp"
#include "Shrubbery.hpp"
#include "Robotomy.hpp"

Intern::Intern ( void ) {}

Intern::Intern ( const Intern &copy )
{
	*this = copy;
}

Intern::~Intern ( void ) {}

Intern &Intern::operator=( const Intern &right )
{
    (void) right;
	return (*this);
}

Form *Intern::makeForm ( const std::string name, const std::string target ) const {
	std::string form[3] = { "PresidentialForm",
						"ShrubberyForm",
						"RobotomyForm" };
	int i;
	for (i = 0; i < 3; ++i)
    {
		if (name == form[i])
			break ;
	}
	switch (i)
    {
		case 0:
            std::cout << "Intern creates " << name << std::endl;
            return (new Presidential(target));
		case 1:
            std::cout << "Intern creates " << name << std::endl;
            return (new Shrubbery(target));
		case 2:
            std::cout << "Intern creates " << name << std::endl;
            return (new Robotomy(target));
		default :
			std::cerr << "This Form name doesn't exist. Choose between PresidentialForm, ShrubberyForm or RobotomyForm. Thanks." << std::endl;
			return nullptr;
	}
}
