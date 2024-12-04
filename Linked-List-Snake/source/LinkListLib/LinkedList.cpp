#include "LinkListLib/LinkedList.h"

namespace LinkListLib
{
	LinkListLib::LinkList::LinkList()
	{
	}

	LinkList::~LinkList()
	{
	}

	void LinkListLib::LinkList::initialize(float width, float height, sf::Vector2i position, Direction direction)
	{
	}

	void LinkListLib::LinkList::render()
	{
	}

	void LinkListLib::LinkList::updateNodePosition()
	{
	}

	void LinkListLib::LinkList::updateNodeDirection(Direction direction_to_set)
	{
	}

	Node* LinkListLib::LinkList::getNodeHead()
	{
		return nullptr;
	}

	int LinkListLib::LinkList::getLinkListSize()
	{
		return 0;
	}

	bool LinkList::processNodeCollision()
	{
		return false;
	}

	void LinkList::reverseNodeDirection()
	{
	}

	std::vector<sf::Vector2i> LinkList::nodePositionList()
	{
		return std::vector<sf::Vector2i>();
	}

	sf::Vector2i LinkList::getNewNodePosition(Node* refernce_node, Operation operation)
	{
		return sf::Vector2i();
	}

	Direction LinkList::getReverseDirection(Direction reference_direction)
	{
		return Direction();
	}

	Node* LinkList::findNodeAtIndex(int index)
	{
		return nullptr;
	}

	void LinkList::initializeNode(Node* new_node, Node* refernce_node, Operation operation)
	{
	}

	int LinkList::findMiddleNode()
	{
		return 0;
	}

}

