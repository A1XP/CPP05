#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat
{
private:
	const std::string _name;
	unsigned int _grade;
public:
	Bureaucrat(const std::string& name, unsigned int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other) = delete;

	Bureaucrat&	operator++();
	Bureaucrat	operator++(int);
	Bureaucrat&	operator--();
	Bureaucrat	operator--(int);

	const std::string& getName() const;
	unsigned int getGrade() const;

	class GradeTooHighException : public std::exception 
	{
	public:
		const char* what() const noexcept override 
		{
		return "Grade is too high!";
		}
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept override 
		{
		return "Grade is too low!";
		}
	};
};


std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);

#endif