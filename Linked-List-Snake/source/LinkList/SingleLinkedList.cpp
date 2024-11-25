#include "LinkList/SingleLinkedList.h"
#include <iostream>

namespace LinkList
{
	// Add this function to handle the output of Direction enum
	std::ostream& operator<<(std::ostream& os, const Player::Direction& direction)
	{
		switch (direction)
		{
		case Player::Direction::UP:
			os << "UP";
			break;
		case Player::Direction::DOWN:
			os << "DOWN";
			break;
		case Player::Direction::LEFT:
			os << "LEFT";
			break;
		case Player::Direction::RIGHT:
			os << "RIGHT";
			break;
		}
		return os;
	};
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
		//std::cout << ref_direction << std::endl;
       


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

	void SingleLinkedList::updateNodeDirection(Direction direction_to_set)
	{
		Node* current_node = head_node;

		while (current_node!=nullptr)
		{
			//std::cout <<static_cast<int>(direction_to_set) << std::endl;
			Direction previous_direction = current_node->body_part.getDirection();
			current_node->body_part.setDirection(direction_to_set);
			direction_to_set = previous_direction;
			current_node = current_node->next;
		}
	}

	void SingleLinkedList::updateNodePosition()
	{
		Node* current_node = head_node;

		while (current_node!=nullptr)
		{

			current_node->body_part.update();
			current_node = current_node->next;

			
		}
	}

	bool SingleLinkedList::processNodeCollision()
	{
		if (head_node == nullptr)
		{
			return false;
		}
		sf::Vector2i predicted_position = head_node->body_part.getNextPosition();
		Node* current_node = head_node->next;

		if (current_node != nullptr)
		{
			if (current_node->body_part.getNextPosition() == predicted_position)
			{
				return true;
			}
			current_node = current_node->next;
		}
		return false;
	}

	void SingleLinkedList::removeNodeAtHead()
	{
		Node* current_node = head_node;
		head_node = head_node->next;
		current_node->next = nullptr;
		delete(current_node);
	}

	void SingleLinkedList::removeAllNodes()
	{
		if (head_node == nullptr)return;

		while(head_node != nullptr)
		{
			removeNodeAtHead();
		}

	}



}