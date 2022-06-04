#ifndef ROBOTOMY_H
# define ROBOTOMY_H

# include "Form.hpp"
# include "fstream"

class Robotomy: public Form
{
    public:
        Robotomy( const std::string target);
        Robotomy( const Robotomy &cpy );
        ~Robotomy( void );

        Robotomy &operator=( const Robotomy &rhs );

        const std::string getTarget( void ) const;

        void execute(Bureaucrat const & executor) const;

        class BadOpenException: public std::exception {
            virtual const char * what() const throw();
        };

    private:
        const std::string   _target;
};

#endif
