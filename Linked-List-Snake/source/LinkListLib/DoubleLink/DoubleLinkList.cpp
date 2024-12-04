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
		}

		void DoubleLinkList::removeNodeAtTail()
		{
		}

		void DoubleLinkList::removeNodeAtHead()
		{
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

		Node* DoubleLinkList::createNode()
		{
			return new DoubleNode;
		}


	}
}