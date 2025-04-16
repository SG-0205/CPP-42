/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:46:11 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 15:59:41 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinkedList.hpp"
#include "AMateria.hpp"
#include <cstddef>
#include <iterator>
#include <pthread.h>
#include <stdexcept>

ListNode *LinkedList::_head[2] = {NULL, NULL};

LinkedList::LinkedList(void) {}

LinkedList::LinkedList(const LinkedList &other) { static_cast<void>(other); }

LinkedList &LinkedList::operator=(const LinkedList &other) {
  static_cast<void>(other);
  return (*this);
}

LinkedList::~LinkedList(void) { purgeAll(); }

ListNode *LinkedList::_newNode(void *ptr) {
  ListNode *new_node = new ListNode;

  new_node->ptr = ptr;
  new_node->next = NULL;

  return (new_node);
}

ListNode *LinkedList::_getLast(const dataTypes &type) const {
  if (type > CHARACTERS)
    throw std::invalid_argument("LinkedList::_getLast: invalid type.");
  else if (!_head[type])
    return (NULL);

  ListNode *tmp = _head[type];

  while (tmp->next)
    tmp = tmp->next;

  return (tmp);
}

void LinkedList::addPtr(void *ptr, const dataTypes &type) {
  if (type > CHARACTERS)
    throw std::invalid_argument("LinkedList::addPtr: invalid type");
  if (!_head[type])
    _head[type] = _newNode(ptr);
  else
    _getLast(type)->next = _newNode(ptr);
}

void LinkedList::purge(const dataTypes &type) {
  if (type > CHARACTERS)
    throw std::invalid_argument("LinkedList::purge: invalid type.");
  if (!_head[type])
    return;

  ListNode *tmp = _head[type];
  ListNode *prev = NULL;

  while (tmp) {
    if (prev)
      delete prev;

    switch (type) {
    case (MATERIA):
      if (tmp->ptr)
        delete static_cast<AMateria *>(tmp->ptr);
      break;
    case (CHARACTERS):
      if (tmp->ptr)
        delete static_cast<ICharacter *>(tmp->ptr);
      break;
    default:
      break;
    }

    prev = tmp;
    tmp = tmp->next;
  }
  if (prev)
    delete prev;
}

ListNode *LinkedList::getNode(void *ptr, const dataTypes &type) {
  if (!ptr)
    throw std::invalid_argument("LinkedList::getNode: null pointer as param");

  ListNode *tmp = NULL;

  switch (type) {
  case (MATERIA):
    tmp = _head[MATERIA];
    break;
  case (CHARACTERS):
    tmp = _head[CHARACTERS];
    break;
  default:
    throw std::invalid_argument("LinkedList::getNode: invalid type.");
    break;
  }
  if (!tmp)
    return (NULL);

  while (tmp) {
    if (tmp->ptr == ptr)
      return (tmp);
    tmp = tmp->next;
  }

  return (NULL);
}

void LinkedList::purgeAll(void) {
  if (_head[MATERIA])
    purge(MATERIA);
  if (_head[CHARACTERS])
    purge(CHARACTERS);
}
