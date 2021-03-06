#pragma once

template <class A, class B>
struct Pair
{
	A first{};
	B second{};

	Pair()
	{

	}

	constexpr Pair(A a) : first(a) {}

	constexpr Pair(A a, B b) : first(a), second(b) {}

	~Pair()
	{

	}

	bool operator ==(const Pair<A, B>& b) const
	{
		return (this->first == b.first) && (this->second == b.second);
	}

	void operator = (const B b)
	{
		second = b;
	}

};