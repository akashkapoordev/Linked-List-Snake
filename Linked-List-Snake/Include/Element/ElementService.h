#pragma once
#include "Element/Obstacle.h"
#include "Element/ElementData.h"
#include <vector>
namespace Element
{
	class  ElementService
	{
	public:
		ElementService();
		~ElementService();


		void initialize();
		void update();
		void render();

		void spwanObstacle(sf::Vector2i position, float width, float height);
		const void spwanElements(std::vector<ElementData>& element_data_list, float width, float height);
		std::vector<sf::Vector2i> getElementPosition();

	private:
		std::vector<Obstacle*> obstacle_list;
		
	};
}

