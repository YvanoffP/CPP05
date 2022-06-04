#include "Presidential.hpp"

Presidential::Presidential(const std::string target): Form("Presidential Form", 145, 137) ,_target(target)
{
}

Presidential::Presidential( const Presidential &cpy ): Form(cpy), _target(cpy.getTarget())
{
}

Presidential &Presidential::operator=( const Presidential &right )
{
    if (&right == this)
        return (*this);
    return (*this);
}

Presidential::~Presidential( void )
{
    std::cout << "Presidential destructor called" << std::endl;
}

const std::string Presidential::getTarget( void ) const
{
    return _target;
}

/*=======================================================================
 *                      EXCEPTION                                       =
 *======================================================================*/

const char *Presidential::BadOpenException::what() const throw()
{
    return ("BadOpenException : can't open file");
}

//========================================================================

void Presidential::execute( Bureaucrat const &executor ) const
{
    std::cout << getTarget() << " has been forgiven by Zaphod Beeblebrox" << std::endl;
    (void) executor;
}
