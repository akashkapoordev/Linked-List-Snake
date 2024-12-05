#include "LinkListLib/DoubleLinked/DoubleLinkList.h"
#include "Player/Direction.h"

namespace LinkListLib
{
	namespace DoubleLinkList
	{

		DoubleLinkList::DoubleLinkList() = default;
		DoubleLinkList::~DoubleLinkList() = default;

		void DoubleLinkList::insertNodeAtTail()
		{
			link_list_size++;
			Node* new_node = createNode();
			Node* current_node = head_node;

			if (current_node == nullptr)
			{
				static_cast<DoubleNode*>(new_node)->previous = nullptr;
				initializeNode(new_node, nullptr, Operation::TAIL);
				return;

			}

			while (current_node->next != nullptr)
			{
				current_node = current_node->next;
			}

			current_node->next = new_node;
			static_cast<DoubleNode*>(new_node)->previous = current_node;
			initializeNode(new_node, current_node, Operation::TAIL);
			


		}

		void DoubleLinkList::insertNodeAtHead()
		{
			link_list_size++;
			Node* current_node = createNode();

			while (head_node == nullptr)
			{
				head_node = current_node;
				static_cast<DoubleNode*>(current_node)->previous = nullptr;
				initializeNode(current_node, nullptr, Operation::HEAD);
				return;
			}

			initializeNode(current_node, head_node, Operation::HEAD);
			current_node->next = head_node;
			static_cast<DoubleNode*>(head_node)->previous = current_node;
			head_node = current_node;
		}

		void DoubleLinkList::insertNodeAtMiddle()
		{
			if (head_node == nullptr)
			{
				insertNodeAtHead();
				return;
			}
			int current_index = findMiddleNode();
			insertNodeAtIndex(current_index);
		}

		void DoubleLinkList::insertNodeAtIndex(int index)
		{
			if (index <0 || index>link_list_size)return ;


			if (index ==0)
			{
				insertNodeAtHead();
				return;
			}

			Node* new_node = createNode();
			Node* current_node = head_node;
			int current_index = 0;
			Node* previous_node = nullptr;

			while (current_node !=nullptr && current_index<index)
			{
				previous_node = current_node;
				current_node = current_node->next;
				current_index++;
			}

			previous_node->next = new_node;
			static_cast<DoubleNode*>(new_node)->previous = previous_node;
			new_node->next = current_node;
			static_cast<DoubleNode*>(current_node)->previous = new_node;
			initializeNode(new_node, current_node, Operation::TAIL);
			link_list_size++;

			shiftNodesAfterInsertion(new_node, current_node, previous_node);

			
		}

		void DoubleLinkList::removeNodeAtTail()
		{
			if (head_node == nullptr)return;
			link_list_size--;
			Node* current_node = head_node;

			if (current_node->next == nullptr)
			{
				removeNodeAtHead();
				return;
			}
		

			while (current_node->next != nullptr)
			{
				current_node = current_node->next;
			}

			Node* previous = static_cast<DoubleNode*>(current_node)->previous;
			previous->next = nullptr;
			delete(current_node);
		}

		void DoubleLinkList::removeNodeAtHead()
		{
			link_list_size--;
			Node* current_node = head_node;
			head_node = head_node->next;

			if (head_node != nullptr)
			{
				static_cast<DoubleNode*>(head_node)->previous = nullptr;
	
			}

			current_node->next = nullptr;
			delete(current_node);
		}

		void DoubleLinkList::removeNodeAtMiddle()
		{
			if (head_node == nullptr)return;

			int current_index = findMiddleNode();

			removeNodeAt(current_index);
		}

		void DoubleLinkList::removeNodeAt(int index)
		{
			if (index<0 || index>link_list_size)return;

			if (index == 0)
			{
				removeNodeAtHead();
				return;
			}
			link_list_size--;
			int current_index = 0;
			Node* previous_node = nullptr;
			Node* current_node = head_node;

			while (current_node != nullptr && current_index < index)
			{
				previous_node = current_node;
				current_node = current_node->next;
				current_index++;
			}

			if (previous_node != nullptr)
			{
				previous_node->next = current_node->next;

			}

			if (current_node->next != nullptr)
			{
				Node* next_node = current_node->next;
				static_cast<DoubleNode*>(next_node->next)->previous = previous_node;

			}
			shiftNodesAfterRemoval(current_node);
			delete(current_node);
			

		}

		void DoubleLinkList::removeAllNodes()
		{
			if (head_node == nullptr)return;

			while (head_node != nullptr)
			{
				removeNodeAtHead();
			}
		}

		void DoubleLinkList::removeHalfNodes()
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

		Direction DoubleLinkList::reverse()
		{
			Node* current_node = head_node;
			Node* next_node = nullptr;
			Node* previous_node = nullptr;


			while (current_node != nullptr)
			{
				next_node = current_node->next;
				current_node->next = previous_node;
				static_cast<DoubleNode*>(current_node)->previous = next_node;

				previous_node = current_node;
				current_node = next_node->next;


			}

			head_node = previous_node;
			reverseNodeDirection();
			return head_node->body_part.getDirection();

		}

		void DoubleLinkList::shiftNodesAfterInsertion(Node* new_node, Node* current_node, Node* previous_node)
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
			initializeNode(current_node, previous_node, Operation::TAIL);

		}

		void DoubleLinkList::shiftNodesAfterRemoval(Node* current_node)
		{
			Direction previous_direction = current_node->body_part.getDirection();
			sf::Vector2i previous_position = current_node->body_part.getgridPosition();

			current_node = current_node->next;

			while (current_node != nullptr)
			{
				Direction current_direction = current_node->body_part.getDirection(); 
				sf::Vector2i current_position = current_node->body_part.getgridPosition();

				current_node->body_part.setDirection(previous_direction);
				current_node->body_part.setPosition(previous_position);

				current_node = current_node->next;

				previous_direction = current_direction;
				previous_position = current_position;
			}
		}

		Node* DoubleLinkList::createNode()
		{
			return new DoubleNode;
		}


	}
}