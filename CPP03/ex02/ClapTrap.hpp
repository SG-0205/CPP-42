#pragma once

#include <string>

enum PointsType { HIT, ENERGY, ATTACK_DMG, _SIZE };

class ClapTrap {
protected:
  std::string _name;
  int _hit_points;
  int _energy_points;
  int _attack_damage;

  void _message(const std::string &message);
  void _message(const std::string &child_prefix, const std::string &message);
  const std::string &_getName(void) const;
  const int &_getPoints(const PointsType &type) const;
  void _incrementPoints(const PointsType &type);
  void _decrementPoints(const PointsType &type);

public:
  ClapTrap(const std::string &name);
  ClapTrap(const ClapTrap &other);
  ClapTrap &operator=(const ClapTrap &other);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void printState(void);

  ~ClapTrap(void);
};
