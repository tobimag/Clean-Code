/*
 * list_of_pairs.hpp
 *
 *  Created on: Apr 2, 2015
 *      Author: tobimag
 */

#ifndef INCLUDE_LIST_OF_PAIRS_HPP
#define INCLUDE_LIST_OF_PAIRS_HPP

#include <vector>
#include <utility>

template <class T1, class T2>
class ListOfPairs {
public:
	ListOfPairs();

	virtual ~ListOfPairs();

private:
	std::vector<std::pair<T1, T2> > _listOfPairs;
};

#endif /* INCLUDE_LIST_OF_PAIRS_HPP */
