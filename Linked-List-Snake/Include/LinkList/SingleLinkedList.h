#pragma once
#include "LinkList/Node.h"
#include "Player/Direction.h" 
namespace LinkList
{
	enum class Operations
	{
		HEAD,
		MID,
		TAIL
	};
	class SingleLinkedList
	{
	public:
		SingleLinkedList();
		~SingleLinkedList();
		int link_list_size;

		void initialize(float node_width, float node_height, sf::Vector2i pos, Direction dir);
		void update();
		void render();
		void attachNewTail();
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollision();
		void removeNodeAtHead();
		void removeAllNodes();

		std::vector<sf::Vector2i> getNodePositionList();

		Node* getHeadNode();



	private:
		Node* head_node;
		float node_width;
		float node_height;
		Node* createNode();
		sf::Vector2i default_position;
		Player::Direction default_direction; 
		sf::Vector2i getNewNodePosition(Node* ref_node,Operations operation);
		void initializeNewNode(Node* new_node, Node* ref_node,Operations operation);
		void insertNodeAtHead();
		void insertNodeAtIndex(int index);
		void shiftNodesAfterInsertion(Node* new_node, Node* current_node, Node* previous_node);
		int findMiddleIndex();
		void nodeInsetAtMiddle();
		void shiftNodesAfterRemoval(Node* current_node);
		void removeAtIndex(int index);
		void removeAtNode(int index);
		void nodeRemoveAtMiddle();
		void removeAtTail();
		

	};


}