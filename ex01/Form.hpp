#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(const Form& other);
	Form& operator=(const Form& other) = delete;

	const std::string& getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception 
	{
	public:
		const char* what() const noexcept override 
		{
		return ("Grade is too high!");
		}
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept override 
		{
		return ("Grade is too low!");
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif