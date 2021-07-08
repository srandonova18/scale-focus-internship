#pragma once

template <class T>
bool safeCin(T& data)
{
	if (!(std::cin >> data))
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		return false;
	}

	return true;
};
