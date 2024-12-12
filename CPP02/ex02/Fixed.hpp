#pragma once

#include <ostream>
class Fixed {
public:
  Fixed();
  Fixed(const int to_convert);
  Fixed(const float to_convert);
  Fixed(const Fixed &other);

  void operator=(Fixed const &other);

  bool operator>(const Fixed &n2) const;
  bool operator<(const Fixed &n2) const;
  bool operator>=(const Fixed &n2) const;
  bool operator<=(const Fixed &n2) const;
  bool operator==(const Fixed &n2) const;
  bool operator!=(const Fixed &n2) const;

  int operator+(const Fixed &n2);
  int operator-(const Fixed &n2);
  int operator*(const Fixed &n2);
  int operator/(const Fixed &n2);

  Fixed &operator++(void);
  Fixed &operator--(void);
  Fixed operator++(int);
  Fixed operator--(int);

  int getRawBits(void) const;
  float toFloat(void) const;
  int toInt(void) const;
  void setRawBits(const int raw);
  int getScaleFactor(void) const;

  static Fixed &min(Fixed &n1, Fixed &n2);
  static const Fixed &min(const Fixed &n1, const Fixed &n2);
  static Fixed &max(Fixed &n1, Fixed &n2);
  static const Fixed &max(const Fixed &n1, const Fixed &n2);

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
