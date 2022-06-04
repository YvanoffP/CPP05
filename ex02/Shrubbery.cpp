#include "Shrubbery.hpp"

Shrubbery::Shrubbery(const std::string target): Form("Shrubbery Form", 145, 137) ,_target(target)
{
}

Shrubbery::Shrubbery( const Shrubbery &cpy ): Form(cpy), _target(cpy.getTarget())
{
}

Shrubbery &Shrubbery::operator=( const Shrubbery &right )
{
    if (&right == this)
        return (*this);
    return (*this);
}

Shrubbery::~Shrubbery( void )
{
    std::cout << "Shrubbery destructor called" << std::endl;
}

const std::string Shrubbery::getTarget( void ) const
{
    return _target;
}

/*=======================================================================
 *                      EXCEPTION                                       =
 *======================================================================*/

const char *Shrubbery::BadOpenException::what() const throw()
{
    return ("BadOpenException : can't open file");
}

//========================================================================

void Shrubbery::execute( Bureaucrat const &executor ) const
{
    std::ofstream file( _target + "_shrubbery");
    if(file.is_open())
    {
        file << "      ,.," << std::endl;
        file << "      MMMM_    ,..," << std::endl;
        file << "        \"_ \"__\"MMMMM          ,...,," << std::endl;
        file << " ,..., __.\" --\"    ,.,     _-\"MMMMMMM" << std::endl;
        file << "MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"" << std::endl;
        file << " \"\"\"\"\"    \"\" , \\_.   \"_. .\"" << std::endl;
        file << "        ,., _\"__ \\__./ .\"" << std::endl;
        file << "       MMMMM_\"  \"_    ./" << std::endl;
        file << "        ''''      (    )" << std::endl;
        file << " ._______________.-'____\"---._." << std::endl;
        file << "  \\                          /" << std::endl;
        file << "   \\________________________/" << std::endl;
        file << "   (_)                    (_)" << std::endl;
        if (file.bad())
        {
            file.close();
            throw Shrubbery::BadOpenException();
            return ;
        }
        file.close();
    }
    else
        throw Shrubbery::BadOpenException();
    (void) executor;
}
