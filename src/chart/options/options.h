#ifndef PLOT_OPTIONS_H
#define PLOT_OPTIONS_H

#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>

#include "base/anim/interpolated.h"
#include "base/geom/rect.h"
#include "base/math/fuzzybool.h"
#include "base/math/range.h"
#include "data/datacube/datafilter.h"
#include "data/multidim/multidimindex.h"
#include "data/table/datatable.h"

#include "align.h"
#include "autoparam.h"
#include "channels.h"
#include "coordsystem.h"
#include "orientation.h"
#include "shapetype.h"
#include "sort.h"

namespace Vizzu::Gen
{

class Options
{
public:
	using MarkerId = uint64_t;
	using Heading = ::Anim::Interpolated<std::optional<std::string>>;
	using LegendType = Base::AutoParam<ChannelId>;
	using Legend = ::Anim::Interpolated<LegendType>;
	using OrientationType = Base::AutoParam<Gen::Orientation>;
	using Orientation = ::Anim::Interpolated<OrientationType>;
	using MarkersInfoMap = std::map<uint64_t, MarkerId>;

	Options() = default;

	[[nodiscard]] const Channels &getChannels() const
	{
		return channels;
	}
	Channels &getChannels() { return channels; }

	void reset();

	[[nodiscard]] ChannelId mainAxisType() const
	{
		return isHorizontal() ? ChannelId::x : ChannelId::y;
	}

	[[nodiscard]] bool isHorizontal() const
	{
		auto hasOrientation = orientation.get();
		return (hasOrientation ? *hasOrientation
		                       : getAutoOrientation())
		    == Gen::Orientation::horizontal;
	}

	[[nodiscard]] ChannelId subAxisType() const
	{
		return isHorizontal() ? ChannelId::y : ChannelId::x;
	}

	[[nodiscard]] const Channel &mainAxis() const
	{
		return channels.at(mainAxisType());
	}

	[[nodiscard]] const Channel &subAxis() const
	{
		return channels.at(subAxisType());
	}

	Channel &mainAxis() { return channels.at(mainAxisType()); }

	Channel &subAxis() { return channels.at(subAxisType()); }

	[[nodiscard]] const Channel *subAxisOf(ChannelId id) const;
	[[nodiscard]] ChannelId stackChannelType() const;
	[[nodiscard]] std::optional<ChannelId> secondaryStackType() const;

	Channel &stackChannel()
	{
		return channels.at(stackChannelType());
	}

	Heading title{std::nullopt};
	Heading subtitle{std::nullopt};
	Heading caption{std::nullopt};
	Anim::Interpolated<CoordSystem> coordSystem{
	    CoordSystem::cartesian};
	double angle{};
	Anim::Interpolated<ShapeType> geometry{ShapeType::rectangle};
	Orientation orientation{OrientationType{}};
	Math::FuzzyBool split;
	Base::Align::Type align{Base::Align::Type::none};
	Data::Filter dataFilter;
	Sort sort{Sort::none};
	Math::FuzzyBool reverse{false};
	Legend legend;
	std::optional<uint64_t> tooltip;
	MarkersInfoMap markersInfo;

	bool operator==(const Options &other) const;
	[[nodiscard]] bool sameShadow(const Options &other) const;
	[[nodiscard]] bool looksTheSame(const Options &other) const;
	[[nodiscard]] bool sameAttributes(const Options &other) const;
	[[nodiscard]] bool sameShadowAttribs(const Options &other) const;
	[[nodiscard]] Channels shadowChannels() const;
	void drilldownTo(const Options &other);
	void intersection(const Options &other);
	void simplify();

	[[nodiscard]] ChannelId getHorizontalChannel() const;
	[[nodiscard]] ChannelId getVerticalChannel() const;

	[[nodiscard]] const Channel &getHorizontalAxis() const
	{
		return channels.at(getHorizontalChannel());
	}

	[[nodiscard]] const Channel &getVeritalAxis() const
	{
		return channels.at(getVerticalChannel());
	}

	Channel &getHorizontalAxis()
	{
		return channels.at(getHorizontalChannel());
	}

	Channel &getVeritalAxis()
	{
		return channels.at(getVerticalChannel());
	}

	[[nodiscard]] bool isShapeValid(const ShapeType &) const;
	[[nodiscard]] std::optional<uint64_t> getMarkerInfoId(
	    MarkerId) const;
	static uint64_t generateMarkerInfoId();

	void setAutoParameters();
	void setAutoRange(bool hPositive, bool vPositive);

	[[nodiscard]] bool labelsShownFor(
	    const Data::SeriesIndex &series) const;

private:
	Channels channels;

	[[nodiscard]] Gen::Orientation getAutoOrientation() const;
	[[nodiscard]] std::optional<ChannelId> getAutoLegend() const;
	static void setMeasureRange(Channel &channel, bool positive);
	static void setRange(Channel &channel,
	    ChannelExtrema min,
	    ChannelExtrema max);
};

using PlotOptionsPtr = std::shared_ptr<Options>;

}

#endif
