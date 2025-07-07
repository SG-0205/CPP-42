
#pragma once

#include <limits>
#include <string>
class ScalarConverter {
private:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter(void);

  enum Types { INVALID, PSEUDO, CHAR, INT, FLOAT, DOUBLE };

  static Types _readType(const std::string &arg);
  static void _toInt(const std::string &arg);
  static void _toFloat(const std::string &arg);
  static void _toDouble(const std::string &arg);
  static void _toChar(const std::string &arg);
  static void _readSpecialValue(const std::string &arg);

  static void _printTypeHeader(const std::string &content);
  static void _printImpossible(void);
  static void _printImpossible(const std::string &content);
  static void _printTypeException(const std::string &content);

  static const int MAX_INT;
  static const int MIN_INT;

  static const float MAX_FLOAT;
  static const float MIN_FLOAT;

  static const double MAX_DOUBLE;
  static const double MIN_DOUBLE;

public:
  static void convert(const std::string &str);
};
