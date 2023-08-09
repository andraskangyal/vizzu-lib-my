#ifndef AXIS_H
#define AXIS_H

#include <map>

#include "base/anim/interpolated.h"
#include "base/geom/point.h"
#include "base/gfx/color.h"
#include "base/math/fuzzybool.h"
#include "base/math/interpolation.h"
#include "base/math/range.h"
#include "chart/options/channel.h"
#include "data/datacube/datacube.h"
#include "data/multidim/multidimindex.h"
#include "data/table/datatable.h"

namespace Vizzu::Gen
{

template <typename Type> struct AbstractAxises
{
	Refl::EnumArray<ChannelId, Type> axises;

	[[nodiscard]] const Type &at(ChannelId channelType) const
	{
		return axises.at(channelType);
	}

	Type &at(ChannelId channelType) { return axises.at(channelType); }

	[[nodiscard]] const Type &other(ChannelId channelType) const
	{
		return channelType == ChannelId::x ? axises.at(ChannelId::y)
		     : channelType == ChannelId::y
		         ? axises.at(ChannelId::x)
		         : throw std::logic_error("not an axis channel");
	}

	bool operator==(const AbstractAxises<Type> &other) const
	{
		for (auto i = 0; i < std::size(axises); i++) {
			auto id = static_cast<ChannelId>(i);
			if (axises[id] != other.axises[id]) return false;
		}
		return true;
	}
};

struct MeasureAxis
{
	::Anim::Interpolated<bool> enabled{false};
	Math::Range<double> range = Math::Range<double>(0, 1);
	::Anim::String title;
	std::string unit;
	::Anim::Interpolated<double> step{1.0};
	MeasureAxis() = default;
	MeasureAxis(Math::Range<double> interval,
	    std::string title,
	    std::string unit,
	    std::optional<double> step);
	bool operator==(const MeasureAxis &other) const;
	[[nodiscard]] double origo() const;
};

MeasureAxis interpolate(const MeasureAxis &op0,
    const MeasureAxis &op1,
    double factor);

struct MeasureAxises : public AbstractAxises<MeasureAxis>
{
	[[nodiscard]] Geom::Point origo() const;
};

struct DimensionAxis
{
	friend DimensionAxis interpolate(const DimensionAxis &op0,
	    const DimensionAxis &op1,
	    double factor);

public:
	struct Item
	{
		bool start;
		bool end;
		Math::Range<double> range;
		double value;
		Gfx::Color color;
		std::string label;
		double weight;
		bool operator==(const Item &other) const
		{
			return range == other.range;
		}
		[[nodiscard]] bool presentAt(int index) const
		{
			return index == 0 ? start : index == 1 && end;
		}
	};
	using Values = std::map<Data::MultiDim::SliceIndex, Item>;

	Math::FuzzyBool enabled{false};
	::Anim::String title;

	DimensionAxis() = default;
	bool add(const Data::MultiDim::SliceIndex &index,
	    double value,
	    Math::Range<double> &range,
	    double enabled);
	bool operator==(const DimensionAxis &other) const;

	Values::iterator begin() { return values.begin(); };
	Values::iterator end() { return values.end(); }
	[[nodiscard]] Values::const_iterator begin() const
	{
		return values.cbegin();
	};
	[[nodiscard]] Values::const_iterator end() const
	{
		return values.cend();
	}
	void setLabels(const Data::DataCube &data,
	    const Data::DataTable &table);

private:
	Values values;
};

DimensionAxis interpolate(const DimensionAxis &op0,
    const DimensionAxis &op1,
    double factor);

using DimensionAxises = AbstractAxises<DimensionAxis>;

}

#endif
