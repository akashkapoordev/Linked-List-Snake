#pragma once
#include "LinkList/Node.h"
#include "Player/Direction.h" 
namespace LinkList
{
	class SingleLinkedList
	{
	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float node_width, float node_height, sf::Vector2i pos, Direction dir);
		void update();
		void render();
		void attachNewTail();
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollision();
		void removeNodeAtHead();
		void removeAllNodes();



	private:
		Node* head_node;
		float node_width;
		float node_height;
		Node* createNode();
		sf::Vector2i default_position;
		Player::Direction default_direction; 
		sf::Vector2i getNewNodePosition(Node* ref_node);

	};


}