#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;

	AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
	AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
	AForm* form4 = someRandomIntern.makeForm("undefined form", "Nobody");

	std::cout << std::endl;

	// Убедимся, что формы действительно созданы
	if (form1) {
		std::cout << "Created: " << form1->getName() << " for " << "Home" << std::endl;
		delete form1;
	}
	if (form2) {
		std::cout << "Created: " << form2->getName() << " for " << "Bender" << std::endl;
		delete form2;
	}
	if (form3) {
		std::cout << "Created: " << form3->getName() << " for " << "Marvin" << std::endl;
		delete form3;
	}
	if (!form4) {
		std::cout << "Form 4 creation failed as expected." << std::endl;
	}

	return (0);
}
