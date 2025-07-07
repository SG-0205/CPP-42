#include "ScalarConverter.hpp"
#include "colors.h"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>

const int ScalarConverter::MAX_INT = std::numeric_limits<int>::max();
const int ScalarConverter::MIN_INT = std::numeric_limits<int>::min();

const float ScalarConverter::MAX_FLOAT = std::numeric_limits<float>::max();
// std::numeric_limits<floats>min() renvoie la valeur positive la plus petite;
const float ScalarConverter::MIN_FLOAT = -MAX_FLOAT;

const double ScalarConverter::MAX_DOUBLE = std::numeric_limits<double>::max();
const double ScalarConverter::MIN_DOUBLE = std::numeric_limits<double>::min();

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  static_cast<void>(other);

  return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

static inline bool isChar(const std::string &arg) {
  switch (arg.length()) {
  case (1):
    return (!std::isdigit(arg[0]));
    break;
  case (3):
    return (arg[0] == '\'' && arg[2] == '\'');
    break;
  default:
    return (false);
  }
}

static inline bool isInt(const std::string &arg) {
  bool signed_int = false;

  if (arg[0] == '+' || arg[0] == '-')
    signed_int = true;

  if ((signed_int && arg.length() > 11) || (!signed_int && arg.length() > 10))
    return (false);

  for (size_t i = (signed_int ? 1 : 0); i < arg.length(); i++)
    if (!std::isdigit(arg[i]))
      return (false);

  return (true);
}

static inline bool isFloat(const std::string &arg) {
  size_t dot_position = arg.find('.');
  size_t f_position = arg.find('f');
  if (f_position == std::string::npos)
    f_position = arg.find('F');
  bool signed_float = (arg[0] == '-');

  if (f_position == std::string::npos)
    return (false);
  if (dot_position == std::string::npos && f_position == std::string::npos)
    return (false);

  if (f_position != arg.length() - 1)
    return (false);

  unsigned int point_count = 0, f_count = 0;
  for (size_t i = (signed_float ? 1 : 0); i < arg.length(); i++) {
    if (!std::isdigit(arg[i]) && arg[i] != '.' && arg[i] != 'f' &&
        arg[i] != 'F')
      return (false);
    else if (arg[i] == '.')
      point_count++;
    else if (arg[i] == 'f' || arg[i] == 'F')
      f_count++;
  }

  return (point_count == 1 && f_count == 1);
}

static inline bool isDouble(const std::string &arg) {
  size_t dot_position = arg.find('.');
  bool signed_double = (arg[0] == '-');

  if (dot_position == std::string::npos)
    return (false);

  unsigned int point_count = 0;
  for (size_t i = (signed_double ? 1 : 0); i < arg.length(); i++) {
    if (!std::isdigit(arg[i]) && arg[i] != '.')
      return (false);
    if (arg[i] == '.')
      point_count++;
  }

  return (point_count == 1);
}

static inline bool isSpecial(const std::string &arg) {
  return (arg == "nan" || arg == "nanf" || arg == "+inf" || arg == "+inff" ||
          arg == "-inf" || arg == "-inff");
}

ScalarConverter::Types ScalarConverter::_readType(const std::string &arg) {
  if (arg.empty())
    throw std::runtime_error("ScalarConverter::_readType: empty arg.");

  size_t dot_position = arg.find('.');
  size_t f_position = arg.find('.');
  if (f_position == std::string::npos)
    f_position = arg.find('F');

  if (dot_position == std::string::npos) {
    if (isInt(arg))
      return (INT);
    else if (isChar(arg))
      return (CHAR);
    else if (isSpecial(arg))
      return (PSEUDO);
  } else if (dot_position != std::string::npos &&
             f_position != std::string::npos) {
    if (isFloat(arg))
      return (FLOAT);
  } else if (dot_position != std::string::npos &&
             f_position == std::string::npos) {
    if (isDouble(arg))
      return (DOUBLE);
  }

  return (INVALID);
}

void ScalarConverter::_printTypeHeader(const std::string &content) {
  std::cout << UNDERLINE BOLD << content + "\n\t" << RESET;
}

void ScalarConverter::_printImpossible(void) {
  std::cout << RED "Impossible" RESET << '\n';
}

void ScalarConverter::_printImpossible(const std::string &content) {
  std::cout << RED "Impossible : " + content + RESET << '\n';
}

void ScalarConverter::_printTypeException(const std::string &content) {
  std::cout << YELLOW ITALIC + content + RESET << '\n';
}

