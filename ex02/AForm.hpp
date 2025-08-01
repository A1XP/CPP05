#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
protected:
	virtual void executeAction() const = 0;
public:
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	virtual ~AForm();
	AForm(const AForm& other);
	AForm& operator=(const AForm& other) = delete;

	const std::string& getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);
	void execute(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception 
	{
	public:
		const char* what() const noexcept override 
		{
		return ("Form grade is too high!");
		}
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept override 
		{
		return ("Form grade is too low!");
		}
	};

	class FormSignedException : public std::exception
	{
	public:
		const char* what() const noexcept override 
		{
		return ("Form is already signed!");
		}
	};

	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const noexcept override 
		{
		return ("Form is not signed!");
		}
	};
};

std::ostream& operator<<(std::ostream& output, const AForm& form);

#endif