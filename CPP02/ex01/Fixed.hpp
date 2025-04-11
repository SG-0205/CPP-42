/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:51:25 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/11 13:09:40 by sgoldenb         ###   ########.fr       */
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

  int getRawBits(void) const;
  float toFloat(void) const;
  int toInt(void) const;
  void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed_nb);
