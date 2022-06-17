#include "Bureaucrat.hpp"

/* ==================================================================
**							CONSTRUCTOR								|
**							DESTRUCTOR								|
** ==================================================================
*/

Bureaucrat::Bureaucrat ( const std::string name, int grade ): _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat ( const Bureaucrat &copy ): _name(copy.getName()), _grade(copy.getGrade())
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat ( void ) {}


/* =================================================================
**								EXCEPTIONS							|
** ==================================================================
*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("BureaucratException : Grade too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("BureaucratException : Grade too Low");
}


/* ==================================================================
**								OPERATOR							|
** ==================================================================
*/

Bureaucrat &Bureaucrat::operator = ( const Bureaucrat &right )
{
	if (&right == this)
		return (*this);
//	this->_name = right.getName(); DON'T WORK BECAUSE OF CONST STD::STRING
	this->_grade = right.getGrade();
	return (*this);
}

std::ostream &operator << ( std::ostream &out, const Bureaucrat &right )
{
	out << right.getName() << ", bureaucrat grade " << right.getGrade() << "." << std::endl;
	return (out);
}


/* ==================================================================
**								FUNCTIONS							|
** ==================================================================
*/

const std::string Bureaucrat::getName ( void ) const
{
	return (_name);
}

int Bureaucrat::getGrade ( void ) const
{
	return (_grade);
}

void Bureaucrat::downGrade ( void )
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::upGrade ( void )
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooLowException();
}
