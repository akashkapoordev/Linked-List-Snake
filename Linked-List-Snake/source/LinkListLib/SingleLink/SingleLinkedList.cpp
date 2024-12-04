#include "LinkListLib/SingleLinked/SingleLinkedList.h"
#include <iostream>

namespace LinkListLib
{
	namespace SingleList
	{
		SingleLinkedList::SingleLinkedList() = default;
	
		SingleLinkedList::~SingleLinkedList() = default;



		Node* SingleLinkedList::createNode()
		{
			return new SingleLinkList::SingleNode;
		}

		void SingleLinkedList::initializeNewNode(Node* new_node, Node* ref_node, Operation operation)
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
				initializeNewNode(new_node, nullptr, Operation::HEAD);
				return;
			}

			initializeNewNode(new_node, head_node, Operation::HEAD);
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
			initializeNewNode(new_node, previous_node, Operation::TAIL);
			link_list_size++;

			shiftNodesAfterInsertion(new_node, current_node, previous_node);

		}

		void SingleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* current_node, Node* previous_node)
		{
			Node* next_node = current_node;
			current_node = new_node;

			while (current_node != nullptr && next_node != nullptr)
			{
				current_node->body_part.setDirection(next_node->body_part.getDirection());
				current_node->body_part.setPosition(next_node->body_part.getgridPosition());

				previous_node = current_node;
				current_node = next_node;
				next_node = next_node->next;
			}

			initializeNewNode(current_node, previous_node, Operation::TAIL);
		}



		void SingleLinkedList::insertNodeAtMiddle()
		{
			if (head_node == nullptr)
			{
				insertNodeAtHead();
				return;
			}
			int middle_index = findMiddleNode();
			insertNodeAtIndex(middle_index);
		}

		void SingleLinkedList::shiftNodesAfterRemoval(Node* current_node)
		{
			Direction previous_direction = current_node->body_part.getDirection();
			sf::Vector2i previous_position = current_node->body_part.getgridPosition();
			current_node = current_node->next;

			while (current_node != nullptr)
			{
				Direction current_direction = current_node->body_part.getDirection();
				sf::Vector2i current_postion = current_node->body_part.getgridPosition();

				current_node->body_part.setDirection(previous_direction);
				current_node->body_part.setPosition(previous_position);
				current_node = current_node->next;

				previous_direction = current_direction;
				previous_position = current_postion;
			}
		}

		void SingleLinkedList::removeAtIndex(int index)
		{
			if (index < 0 || index >= link_list_size)return;

			int current_index = 0;
			Node* current_node = head_node;
			Node* previous_node = nullptr;
			while (current_node != nullptr && current_index < index)
			{
				previous_node = current_node;
				current_node = current_node->next;
				current_index++;
			}

			previous_node->next = current_node->next;

			shiftNodesAfterRemoval(current_node);
			delete(current_node);
			link_list_size--;


		}

		void SingleLinkedList::removeNodeAt(int index)
		{
			if (index < 0 || index >= link_list_size) return;

			if (index == 0)
			{
				removeNodeAtHead();
			}
			else
			{
				removeAtIndex(index);
			}
		}

		void SingleLinkedList::removeNodeAtMiddle()
		{
			if (head_node == nullptr) return;

			int middle_index = findMiddleNode();

			removeAtIndex(middle_index);

		}

		void SingleLinkedList::removeNodeAtTail()
		{
			if (head_node == nullptr)return;

			Node* current_node = head_node;
			if (current_node->next == nullptr)
			{
				removeNodeAtHead();
				return;
			}

			while (current_node->next->next != nullptr)
			{
				current_node = current_node->next;

			}

			delete(current_node->next);
			link_list_size--;
			current_node->next = nullptr;

		}

		void SingleLinkedList::removeHalfNodes()
		{
			int index = (link_list_size / 2) - 1;
			Node* previous_node = findNodeAtIndex(index);
			Node* current_node = previous_node->next;

			while (current_node != nullptr)
			{
				Node* node_to_delete = current_node;
				current_node = current_node->next;

				delete(node_to_delete);
				link_list_size--;
			}

			previous_node->next = nullptr;

		}

	

	

		Direction SingleLinkedList::reverse()
		{
			Node* current_node = head_node;
			Node* next_node = nullptr;
			Node* previous_node = nullptr;

			while (current_node != nullptr)
			{
				next_node = current_node->next;
				current_node->next = previous_node;

				previous_node = current_node;
				current_node = next_node;


			}

			head_node = previous_node;

			reverseNodeDirection();
			return head_node->body_part.getDirection();
		}

	/*	void SingleLinkedList::reverseNodeDirection()
		{
		}*/



		void SingleLinkedList::insertNodeAtTail()
		{
			link_list_size++;
			Node* new_node = createNode();
			Node* current_node = head_node;

			if (current_node == nullptr)
			{
				head_node = new_node;
				initializeNewNode(new_node, nullptr, Operation::TAIL);
				return;
			}

			while (current_node->next != nullptr)
			{
				current_node = current_node->next;
			}

			current_node->next = new_node;
			initializeNewNode(new_node, current_node, Operation::TAIL);


		}




		void SingleLinkedList::removeNodeAtHead()
		{
			Node* current_node = head_node;
			head_node = head_node->next;
			current_node->next = nullptr;
			delete(current_node);
			link_list_size--;

		}

		void SingleLinkedList::removeAllNodes()
		{
			if (head_node == nullptr)return;

			while (head_node != nullptr)
			{
				removeNodeAtHead();
			}

		}


	

	}






}