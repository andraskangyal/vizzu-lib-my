#include "base/style/paramregistry.h"

#include "../../util/test.h"

#include "teststyle.h"

using namespace test;

auto& paramReg = Style::ParamRegistry<Fobar>::instance();
static auto tests =
    collection::add_suite("Style::ParamRegistry")

        .add_case("nested_param_can_be_get_as_string",
            []
            {
	            Fobar fobar{{1, 2}, {5, 6}};

	            double foo_bar = std::stod(paramReg.find(
	                "foo.bar")->toString(fobar));

	            check() << foo_bar == 2;
            })

        .add_case("nested_param_can_be_set_with_string",
            []
            {
	            Fobar fobar{{1, 2}, {5, 6}};

	            paramReg.find(
	                "foo.bar")->fromString(fobar, "9");

	            check() << fobar.foo.bar == 9;
            })

        .add_case("all_nested_param_can_iterated_over",
            []
            {
	            Fobar fobar{{1, 2}, {5, 6}};

	            double sum = 0;

	            for (auto [b, e] = paramReg.prefix_range("");
	                 b != e; ++b)
		            sum += std::stod(b->second.toString(fobar));

	            check() << sum == 1 + 2 + 5 + 6;
            })

        .add_case("all_nested_param_path_can_be_iterated_over",
            []
            {
	            std::string nameList;

	            for (auto [b, e] = paramReg.prefix_range("");
	                 b != e; ++b)
		            nameList += ":" + b->first;

	            check() << nameList
	                == ":baz.baz:baz.fobar:foo.bar:foo.foo";
            })

    ;
