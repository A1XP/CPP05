#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern was created." << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern was deleted." << std::endl;
}

static AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	typedef AForm* (*FormCreator)(const std::string&);

	struct FormType
	{
		const char* name;
		FormCreator create;
	};

	FormType forms[] = 
	{
		{"shrubbery creation", createShrubbery},
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPardon}
	};

	for (size_t i = 0; i < sizeof(forms) / sizeof(forms[0]); ++i)
	{
		if (formName == forms[i].name) 
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].create(target);
		}
	}

	std::cerr << "Intern couldn't find the form: " << formName << std::endl;
	return nullptr;
}