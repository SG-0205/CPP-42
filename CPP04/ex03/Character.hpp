/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:20:41 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 09:31:14 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
class Character : public ICharacter {
private:
  enum slotIterators {
    INCR,
    DECR,
  };
  std::string _name;
  AMateria *_inventory[4];
  unsigned int _free_slot_idx;

  AMateria **_initInventory(AMateria **inventory);
  void _changeActiveSlot(const slotIterators &operation);
  const unsigned int &_getActiveSlotId(void) const;
  bool _isInventoryFull(void) const;
  bool _isInventoryEmpty(void) const;
  AMateria *_getItem(const unsigned int &idx) const;
  void _sortInventory(void);

public:
  Character(void);
  Character(const std::string &name);
  Character(const Character &other);
  Character &operator=(const Character &other);
  ~Character(void);

  const std::string &getName(void) const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
  void printInventory(void) const;
};
