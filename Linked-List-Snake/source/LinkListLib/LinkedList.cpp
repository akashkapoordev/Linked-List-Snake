#include "LinkListLib/LinkedList.h"

namespace LinkListLib
{
	LinkListLib::LinkList::LinkList()
	{
		head_node = nullptr;
	}

	LinkList::~LinkList() = default;

	void LinkListLib::LinkList::initialize(float width, float height, sf::Vector2i position, Direction direction)
	{

		link_list_size = 0;
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
	}

	void LinkListLib::LinkList::render()
	{
		Node* current_node = head_node;
		while (current_node != nullptr)
		{
			current_node->body_part.render();
			current_node = current_node->next;
		}
	}

	void LinkListLib::LinkList::updateNodePosition()
	{
		Node* current_node = head_node;

		while (current_node != nullptr)
		{

			current_node->body_part.update();
			current_node = current_node->next;


		}
	}

	void LinkListLib::LinkList::updateNodeDirection(Direction direction_to_set)
	{
		Node* current_node = head_node;

		while (current_node != nullptr)
		{
			Direction previous_direction = current_node->body_part.getDirection();
			current_node->body_part.setDirection(direction_to_set);
			direction_to_set = previous_direction;
			current_node = current_node->next;
		}
	}

	Node* LinkListLib::LinkList::getNodeHead()
	{
		return head_node;
	}

	int LinkListLib::LinkList::getLinkListSize()
	{
		return link_list_size;
	}

	bool LinkList::processNodeCollision()
	{
		if (head_node == nullptr)
		{
			return false;
		}
		sf::Vector2i predicted_position = head_node->body_part.getNextPosition();

		Node* current_node = head_node->next;

		while (current_node != nullptr)
		{
			if (current_node->body_part.getNextPosition() == predicted_position)
			{
				return true;
			}
			current_node = current_node->next;
		}
		return false;
	}

	void LinkList::reverseNodeDirection()
	{
		Node* current_node = head_node;

		while (current_node != nullptr)
		{
			Direction previous_direction = current_node->body_part.getPreviousDirection();
			Direction reverse_direction = getReverseDirection(previous_direction);
			current_node->body_part.setDirection(reverse_direction);
			current_node = current_node->next;
		}
	}

	std::vector<sf::Vector2i> LinkList::nodePositionList()
	{
		std::vector<sf::Vector2i> node_position_list;

		Node* current_node = head_node;


		while (current_node != nullptr)
		{
			node_position_list.push_back(current_node->body_part.getgridPosition());
			current_node = current_node->next;
		}

		return node_position_list;
	}

	sf::Vector2i LinkList::getNewNodePosition(Node* refernce_node, Operation operation)
	{
		switch (operation)
		{
		case LinkListLib::Operation::HEAD:
			return refernce_node->body_part.getNextPosition();
		case LinkListLib::Operation::MID:
			break;
		case LinkListLib::Operation::TAIL:
			return refernce_node->body_part.getPreviousPosition();
		}

		return default_position;
	}

	Direction LinkList::getReverseDirection(Direction reference_direction)
	{
		switch (reference_direction)
		{
		case Player::Direction::RIGHT:
			return Direction::LEFT;
		case Player::Direction::UP:
			return Direction::DOWN;
		case Player::Direction::DOWN:
			return Direction::UP;
		case Player::Direction::LEFT:
			return Direction::RIGHT;
		}
	}

	Node* LinkList::findNodeAtIndex(int index)
	{
		int current_index = 0;
		Node* current_node = head_node;
		Node* previous_node = nullptr;
		while (current_node != nullptr && current_index <= index)
		{
			previous_node = current_node;
			current_node = current_node->next;
			current_index++;
		}

		return previous_node;
	}

	void LinkList::initializeNode(Node* new_node, Node* refernce_node, Operation operation)
	{
		if (refernce_node == nullptr)
		{
			new_node->body_part.initialize(node_width, node_height, default_direction, default_position);
			return;
		}

		sf::Vector2i position = getNewNodePosition(refernce_node, operation);

		new_node->body_part.initialize(node_width, node_height, refernce_node->body_part.getDirection(),position);


	}

	int LinkList::findMiddleNode()
	{
		Node* fast = head_node;
		Node* slow = head_node;

		int middle_index = 0;

		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			middle_index++;
		}

		return middle_index;
	}

}

