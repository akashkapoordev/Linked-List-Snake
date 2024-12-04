#pragma once
#include "LinkListLib/SingleLinked/SingleNode.h"
#include "Player/Direction.h" 
#include "LinkListLib/LinkedList.h"
namespace LinkListLib
{
	namespace SingleList
	{
		class SingleLinkedList :public LinkList
		{
		public:
			SingleLinkedList();
			~SingleLinkedList();

			void initializeNewNode(Node* new_node, Node* ref_node, Operation operation);

			void insertNodeAtTail() override;
			void insertNodeAtHead() override;
			void insertNodeAtMiddle() override;
			void insertNodeAtIndex(int index) override;

			void shiftNodesAfterInsertion(Node* new_node, Node* current_node, Node* previous_node);


			void removeNodeAtTail() override;
			void removeNodeAtHead() override;
			void removeNodeAtMiddle() override;
			void removeNodeAt(int index) override;
			void removeAllNodes() override;
			void removeHalfNodes() override;
			void removeAtIndex(int index);

			void shiftNodesAfterRemoval(Node* current_node);

			Direction reverse() override;

			//void reverseNodeDirection();


		protected:
		
			Node* createNode() override;
		};
	}




}