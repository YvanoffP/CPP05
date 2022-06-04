#ifndef PRESIDENTIAL_H
# define PRESIDENTIAL_H

# include "Form.hpp"
# include "fstream"

class Presidential: public Form
{
    public:
        Presidential( const std::string target);
        Presidential( const Presidential &cpy );
        ~Presidential( void );

        Presidential &operator=( const Presidential &rhs );

        const std::string getTarget( void ) const;

        void execute(Bureaucrat const & executor) const;

        class BadOpenException: public std::exception {
            virtual const char * what() const throw();
        };

    private:
        const std::string   _target;
};

#endif
