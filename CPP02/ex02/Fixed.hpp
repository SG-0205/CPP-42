/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:51:25 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/11 15:23:28 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
class Fixed {
private:
  int _value;
  static const int _lenght;

public:
  Fixed(void);
  Fixed(const int to_store);
  Fixed(const float to_store);
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed(void);

  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  Fixed operator++(void);
  Fixed operator++(int);
  Fixed operator--(void);
  Fixed operator--(int);

  static const Fixed &min(const Fixed &f1, const Fixed &f2);
  static Fixed &min(Fixed &f1, Fixed &f2);
  static const Fixed &max(const Fixed &f1, const Fixed &f2);
  static Fixed &max(Fixed &f1, Fixed &f2);

  int getRawBits(void) const;
  float toFloat(void) const;
  int toInt(void) const;
  void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed_nb);
