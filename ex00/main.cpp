#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Misha", 3);

		Bureaucrat b2 = b1;
		std::cout << "Copied: " << b2 << std::endl;

		++b2;
		std::cout << "After promotion: " << b2 << std::endl;

		b2--;
		std::cout << "After demotion: " << b2 << std::endl;


		Bureaucrat b3("Boss", 1);
		--b3;
		std::cout << "After demotion: " << b3 << std::endl;
		++b3;
		std::cout << "Back to 1: " << b3 << std::endl;
		++b3;
		++b3;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b4("Intern", 149);
		--b4;
		--b4;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
