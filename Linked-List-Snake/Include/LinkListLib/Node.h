#pragma once
#include "Player/BodyPart.h"

namespace LinkListLib
{
	using namespace Player;
	struct Node
	{
		BodyPart body_part;
		Node* next = nullptr;
	};
}