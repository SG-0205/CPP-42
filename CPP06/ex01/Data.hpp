#pragma once

#include <string>

enum Level { PISCINER, STUDENT, ALUMNI };

struct Data {
private:
  std::string _name;
  unsigned int _age;
  bool _active;
  Level _level;

public:
  Data(void);
  Data(const std::string &name, const unsigned int &age, const bool &is_active,
       const Level &level);
  Data(const Data &other);
  Data &operator=(const Data &other);
  ~Data(void);

  const std::string &GetName(void) const;
  const unsigned int &GetAge(void) const;
  const bool &IsActive(void) const;
  const Level &GetLevel(void) const;
  const std::string GetLevelString(void) const;

  void setName(const std::string &name);
  void setAge(const unsigned int &age);
  void setActivityStatus(const bool &is_active);
  void setLevel(const Level &level);

  void print(void);
};
