#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	_isSigned = false;
	std::cout << "Form " << _name  << " with grade to sign : " << _gradeToSign << " and grade to execute : " << _gradeToExecute << " was created." << std::endl;

}

Form::~Form()
{
	std::cout << "Form " << _name  << " with grade to sign : " << _gradeToSign << " and grade to execute : " << _gradeToExecute << " was deleted." << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form " << _name  << " with grade to sign : " << _gradeToSign << " and grade to execute : " << _gradeToExecute << " was copied." << std::endl;
}

const std::string& Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned ==true)
		throw FormSignedException();
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& output, const Form& form)
{
	output << "Form " << form.getName()
		<< " (signed: " << (form.isSigned() ? "yes" : "no")
		<< "), grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute() << ".";
	return (output);
}
