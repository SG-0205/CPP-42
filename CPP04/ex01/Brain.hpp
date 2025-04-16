/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:43:07 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 13:12:38 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
class Brain {
protected:
  std::string _ideas[100];

public:
  Brain(void);
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);
  ~Brain(void);

  void inputIdea(const unsigned int &id, const std::string &idea);
  void storeFast(const std::string &idea);
  const std::string &outputIdea(const unsigned int &id) const;
  const std::string &firstThingInMind(void) const;
};
