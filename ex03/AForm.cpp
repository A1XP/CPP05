#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	_isSigned = false;
	std::cout << "Form " << _name  << " with grade to sign : " << _gradeToSign << " and grade to execute : " << _gradeToExecute << " was created." << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form " << _name  << " with grade to sign : " << _gradeToSign << " and grade to execute : " << _gradeToExecute << " was deleted." << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form " << _name  << " with grade to sign : " << _gradeToSign << " and grade to execute : " << _gradeToExecute << " was copied." << std::endl;
}

const std::string& AForm::getName() const
{
	return (_name);
}

bool AForm::isSigned() const
{
	return (_isSigned);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned ==true)
		throw FormSignedException();
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const 
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

std::ostream& operator<<(std::ostream& output, const AForm& form)
{
	output << "Form " << form.getName()
		<< " (signed: " << (form.isSigned() ? "yes" : "no")
		<< "), grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute() << ".";
	return (output);
}
