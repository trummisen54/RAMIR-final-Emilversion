#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "AbstractCounting.hpp"
#include "Tools.hpp"

#include <opencv2\opencv.hpp>

class COUNTER: public AbstractCounting
{
	public:
		COUNTER(Data *data);
		~COUNTER();

		// Inherited via AbstractCounting
		void count();
		void saveSettings();

	private:
		int left2Right;
		int right2Left;

};

#endif // !COUNTER_HPP