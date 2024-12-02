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
	public:
		ElementData(ElementType type, sf::Vector2i pos)
		{
			element_type = type;
			element_positon = pos;
		};

		
		ElementType element_type;
		sf::Vector2i element_positon;
	};
}