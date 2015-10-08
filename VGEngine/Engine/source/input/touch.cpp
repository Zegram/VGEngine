#include "engine/input/touch.h"
using namespace vg::input;
using namespace vg;
bool Touch::isTouched = false;
bool Touch::isTouchReleased = false;
Vector2<float> Touch::touchPos = Vector2<float>();


Vector2<float> Touch::getTouchPos()
{
	return touchPos;
}
void Touch::setTouchPos(Vector2<float> value)
{
	touchPos = value;
}
bool Touch::getIsTouched()
{
	return isTouched;
}
bool Touch::getIsTouchReleased()
{
	return isTouchReleased;
}
void Touch::update()
{
	if (isTouchReleased)
		isTouchReleased = false;
}
void Touch::setIsTouched(bool value)
{
	isTouched = value;
}
void Touch::setIsTouchReleased(bool value)
{
	isTouchReleased = value;
}