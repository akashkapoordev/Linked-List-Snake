#pragma once
#include <SFML/System/Vector2.hpp>
namespace Element
{
	enum class ElementType
	{
		OBSTACLE,
	};

	struct ElementData
	{
		ElementData(ElementType type, sf::Vector2i pos);

		ElementType element_type;
		sf::Vector2i elemrnt_positon;

	};
}