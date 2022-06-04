#ifndef SHRUBBERY_H
# define SHRUBBERY_H

# include "Form.hpp"
# include "fstream"

class Shrubbery: public Form
{
    public:
        Shrubbery( const std::string target);
        Shrubbery( const Shrubbery &cpy );
        ~Shrubbery( void );

        Shrubbery &operator=( const Shrubbery &rhs );

        const std::string getTarget( void ) const;

        void execute(Bureaucrat const & executor) const;

        class BadOpenException: public std::exception {
            virtual const char * what() const throw();
        };

    private:
        const std::string   _target;
};

#endif
