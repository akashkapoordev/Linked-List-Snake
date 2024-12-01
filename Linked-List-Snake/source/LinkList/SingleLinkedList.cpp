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

    void SingleLinkedList::insertNodeAtIndex(int index)
    {
        if (index < 0 || index >= link_list_size) return;

        if (index == 0)
        {
            insertNodeAtHead();
            return;
        }

        Node* new_node = createNode();
        int current_index = 0;
        Node* current_node = head_node;
        Node* previous_node = nullptr;

        while (current_node != nullptr && current_index < index)
        {
            previous_node = current_node;
            current_node = current_node->next;
            current_index++;
        }

			previous_node->next = new_node;
            new_node->next = current_node;
            initializeNewNode(new_node, previous_node, Operations::MID);
            link_list_size++;

			shiftNodesAfterInsertion(new_node, current_node, previous_node);
        
    }

	void SingleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* current_node, Node* previous_node)
	{
		Node* next_node = current_node;
		current_node = new_node;

		while (current_node !=nullptr && next_node!=nullptr)
		{
			current_node->body_part.setDirection(next_node->body_part.getDirection());
			current_node->body_part.setPosition(next_node->body_part.getgridPosition());

			previous_node = current_node;
			current_node = next_node;
			next_node = next_node->next;
		}

		initializeNewNode(current_node, previous_node, Operations::TAIL);
	}

	int SingleLinkedList::findMiddleIndex()
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

	void SingleLinkedList::nodeInsetAtMiddle()
	{
		if (head_node == nullptr)
		{
			insertNodeAtHead();
			return;
		}
		int middle_index = findMiddleIndex();
		insertNodeAtIndex(middle_index);
	}



	void SingleLinkedList::attachNewTail()
	{
		link_list_size++;
		Node* new_node = createNode();
		Node* current_node = head_node;

		if (current_node == nullptr)
		{
			head_node = new_node;
			initializeNewNode(new_node, nullptr, Operations::TAIL);
			return;
		}

		while (current_node->next != nullptr)
		{
			current_node = current_node->next;
		}

		current_node->next = new_node;
		initializeNewNode(new_node, current_node, Operations::TAIL);
		

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
		link_list_size--;
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