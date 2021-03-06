
#pragma once

namespace vg
{
	/**
		Provides some math related extension functions
	*/
	class Math
	{
	public:
		/**
			Return the absolute of a value
			@param value a value
			@return the absolute
		*/
		template<class T>
		static T abs(T value)
		{
			return value < 0 ? -value : value;
		}

		static float radianToDegrees(float radian);

		static float degreesToRadians(float degrees);

	private:
	};
}
