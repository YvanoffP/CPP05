#include "Form.hpp"

/* ==============================================================================
**									CONSTRUCTOR									|
**									DESTRUCTOR									|
** ==============================================================================
*/

Form::Form ( const std::string name, int sign, int execute): _name(name), _signGrade(sign), _executeGrade(execute)
{
	if (_signGrade< 1 || _executeGrade < 1)
		throw Form::GradeTooLowException();
	else if (_signGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooHighException();
	_signed = false;
}

Form::Form ( const Form &copy ): _name(copy.getName()), _signed(copy._signed), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw Form::GradeTooLowException();
	else if (_signGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooHighException();
}

Form::~Form ( void ) {}


/* ==============================================================================
**									OPERATORS									|
** ==============================================================================
*/

Form &Form::operator= ( const Form &right )
{
	if (&right == this)
		return (*this);
	return (*this);
}

std::ostream &operator << ( std::ostream &out, const Form &right )
{
	out << "Form : " << right.getName() << ((right.isSigned()) ? " = Signed" : " = Unsigned")
		<< " | Sign grade required : " << right.getSignGrade()
		<< " | Execution grade required : " << right.getExecuteGrade() << std::endl;
	return (out);
}


/* ==============================================================================
**									FUNCTIONS									|
** ==============================================================================
*/

void Form::beSigned ( const Bureaucrat &bureaucrat )
{
	if (this->_signed == true)
		throw Form::AlreadySignedException();
	else if (bureaucrat.getGrade() > Form::getSignGrade()) // this->_signed == false but already checked before
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const std::string Form::getName ( void ) const
{
	return (_name);
}

int Form::getSignGrade ( void ) const
{
	return (_signGrade);
}

int Form::getExecuteGrade ( void ) const
{
	return (_executeGrade);
}

bool Form::isSigned ( void ) const
{
	return (_signed);
}

const char* Form::GradeTooHighException::what ( void ) const throw()
{
	return ("FormException : Grade too High");
}

const char* Form::GradeTooLowException::what ( void ) const throw()
{
	return ("FormException : Grade too Low");
}

const char* Form::AlreadySignedException::what ( void ) const throw()
{
	return ("FormException : Already signed");
}
