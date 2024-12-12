#pragma once

#include <ostream>
class Fixed {
public:
  Fixed();
  Fixed(const int to_convert);
  Fixed(const float to_convert);
  Fixed(const Fixed &other);

  void operator=(Fixed const &other);

  int getRawBits(void) const;
  float toFloat(void) const;
  int toInt(void) const;
  void setRawBits(const int raw);
  int getScaleFactor(void) const;

  ~Fixed();

private:
  int _value;
  static const int _bit_scale;

  enum log_type {
    DEF_CONSTRUCTOR,
    INT_CONSTRUCTOR,
    FLOAT_CONSTRUCTOR,
    COPY_CONSTRUCTOR,
    COPY_ASSIGNEMENT,
    DESTRUCTOR
  };
  void _writeLog(log_type type) const;
  int _scale_factor(void) const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &number);
