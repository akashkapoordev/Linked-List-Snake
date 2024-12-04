#include "LinkListLib/DoubleLinked/DoubleLinkList.h"

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
		}

		void DoubleLinkList::removeNodeAt(int index)
		{
		}

		void DoubleLinkList::removeAllNodes()
		{
		}

		void DoubleLinkList::removeHalfNodes()
		{
		}

		Direction DoubleLinkList::reverse()
		{
			return Direction();
		}

		void DoubleLinkList::updateNodePosition()
		{
		}

		void DoubleLinkList::updateNodeDirection(Direction direction_to_set)
		{
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

		Node* DoubleLinkList::createNode()
		{
			return new DoubleNode;
		}


	}
}