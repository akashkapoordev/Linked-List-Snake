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

		void createHeadNode();


	private:
		Node* head_node;
		float node_width;
		float node_height;
		Node* createNode();
		sf::Vector2i default_position;
		Player::Direction default_direction; 

	};


}