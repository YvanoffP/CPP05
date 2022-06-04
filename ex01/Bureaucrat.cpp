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


// NO Bureaucrat:: before operator : function is outside of class

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

void Bureaucrat::signForm(Form &form) const
{
	if (form.isSigned())
	{
		std::cout << Bureaucrat::getName() << " can't sign " << form.getName()
				<< " because form is already signed." << std::endl;
	}
	else if (form.getSignGrade() < this->_grade)
	{
		std::cout << Bureaucrat::getName() << " cannot sign " << form.getName()
				<< " because his grade is too low." << std::endl;
	}
	else
	{
		std::cout << Bureaucrat::getName() << " signs " << form << std::endl;
		form.beSigned(*this);
	}
}
