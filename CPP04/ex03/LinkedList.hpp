/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:41:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 16:11:39 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>
enum dataTypes { MATERIA, CHARACTERS, DT_SIZE };

struct ListNode {
  void *ptr;
  ListNode *next;
};

class LinkedList {
private:
  ListNode *_newNode(void *ptr);
  ListNode *_getLast(const dataTypes &type) const;

  static ListNode *_head[DT_SIZE];

public:
  LinkedList(void);
  LinkedList(const LinkedList &other);
  LinkedList &operator=(const LinkedList &other);
  ~LinkedList(void);

  void addPtr(void *ptr, const dataTypes &type);
  ListNode *getNode(void *ptr, const dataTypes &type);
  void purge(const dataTypes &type);
  void purgeAll(void);
};
