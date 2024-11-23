#pragma once
#include "LinkList/Node.h"
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

	private:
		Node* head_node;
		float node_width;
		float node_height;
		Node* createNode();
		sf::Vector2i default_position;
		Direction default_direction;

	};


}