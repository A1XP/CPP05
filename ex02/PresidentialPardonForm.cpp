#include "PresidentialPardonForm.hpp"
#include <random>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm was created." << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm was deleted." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm was copied." << std::endl;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << _target << "  has been pardoned by Zaphod Beeblebrox." << std::endl;
}
