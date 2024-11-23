#include "LinkList/SingleLinkedList.h"

namespace LinkList
{
	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}
	SingleLinkedList::~SingleLinkedList() = default;

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		node_width = width;
		node_height = height;
		default_position = pos;
		default_direction = dir;
	
	}

	void SingleLinkedList::update()
	{
	}

	void SingleLinkedList::render()
	{
	}

	Node* SingleLinkedList::createNode()
	{
		return new Node();
	}

}