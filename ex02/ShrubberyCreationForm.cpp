#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm was created." << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm was deleted." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm was copied." << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream outFile(_target + "_shrubbery");
    if (!outFile)
    {
        std::cerr << "Error: Could not open file " << _target << "_shrubbery for writing.\n";
        return;
    }

    outFile <<
    "       _-_\n"
    "    /~~   ~~\\\n"
    " /~~         ~~\\\n"
    "{               }\n"
    " \\  _-     -_  /\n"
    "   ~  \\\\ //  ~\n"
    "_- -   | | _- _\n"
    "  _ -  | |   -_\n"
    "      // \\\\\n";

    outFile.close();
}
