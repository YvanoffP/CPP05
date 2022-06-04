#ifndef FORM_H
# define FORM_H

class Form;
# include "Bureaucrat.hpp"

class Form {

	private:
		const std::string	_name;
		bool 				_signed;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		Form (const std::string name, int sign, int execute);
		Form ( const Form &copy );
		virtual ~Form ( void );

		Form &operator=( const Form &right );

		void beSigned ( const Bureaucrat &bureaucrat );
		const std::string getName ( void ) const;
		int getSignGrade ( void ) const;
		int getExecuteGrade ( void ) const;
		bool isSigned ( void ) const;

        virtual void execute( Bureaucrat const & executor ) const = 0;

		class GradeTooHighException: public std::exception {
			virtual const char*  what() const throw();
		};

		class GradeTooLowException: public std::exception {
			virtual const char*  what() const throw();
		};

		class AlreadySignedException: public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream &operator<< ( std::ostream &out, const Form &right );

#endif
