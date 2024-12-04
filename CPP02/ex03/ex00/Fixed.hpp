#pragma once

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed &operator=(Fixed const &other);

  int getRawBits(void);
  void setRawBits(const int raw);

  ~Fixed();

private:
  int _value;
  static const int _decimals_bit_count;
  enum log_type {
    DEF_CONSTRUCTOR,
    COPY_CONSTRUCTOR,
    COPY_ASSIGNEMENT,
    GETRB,
    SETRB,
    DESTRUCTOR
  };
};
