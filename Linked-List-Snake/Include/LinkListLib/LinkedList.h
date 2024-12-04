#pragma once
#include "Node.h"
#include "Player/Direction.h"
namespace LinkListLib
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL
	};
	class LinkList
	{
	public:
		LinkList();
		virtual ~LinkList();

		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void render();

		virtual void insertNodeAtTail() = 0;
		virtual void insertNodeAtHead() = 0;
		virtual void insertNodeAtMiddle() = 0;
		virtual void insertNodeAtIndex(int index) = 0;

		virtual void removeNodeAtTail() = 0;
		virtual void removeNodeAtHead() = 0;
		virtual void removeNodeAtMiddle() = 0;
		virtual void removeNodeAt(int index) = 0;
		virtual void removeAllNodes() = 0;
		virtual void removeHalfNodes() = 0;

		virtual Direction reverse() = 0;
		virtual void updateNodePosition();
		virtual void updateNodeDirection(Direction direction_to_set);


		Node* getNodeHead();
		int getLinkListSize();
		bool processNodeCollision();
		void reverseNodeDirection();
		std::vector<sf::Vector2i>nodePositionList();


	protected:
		Node* head_node;
		float node_width;
		float node_height;
		sf::Vector2i default_position;
		Direction default_direction;
		int link_list_size;

		virtual void createNode() = 0;
		sf::Vector2i getNewNodePosition(Node* refernce_node, Operation operation);
		Direction getReverseDirection(Direction reference_direction);
		Node* findNodeAtIndex(int index);
		void initializeNode(Node* new_node, Node* refernce_node, Operation operation);
		int findMiddleNode();


	};

}