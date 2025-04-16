/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:27:34 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 09:52:27 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

void Character::_changeActiveSlot(const slotIterators &operation) {
  switch (operation) {
  case (INCR):
    if (_free_slot_idx < 3)
      _free_slot_idx++;
    break;
  case (DECR):
    if (_free_slot_idx > 0)
      _free_slot_idx--;
    break;
  default:
    throw std::invalid_argument(
        "Character::_changeActiveSlot: invalid operation.");
    break;
  }
}

bool Character::_isInventoryFull(void) const {
  if (!_getItem(3))
    return (false);
  else
    return (true);
}

bool Character::_isInventoryEmpty(void) const {
  if (!_getItem(0))
    return (true);
  else
    return (false);
}

AMateria **Character::_initInventory(AMateria **inventory) {
  if (!inventory)
    throw std::invalid_argument(
        "Character::_initInventory: NULL pointer as param.");

  for (unsigned int i = 0; i < 4; i++)
    inventory[i] = NULL;

  return (inventory);
}

AMateria *Character::_getItem(const unsigned int &idx) const {
  if (idx > 3)
    throw std::invalid_argument("Character::_getItem: id out of bounds.");

  return (_inventory[idx]);
}

const unsigned int &Character::_getActiveSlotId(void) const {
  return (_free_slot_idx);
}

void Character::_sortInventory(void) {
  bool null_ptr_found = false;
  unsigned int first_free_slot = 5;

  for (unsigned int i = 0; i < 4; i++) {
    if (_getItem(i) && null_ptr_found && first_free_slot > i)
      _inventory[first_free_slot] = _inventory[i], _inventory[i] = NULL;
    if (!_getItem(i))
      null_ptr_found = true, first_free_slot = i;
  }

  _free_slot_idx = first_free_slot;
}

Character::Character(void) : _name("def"), _free_slot_idx(0) {
  _initInventory(_inventory);
}

Character::Character(const std::string &name) : _name(name), _free_slot_idx(0) {
  _initInventory(_inventory);
}

Character::Character(const Character &other)
    : _name(other.getName()), _free_slot_idx(other._free_slot_idx) {
  _initInventory(_inventory);
  for (unsigned int i = 0; i < other._free_slot_idx + 1; i++)
    if (other._inventory[i])
      this->_inventory[i] = other._inventory[i]->clone();
  _sortInventory();
}

Character &Character::operator=(const Character &other) {
  if (this == &other)
    return (*this);

  this->_free_slot_idx = other._free_slot_idx;
  this->_name = other.getName();
  for (unsigned int i = 0; i < other._free_slot_idx + 1; i++)
    if (other._inventory[i])
      this->_inventory[i] = other._inventory[i]->clone();

  return (*this);
}

const std::string &Character::getName(void) const { return (_name); }

void Character::equip(AMateria *m) {
  if (!m)
    throw std::invalid_argument("Character::equip: null pointer as param.");

  _inventory[_getActiveSlotId()] = m;
  _changeActiveSlot(INCR);
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3)
    throw std::invalid_argument("Character::unequip: invalid id provided.");

  if (!_getItem(idx))
    return;
  else
    _inventory[idx] = NULL;

  _sortInventory();
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx > 3)
    throw std::invalid_argument("Character::use: invalid id provided.");

  _getItem(idx)->use(target);
  unequip(idx);
}

void Character::printInventory(void) const {
  std::cout << "---Inventory for character " << getName() << "---" << '\n';
  for (unsigned int i = 0; i < 4; i++)
    if (_getItem(i))
      std::cout << '[' << i << "]\t" << _inventory[i]->getType() << '\n';

  std::cout << std::endl;
}

Character::~Character(void) {}
