/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:47:16 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 14:02:20 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

Brain::Brain(void) {
  std::cout << "[BRAIN] Default constructor called." << std::endl;
  for (int i = 0; i < 100; i++)
    _ideas[i].assign("");
}

Brain::Brain(const Brain &other) {
  std::cout << "[BRAIN] Copy constructor called." << std::endl;

  for (int i = 0; i < 100; i++)
    this->_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other) {
  if (this == &other)
    return (*this);

  std::cout << "[BRAIN] Assingment operator used." << std::endl;

  for (int i = 0; i < 100; i++)
    this->_ideas[i] = other._ideas[i];

  return (*this);
}

void Brain::inputIdea(const unsigned int &id, const std::string &idea) {
  if (id > 99)
    throw std::invalid_argument("Brain::inputIdea: out of bound id.");

  _ideas[id] = idea;
}

void Brain::storeFast(const std::string &idea) {
  int i = -1;

  while (++i < 100)
    if (_ideas[i].empty())
      break;

  _ideas[i] = idea;
}

const std::string &Brain::outputIdea(const unsigned int &id) const {
  if (id > 99)
    throw std::invalid_argument("Brain::outputIdea: out of bound id.");

  return (_ideas[id]);
}

const std::string &Brain::firstThingInMind(void) const {
  int i = -1;

  while (++i < 100)
    if (!_ideas[i].empty())
      return (_ideas[i]);

  return (_ideas[i]);
}

Brain::~Brain(void) { std::cout << "[BRAIN] Destructor called." << std::endl; }