void ScalarConverter::_toDouble(const std::string &arg) {
  double converted = atof(arg.c_str());
  // Elimine les erreurs de precision de conversion float/double
  bool has_no_floating_part =
      std::fabs(converted - static_cast<int>(converted)) < 1e-13;

  _printTypeHeader("Char:");
  if (converted < 0.0 || converted > 127.0)
    _printImpossible();
  else {
    if (!std::isprint(converted))
      _printTypeException("Non printable...");
    else
      std::cout << '[' << static_cast<char>(converted) << ']' << '\n';
  }

  _printTypeHeader("Int:");
  if (converted < ScalarConverter::MIN_INT ||
      converted > ScalarConverter::MAX_INT)
    _printImpossible();
  else
    std::cout << static_cast<int>(converted) << '\n';

  _printTypeHeader("Float:");
  if (converted < ScalarConverter::MIN_FLOAT ||
      converted > ScalarConverter::MAX_FLOAT)
    _printImpossible();
  else
    std::cout << static_cast<float>(converted)
              << (has_no_floating_part ? ".0f" : "f") << '\n';

  _printTypeHeader("Double:");
  if (converted < ScalarConverter::MIN_DOUBLE ||
      converted > ScalarConverter::MAX_DOUBLE)
    _printImpossible();
  else
    std::cout << converted << '\n';
}

void ScalarConverter::_toChar(const std::string &arg) {
  char converted = (arg.length() == 1 ? arg[0] : arg[1]);

  _printTypeHeader("Char:");
  if (!std::isprint(converted))
    _printTypeException("Non printable...");
  else {
    std::cout << '[' << converted << ']' << '\n';
    _printTypeHeader("Int:");
    std::cout << static_cast<int>(converted) << '\n';
    _printTypeHeader("Float:");
    std::cout << static_cast<float>(converted) << ".0f" << '\n';
    _printTypeHeader("Double:");
    std::cout << static_cast<double>(converted) << ".0" << '\n';
  }
}

void ScalarConverter::_toInt(const std::string &arg) {
  int64_t converted = atol(arg.c_str());

  _printTypeHeader("Char:");
  if (converted < 0 || converted > 127)
    _printImpossible();
  else {
    if (!std::isprint(converted))
      _printTypeException("Non printable...");
    else
      std::cout << '[' << static_cast<char>(converted) << ']' << '\n';
  }

  _printTypeHeader("Int:");
  if (converted < ScalarConverter::MIN_INT ||
      converted > ScalarConverter::MAX_INT)
    _printImpossible();
  else
    std::cout << static_cast<int>(converted) << '\n';

  _printTypeHeader("Float:");
  std::cout << static_cast<float>(converted) << ".0f" << '\n';
  _printTypeHeader("Double:");
  std::cout << static_cast<double>(converted) << ".0" << '\n';
}

void ScalarConverter::_toFloat(const std::string &arg) {
  float converted = atof(arg.c_str());
  std::cout << "FLOAT = " << converted << '\n'
            << "MAX_FLOAT = " << ScalarConverter::MAX_FLOAT << '\n'
            << "MIN_FLOAT = " << ScalarConverter::MIN_FLOAT << '\n';
  bool has_no_floating_part =
      std::fabs(converted - static_cast<int>(converted)) < 1e-13;

  _printTypeHeader("Char:");
  if (converted < 0 || converted > 127)
    _printImpossible();
  else {
    if (!std::isprint(converted))
      _printTypeException("Non printable...");
    else
      std::cout << '[' << static_cast<char>(converted) << ']' << '\n';
  }

  _printTypeHeader("Int:");
  if (static_cast<int64_t>(converted) < ScalarConverter::MIN_INT ||
      static_cast<int64_t>(converted) > ScalarConverter::MAX_INT)
    _printImpossible();
  else
    std::cout << static_cast<int>(converted) << '\n';

  _printTypeHeader("Float:");
  if (converted < ScalarConverter::MIN_FLOAT ||
      converted > ScalarConverter::MAX_FLOAT)
    _printImpossible();
  else
    std::cout << converted << (has_no_floating_part ? ".0f" : "f") << '\n';

  _printTypeHeader("Double:");
  std::cout << static_cast<double>(converted)
            << (has_no_floating_part ? ".0" : "") << '\n';
}

void ScalarConverter::_readSpecialValue(const std::string &arg) {
  _printTypeHeader("Char:");
  _printImpossible();
  _printTypeHeader("Int:");
  _printImpossible();

  if (arg == "+inf" || arg == "+inff") {
    _printTypeHeader("Float:");
    std::cout << "+inff" << '\n';
    _printTypeHeader("Double:");
    std::cout << "+inf" << '\n';
  } else if (arg == "-inf" || arg == "-inff") {
    _printTypeHeader("Float:");
    std::cout << "-inff" << '\n';
    _printTypeHeader("Double:");
    std::cout << "-inf" << '\n';
  } else if (arg == "nan" || arg == "nanf") {
    _printTypeHeader("Float:");
    std::cout << "nanf" << '\n';
    _printTypeHeader("Double:");
    std::cout << "nan" << '\n';
  }
}

void ScalarConverter::convert(const std::string &str) {
  if (str.empty())
    throw std::runtime_error("ScalarConverter::convert: empty argument.");

  switch (_readType(str)) {
  case (INT):
    _toInt(str);
    break;
  case (FLOAT):
    _toFloat(str);
    break;
  case (DOUBLE):
    _toDouble(str);
    break;
  case (CHAR):
    _toChar(str);
    break;
  case (PSEUDO):
    _readSpecialValue(str);
    break;
  case (INVALID):
    throw std::invalid_argument("ScalarConverter::convert: invalid argument");
    break;
  }
}
