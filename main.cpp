#include <functional>
#include <string>
#include <iostream>


template <typename X,
	typename = typename std::enable_if<0U == std::rank<X>::value>::type>
	constexpr X print(X const& x)
{
	std::cout << std::endl;
	return x;
}

template <typename X,
	typename = typename std::enable_if<0U != std::rank<X>::value>::type>
	constexpr typename std::remove_all_extents<X>::type print(X const& x)
{
	auto it = std::begin(x);
	std::cout << "[" << std::extent<X>::value << "]";
	auto ret = print(*it);

	return ret;
}

int main()
{
	int array1[10];
	size_t array2[1][10];
	double array3[1][10][13][15];

	print(array1);
	print(array2);
	print(array3);

    return 0;
}
