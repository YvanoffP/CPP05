#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>
class Intern;
# include "Form.hpp"

class Intern {

	public:
		Intern ( void );
		Intern ( const Intern &copy );
		~Intern ( void );

		Intern &operator=( const Intern &right );

		Form* makeForm ( const std::string name, const std::string target ) const;
};

#endif
