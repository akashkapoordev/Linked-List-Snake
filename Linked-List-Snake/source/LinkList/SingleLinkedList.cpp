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
		head_node->body_part.render();
	}

	void SingleLinkedList::createHeadNode()
	{
		head_node = createNode();
		head_node->body_part.initialize(node_width, node_height, default_direction, default_position);
		return;
	}

	Node* SingleLinkedList::createNode()
	{
		return new Node();
	}



}