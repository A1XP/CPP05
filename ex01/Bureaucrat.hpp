#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <exception>

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other) = delete;

	Bureaucrat&	operator++();
	Bureaucrat	operator++(int);
	Bureaucrat&	operator--();
	Bureaucrat	operator--(int);

	const std::string& getName() const;
	int getGrade() const;

	void signForm(Form& form);

	class GradeTooHighException : public std::exception 
	{
	public:
		const char* what() const noexcept override 
		{
		return ("Bureaucrat grade is too high!");
		}
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept override 
		{
		return ("Bureaucrat grade is too low!");
		}
	};
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);

#endif