#include "Contact.hpp"
#include <stdexcept>

Contact::Contact(const std::string inputs[5]) {
  int i = -1;
  while (++i < 5)
    if (inputs[i].empty() || _emptyField(inputs[i]))
      throw std::invalid_argument("EMPTY FIELD BLOCKED CREATION OF CONTACT");
    else
      _fields[i] = inputs[i];
}

Contact &Contact::operator=(const Contact &other) {
  for (int i = 0; i < 5; i++)
    this->_fields[i] = other[i];
  return (*this);
}

const std::string &Contact::operator[](const int &id) const {
  if (id < 0 || id > static_cast<int>(D_SECRET))
    throw std::invalid_argument(
        "Contact::operator[]: invalid contact field id.");

  return (_fields[id]);
}

const std::string &Contact::operator[](const e_contact_field_key &key) const {
  if (key < F_NAME || key > D_SECRET)
    throw std::invalid_argument(
        "Contact::operator[]: invalid contact field key.");

  return (_fields[static_cast<int>(key)]);
}

const std::string &Contact::getField(const e_contact_field_key &key) const {
  return ((*this)[key]);
}
