#pragma once
#ifndef LIST_HPP
#define LIST_HPP

namespace List
{
	// Find indx of an item in a list
	template<typename T>
	int GetIndexOf(std::vector<T> list, T item)
	{
		return std::find(list.begin(), list.end(), item) - list.begin();
	}

	// Find if a list contains an item
	template<typename T>
	bool Contains(std::vector<T> list, T item)
	{
		return std::find(list.begin(), list.end(), item) != list.end();
	}


}

#endif