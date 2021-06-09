#include "blendeditem.h"

#include "base/math/arrayoperators.h"

#include "areaitem.h"
#include "circleitem.h"
#include "lineitem.h"
#include "rectangleitem.h"

using namespace Vizzu;
using namespace Math;
using namespace Vizzu::Draw;

BlendedDrawItem::BlendedDrawItem(const Diag::Marker &item,
    const Diag::DiagramOptions &options,
    const Styles::Chart &style,
    const Diag::Diagram::Markers &items,
    size_t lineIndex)
{
	std::array<DrawItem, 4> drawItems =
	{
		RectangleItem(item, options, style),
		CircleItem(item, options, style),
		LineItem(item, options, style, items, lineIndex),
		AreaItem(item, options, items, lineIndex)
	};

	enabled = false;
	for (auto &item: drawItems) enabled += item.enabled;

	auto lineEnabled = drawItems[2].enabled;
	drawItems[2].enabled = false;
	blend(drawItems, &DrawItem::morphToCircle);
	drawItems[2].enabled = lineEnabled;

	blend(drawItems, &DrawItem::linear);
	blend(drawItems, &DrawItem::border);
	blend(drawItems, &DrawItem::space);
	blend(drawItems, &DrawItem::points);
	blend(drawItems, &DrawItem::lineWidth);
	blend(drawItems, &DrawItem::connected);
	blend(drawItems, &DrawItem::color);
	blend(drawItems, &DrawItem::center);
}

template <typename T, size_t N>
void BlendedDrawItem::blend(std::array<DrawItem, N> &items, T DrawItem::*member)
{
	this->*member = T();
	double cnt = 0;
	for (auto &item : items)
		if ((double)item.enabled > 0)
	{
		this->*member = this->*member + item.*member * (double)item.enabled;
		cnt += (double)item.enabled;
	}
	if (cnt != 0)
		this->*member = this->*member * (1.0 / cnt);
	else
		this->*member = T();
}

