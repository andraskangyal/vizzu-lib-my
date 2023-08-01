#ifndef GEOM_TRANSFORMEDRECT
#define GEOM_TRANSFORMEDRECT

#include "rect.h"
#include "affinetransform.h"

namespace Geom
{

class TransformedRect
{
public:
	AffineTransform transform;
	Size size;

	[[nodiscard]] bool contains(const Point &point) const
	{
		auto transformed = transform.inverse()(point);
		return Rect(Point(), size).contains(transformed);
	}

	[[nodiscard]] std::string toJSON() const
	{
		return "{\"transform\":"
		     + std::string(transform)
		     + ",\"size\":"
		     + size.toJSON() + "}";
	}
};

}

#endif
