#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm test("test");
	
	Bureaucrat b1("Tip", 1);
	Bureaucrat b2("Top", 50);
	Bureaucrat b3("Hip", 100);
	Bureaucrat b4("Hop", 150);
	
	b4.executeForm(test);
	b4.signForm(test);
	b3.signForm(test);
	b3.executeForm(test);

	return (0);
}
