#include "Robotomy.hpp"

Robotomy::Robotomy(const std::string target): Form("Robotomy Form", 145, 137) ,_target(target)
{
}

Robotomy::Robotomy( const Robotomy &cpy ): Form(cpy), _target(cpy.getTarget())
{
}

Robotomy &Robotomy::operator=( const Robotomy &right )
{
    if (&right == this)
        return (*this);
    return (*this);
}

Robotomy::~Robotomy( void )
{
    std::cout << "Robotomy destructor called" << std::endl;
}

const std::string Robotomy::getTarget( void ) const
{
    return _target;
}

/*=======================================================================
 *                      EXCEPTION                                       =
 *======================================================================*/

const char *Robotomy::BadOpenException::what() const throw()
{
    return ("BadOpenException : can't open file");
}

//========================================================================

void Robotomy::execute( Bureaucrat const &executor ) const
{
    std::cout << "BRRRRRRRRRRRrrrrrrrrrrrrrrrrrrrrrrrrrrrr" << std::endl;
	srand(time(NULL));
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomised" << std::endl;
    else
        std::cout << "Robotomisation failed" << std::endl;
    (void) executor;
}
