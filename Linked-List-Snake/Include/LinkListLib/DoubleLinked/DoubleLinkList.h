#pragma once
#include "LinkListLib/LinkedList.h"
#include "LinkListLib/DoubleLinked/DoubleNode.h"
namespace LinkListLib
{
	namespace DoubleLinkList
	{
		class DoubleLinkList:public LinkList
		{
		public:
			DoubleLinkList();
			~DoubleLinkList();

			void insertNodeAtTail() override;
			void insertNodeAtHead() override;
			void insertNodeAtMiddle() override;
			void insertNodeAtIndex(int index) override;

			void removeNodeAtTail() override;
			 void removeNodeAtHead() override;
			 void removeNodeAtMiddle() override;
			 void removeNodeAt(int index) override;
			 void removeAllNodes() override;
			 void removeHalfNodes() override;

			 Direction reverse() override;

			 void shiftNodesAfterInsertion(Node* new_node, Node* current_node, Node* previous_node);
			 void shiftNodesAfterRemoval(Node* current_node);



		protected:
			Node* createNode() override;
		};
	}
}
