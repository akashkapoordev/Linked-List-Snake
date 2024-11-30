#include "Element/ElementService.h"

namespace Element
{
	using namespace LinkList;
	ElementService::ElementService() = default;
	ElementService::~ElementService() = default;

	void ElementService::initialize()
	{
	}
	void ElementService::update()
	{
		for (int i = 0; i < obstacle_list.size(); i++)
		{
			obstacle_list[i]->update();
		}
	}
	void ElementService::render()
	{
		for (int i = 0; i < obstacle_list.size(); i++)
		{
			obstacle_list[i]->render();
		}
	}
	void ElementService::spwanObstacle(sf::Vector2i position, float width, float height)
	{
		Obstacle* obstacle = new Obstacle();
		obstacle->intialize(position, width, height);
		obstacle_list.push_back(obstacle);
	}
	const void ElementService::spwanElements(std::vector<ElementData>& element_data_list, float width, float height)
	{
		for (int i = 0; i < element_data_list.size(); i++)
		{
			switch (element_data_list[i].element_type)
			{
				case ElementType::OBSTACLE:
					spwanObstacle(element_data_list[i].element_positon, width, height);
					break;
			}
		}
	}
	std::vector<sf::Vector2i> ElementService::getElementPosition()
	{
		std::vector<sf::Vector2i> element_position;
		for (int i = 0; i < obstacle_list.size(); i++)
		{
			element_position.push_back(obstacle_list[i]->getObstaclePositionList());
		}

		return element_position;
	}
	bool ElementService::processElementCollision(LinkList::Node* head_node)
	{
		for (int i = 0; i < obstacle_list.size(); i++)
		{
			if (obstacle_list[i]->getObstaclePositionList() == head_node->body_part.getNextPosition() || obstacle_list[i]->getObstaclePositionList() == head_node->body_part.getgridPosition())
			{
				return true;
			}
		}
		return false;
		
		
	}
}