#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat b1("Tip", 1);
		Bureaucrat b2("Top", 50);
		Bureaucrat b3("Hip", 100);
		Bureaucrat b4("Hop", 150);
		
		Form f1("1", 1, 20);
		Form f2("25", 25, 20);
		Form f3("125", 125, 20);
		Form f4("150", 150, 20);

		b1.signForm(f1);
		b1.signForm(f1);
		b2.signForm(f2);
		b1.signForm(f2);
		b4.signForm(f3);
		b3.signForm(f3);
	}
	catch (const std::exception& e) {
		std::cerr << "Unhandled exception: " << e.what() << std::endl;
	}

	return 0;
}
