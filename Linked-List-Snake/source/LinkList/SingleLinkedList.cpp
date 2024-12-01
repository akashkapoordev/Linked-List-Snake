#include "LinkList/SingleLinkedList.h"
#include <iostream>

namespace LinkList
{

	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}
	SingleLinkedList::~SingleLinkedList() = default;

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		link_list_size = 0;
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

	sf::Vector2i SingleLinkedList::getNewNodePosition(Node* ref_node, Operations operation)
	{
		
		switch (operation)
		{
		case LinkList::Operations::HEAD:
			return ref_node->body_part.getNextPosition();
		case LinkList::Operations::MID:
			break;
		case LinkList::Operations::TAIL:
			return ref_node->body_part.getPreviousPosition();
		}

		return default_position;
	}

	void SingleLinkedList::initializeNewNode(Node* new_node, Node* ref_node, Operations operation)
	{
		if (ref_node == nullptr)
		{
			new_node->body_part.initialize(node_width, node_height, default_direction, default_position);
			return;
		}
		new_node->body_part.initialize(node_width, node_height, ref_node->body_part.getDirection(), getNewNodePosition(ref_node, operation));
	}

	void SingleLinkedList::insertNodeAtHead()
	{
		link_list_size++;
		Node* new_node = createNode();

		if (head_node == nullptr)
		{
			head_node = new_node;
			initializeNewNode(new_node, nullptr, Operations::HEAD);
			return;
		}

		initializeNewNode(new_node, head_node, Operations::HEAD);
		new_node->next = head_node;
		head_node = new_node;
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

        while (current_node != nullptr)
        {
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

	void SingleLinkedList::removeNodeAtHead()
	{
		Node* current_node = head_node;
		head_node = head_node->next;
		current_node->next = nullptr;
		//std::cout << "Delete" << std::endl;
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

	std::vector<sf::Vector2i> SingleLinkedList::getNodePositionList()
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

	Node* SingleLinkedList::getHeadNode()
	{
		return head_node;
	}





}