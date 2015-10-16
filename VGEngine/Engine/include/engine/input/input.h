
#pragma once

//#include "engine/platforms/android/android_native_app_glue.h"
namespace vg
{
	/**
	Class used to call inputs
	*/
	namespace input
	{
		class Input
		{
		public:
			/**
			Sets androids sensor with the given parameters
			*/
			static void setSensor(float x, float y, float z);

			/**
			Sets sensors angle with the given parameters
			*/
			static void setAngles(float x, float y, float z);

			/**
			@return Returns sensors X coordinate
			*/
			static float getSensorX();

			/**
			@return Returns sensors Y coordinate
			*/
			static float getSensorY();

			/**
			@return Returns sensors Z coordinate
			*/
			static float getSensorZ();

			/**
			Updates the inputs
			*/
			static void update();

		private:
			static float mSensorX;	///< Sensors X coordinate
			static float mSensorY;	///< Sensors Y coordinate
			static float mSensorZ;	///< Sensors Z coordinate
			static float mAngleX;	///< Sensors X angle
			static float mAngleY;	///< Sensors Y angle
			static float mAngleZ;	///< Sensors Z angle
		};
	}
}
