#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm scf("test");
	
	Bureaucrat b1("Tip", 1);
	Bureaucrat b2("Top", 50);
	Bureaucrat b3("Hip", 100);
	Bureaucrat b4("Hop", 150);
	
	b4.executeForm(scf);
	b4.signForm(scf);
	b3.signForm(scf);
	b3.executeForm(scf);

	RobotomyRequestForm rrf("rrf");

	b1.executeForm(rrf);
	b3.signForm(rrf);
	b2.signForm(rrf);
	b1.executeForm(rrf);

	PresidentialPardonForm ppf("ppf");

	b1.executeForm(ppf);
	b2.signForm(ppf);
	b1.signForm(ppf);
	b1.executeForm(ppf);


	return (0);
}
