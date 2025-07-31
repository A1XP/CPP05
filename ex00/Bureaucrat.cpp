#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name) , _grade(grade)
{
	std::cout << "Bureaucrat " <<_name << " with grade " << _grade << " was created." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " <<_name << " with grade " << _grade << " was deleted." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat " <<_name << " with grade " << _grade << " was copied." << std::endl;
}

Bureaucrat&	Bureaucrat::operator++()
{
	if (_grade < 2)
		throw GradeTooHighException();
	_grade--;
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	if (_grade < 2)
		throw GradeTooHighException();
	Bureaucrat temp(*this);
	_grade--;
	return (temp);
}

Bureaucrat&	Bureaucrat::operator--()
{
	if (_grade > 149)
		throw GradeTooLowException();
	_grade++;
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int)
{
	if (_grade > 149)
		throw GradeTooLowException();
	Bureaucrat temp(*this);
	_grade++;
	return (temp);
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat)
{
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (output);
}