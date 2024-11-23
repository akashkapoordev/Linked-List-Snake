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
		Node* current_node = head_node;
		while (current_node !=nullptr)
		{
			current_node->body_part.render();
			current_node = current_node->next;

		}
	}


	Node* SingleLinkedList::createNode()
	{
		return new Node();
	}

	sf::Vector2i SingleLinkedList::getNewNodePosition(Node* ref_node)
	{
		Direction ref_direction = ref_node->body_part.getDirection();
		sf::Vector2i ref_position = ref_node->body_part.getgridPosition();

		switch (ref_direction)
		{
		case Player::Direction::UP:
			return sf::Vector2i(ref_position.x, ref_position.y - 1);
			break;
		case Player::Direction::DOWN:
			return sf::Vector2i(ref_position.x, ref_position.y + 1);
			break;
		case Player::Direction::LEFT:
			return sf::Vector2i(ref_position.x - 1, ref_position.y);
			break;
		case Player::Direction::RIGHT:
			return sf::Vector2i(ref_position.x + 1, ref_position.y);
			break;
		}

		return default_position;
	}

	void SingleLinkedList::attachNewTail()
	{
		Node* new_node = createNode();
		Node* current_node = head_node;

		if (current_node == nullptr)
		{
			head_node = new_node;
			new_node->body_part.initialize(node_width, node_height, default_direction, default_position);
			return;
		}

		while (current_node->next != nullptr)
		{
			current_node = current_node->next;
		}

		current_node->next = new_node;
		new_node->body_part.initialize(node_width, node_height,current_node->body_part.getDirection(),getNewNodePosition(current_node));
		

	}



}